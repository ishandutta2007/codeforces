#include<iostream>
#include<bits/stdc++.h>
#define int long long int 
using namespace std;

class comp{
    public:
    bool operator()(pair<int,int>a , pair<int,int>b)
    {
        if(a.first!=b.first)
        return a.first>b.first ;

        return a.second<b.second;
    }
};

class compset{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
    
    set<pair<int,int>,compset>s;
    set<pair<int,int>, comp>pq;
    int t;cin>>t;
    int customer = 1;
    vector<int>ans;
    while(t--)
    {
        int choice;cin>>choice;
        if(choice==1)
        {
            int tip;cin>>tip;
            pq.insert({tip,customer});
            s.insert({tip,customer});
            customer++;
        }
        else if(choice==2)
        {
            ans.push_back( (*s.begin()).second );
            pq.erase(*s.begin());
            s.erase(*s.begin());
        }
        else
        {
            ans.push_back( (*pq.begin()).second );
            s.erase(*pq.begin());
            pq.erase(*pq.begin());
        }
        
    }

    for(auto i:ans)
    cout<<i<<" ";

    return 0;
}