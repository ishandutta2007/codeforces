#include"bits/stdc++.h"
using namespace std;
#define ll long long
map<ll,ll>mp;
int main()
{
    int n,p,k;
    cin>>n>>p>>k;
    for(int i=0;i<n;i++)
    {
        ll c;
        cin>>c;
        ll tt=c*c%p*c%p*c%p-k*c%p;
        tt%=p;
        if(tt<0)tt+=p;
        if(mp.find(tt)==mp.end())mp[tt]=1;
        else mp[tt]++;
    }
    ll ans=0;
    for(auto pr:mp)
    {
        ans+=(pr.second)*(ll)(pr.second-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}