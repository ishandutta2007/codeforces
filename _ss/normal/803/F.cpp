#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e5+1,mod=1e9+7;
ll f[maxn],d[maxn],pow2[maxn];

int main()
{
    ll n,x;
    cin>>n;
    pow2[0]=1;
    for (int i=1;i<=n;i++) scanf("%I64d",&x),d[x]++,pow2[i]=(pow2[i-1]<<1)%mod;
    for (int i=maxn-1;i;i--)
    {
        ll t=0;
        for (int j=i;j<=maxn;j+=i) t+=d[j];
        f[i]=pow2[t]-1;
        for (int j=i*2;j<=maxn;j+=i) f[i]=(f[i]+mod-f[j])%mod;
    }
    cout<<f[1];
    return 0;
}