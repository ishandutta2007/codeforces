#include<bits/stdc++.h>
#include <iostream>
#define int long long int
using namespace std;

int32_t main()
{
    int t=1;
    while(t--)
    {
       int n;cin>>n;
       map<int,int>mp;
       
       for(int i=0;i<n;i++)
       {
           int b,d;cin>>b>>d;
           mp[b]++;
           mp[d]--;
       }
       
       int maxyear,max=-1,prefix=0;
       
       for(auto i=mp.begin();i!=mp.end();i++)
       {
           prefix+=(i->second);
           if(prefix>max)
           {
               max=prefix;
               maxyear=(i->first);
           }
       }
       
       cout<<maxyear<<" "<<max;
       
    }
    

    return 0;
}