#include"bits/stdc++.h"
using namespace std;
int nn;
map<long long,int>mp;
int main()
{
    int t;
    cin>>t;
    nn=1;
    //cout<<45000*45000<<endl;
    mp[0]=0;
    for(int i=3;i<50000;i+=2)
    {
        long long ans=i;
        ans*=ans;
        mp[ans/2+1]=(nn++);
    }
    while(t--)
    {
        long long x;
        cin>>x;
        cout<<mp.upper_bound(x)->second-1<<endl;
    }
    return 0;
}