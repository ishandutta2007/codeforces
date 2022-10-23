#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
const ll maxn=1e6+1,mod=1e9+7;
ll sl[maxn],f[maxn],pow2[maxn];

int main()
{
    pow2[0]=1;
    for (int i=1;i<maxn;i++) pow2[i]=(pow2[i-1]<<1)%mod;
    ll n,x;
    cin>>n;
    for (int i=1;i<=n;i++) scanf("%I64d",&x),sl[x]++;
    for (int i=maxn-1;i;i--)
    {
        for (int j=i;j<maxn;j+=i) f[i]+=sl[j];
        if (!f[i]) continue;
        f[i]=(f[i]*pow2[f[i]-1])%mod;
        for (int j=2*i;j<maxn;j+=i) f[i]=(f[i]-f[j]+mod)%mod;
    }
    ll ans=0;
    for (int i=2;i<maxn;i++) ans=(ans+f[i]*i)%mod;
    cout<<ans;
    return 0;
}