#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
ll pows(ll a,ll b)
{
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)
    {
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
int a[100005];
int main()
{
    int n,p;
    cin>>n>>p;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    ll ans=0;
    for(int i=0;i<n;i++)ans+=a[i];
    map<ll,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(ans-a[i])==mp.end())mp[ans-a[i]]=1;
        else mp[ans-a[i]]++;
    }
    while(1)
    {
        if((mp.begin())->second%p)break;
        int num=(mp.begin())->second/p;
        ll t=(mp.begin())->first+1;
        mp.erase(mp.begin());
        if(mp.find(t)==mp.end())mp[t]=num;
        else mp[t]+=num;
    }
    cout<<pows(p,min((mp.begin())->first,ans))<<endl;
    return 0;
}