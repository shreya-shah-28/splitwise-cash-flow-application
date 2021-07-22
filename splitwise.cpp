#include <iostream>
#include<map>
#include<unordered_map>
#include<cmath>
#include<utility>

using namespace std;
void welcome();
void solve();
int main()
{
    welcome();
    solve();

    return 0;
}
void welcome(){
cout<<"**************************************************************************\n";
cout<<"**************************************************************************\n";
cout<<"**______________________________________________________________________**\n";
cout<<"**               SPLITWISE CASH FLOW APPLICATION                        **\n";
cout<<"**______________________________________________________________________**\n";
cout<<"**   An Application To Solve The Problem Of Cash Flow Between Friends   **\n";
cout<<"**______________________________________________________________________**\n";
cout<<"**************************************************************************\n";
cout<<"**************************************************************************\n";
cout<<"\n\n\n";


}
void solve(){
    int nooftransactions,friends;
    cout<<"Enter The Total No Of Transactions To Be Made: ";

    cin>>nooftransactions;
    cout<<endl;
    cout<<"Enter total no of friend invloved in the transaction: ";

    cin>>friends;
    cout<<endl;
    int amount;
    string x,y;
    multimap<int,string>m;
    unordered_map<string,int>net;
    cout<<"one by one enter the details in the format as given below."<<endl;
    cout<<"once done press enter.\n";
    cout<<"WHO HAS TO PAY _ TO WHOM _ HOW MUCH"<<endl;
    while(nooftransactions--){
        cin>>x>>y>>amount;
        if(net.count(x)==0){
            net[x]=0;
        }
        if(net.count(y)==0){
            net[y]=0;
        }
        net[x]-=amount;
        net[y]+=amount;

    }
    for(auto p:net){
        string name=p.first;
        int amount =p.second;
        if(amount!=0){
            m.insert((make_pair(amount,name)));
        }
    }
    cout<<"\n\nafter solving the splitwise cash flow:\n"<<endl;
    while(!m.empty()){
        auto low=m.begin();
        auto high=prev(m.end());
        int debit=low->first;
        int credit=high->first;
        string dname=low->second;
        string cname=high->second;

        m.erase(low);
        m.erase(high);
        int settlementamount=min(-debit,credit);
        debit+=settlementamount;
        credit-=settlementamount;
        cout<<dname<<" has to pay rupees "<<settlementamount<<" to "<< cname<<endl;
        if(debit!=0){
            m.insert(make_pair(debit,dname));
        }
        if(credit!=0){
            m.insert(make_pair(credit,cname));
        }


    }


}
