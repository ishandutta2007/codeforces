#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
int main()
{
    int n;
    cin>>n;
    ll s=0;
    map<ll,ll>mp;
    for(int i=0;i<n;i++)
    {
        ll a;
        scanf("%lld",&a);
        if(i==0)
        {
            s=a%mod;
            mp[a]=1;
            continue;
        }
        ll ans=(a-1)*s%mod;
        if(i&1)mp[a]=(mp[a]-s)%mod;
        else mp[a]=(mp[a]+s)%mod;
        while(1)
        {
            auto it=mp.end();
            it--;
            if(it->first<=a)break;
            ll d=it->first-a,k=it->second;
            mp.erase(it);
            mp[a]=(mp[a]+k)%mod;
            if(i&1)ans=(ans+d*k)%mod;
            else ans=(ans-d*k)%mod;
        }
        s=ans;
    }
    if(s<0)s+=mod;
    cout<<s<<endl;
    return 0;
}