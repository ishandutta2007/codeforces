#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll r,h;
        scanf("%lld%lld",&r,&h);
        a[i]=r*r*h;
    }
    map<ll,ll>mp;
    for(int i=0;i<n;i++)
    {
        auto it=mp.lower_bound(a[i]);
        if(it==mp.begin())
        {
            if(mp.find(a[i])==mp.end())mp[a[i]]=a[i];
        }
        else
        {
            it--;
            if(mp.find(a[i])==mp.end())mp[a[i]]=a[i]+it->second;
            else mp[a[i]]=max(mp[a[i]],a[i]+it->second);
        }
        ll ans=mp[a[i]];
        while(1)
        {
            it=mp.upper_bound(a[i]);
            if(it==mp.end())break;
            if(it->second>ans)break;
            mp.erase(it);
        }
    }
    auto it=mp.end();
    it--;
    printf("%.9f\n",atan(1)*4*it->second);
    return 0;
}