#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(vr) vr.begin(),vr.end()
const int N=1e5+10;
const ll mod=1e9+9;

ll modpow(ll x,ll h)
{
    ll res=1;
    for (;h;h>>=1)
    {
        if (h&1) res=res*x%mod;
        x=x*x%mod;
    }
    return res;
}

ll inverse(ll x)
{
    return modpow(x,mod-2);
}

int main()
{
    //freopen("ss.inp","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k,a,b;
    cin>>n>>a>>b>>k;
    ll res=0,x=modpow(b*inverse(a)%mod,k);
    if (x!=1) x=(modpow(x,(n+1)/k)-1+mod)%mod*inverse((x-1+mod)%mod)%mod;
    else x=(n+1)/k*x%mod;
    char ch;
    for (int i=0;i<k;i++)
    {
        cin>>ch;
        ll tmp=modpow(a,n-i)*modpow(b,i)%mod;
        if (ch=='+') res=(res+tmp*x)%mod;
        else res=(res-tmp*x+mod*mod)%mod;
    }
    cout<<res;
    return 0;
}