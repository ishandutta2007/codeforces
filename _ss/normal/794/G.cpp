#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=3e5,mod=1e9+7;
string s,t;
ll n,coprime[maxn+1];

ll modpow(ll x,ll h)
{
    if (h==0) return 1;
    if (h==1) return x;
    ll t=modpow(x,h/2);
    t=(t*t)%mod;
    if (h%2==1) t=(t*x)%mod;
    return t;
}

ll gcd(ll x,ll y)
{
    ll r;
    while (y!=0)
    {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}

ll nghichdao(ll x)
{
    return modpow(x,mod-2);
}

ll solve(ll x,ll y)
{
    if (x==0 && y==0)
    {
        for (ll i=n;i>n/2;i--) coprime[i]=1;
        for (ll i=n/2;i>=1;i--)
        {
            coprime[i]=((n/i)*(n/i))%mod;
            for (ll j=i*2;j<=n;j+=i) coprime[i]-=coprime[j];
            if (coprime[i]<0) coprime[i]+=mod;
        }
        ll cr=2,kq=0;
        for (int i=1;i<=n;i++)
        {
            kq=(kq+(cr*coprime[i])%mod)%mod;
            cr=(cr*2)%mod;
        }
        return kq;
    }
    else if (x>=0 && y>=0) return 0;
    else if (x<=0 && y<=0) return 0;
    else
    {
        x=abs(x);
        y=abs(y);
        ll g=gcd(x,y);
        x=x/g;
        y=y/g;
        ll k=n/max(x,y);
        ll kq=modpow(2,k+1)-2;
        if (kq<0) kq+=mod;
        return kq;
    }
}

int main()
{
    cin>>s>>t>>n;
    ll same=1;
    if (s.length()!=t.length()) same=0;
    else for (ll i=0;i<s.length();i++)
    if (s[i]=='?' && t[i]=='?') same=(same*2)%mod;
    else if (s[i]=='?' || t[i]=='?')
    {

    }
    else if (s[i]==t[i])
    {

    }
    else same=0;
    ll sa,sb,sc,ta,tb,tc;
    sa=sb=sc=ta=tb=tc=0;
    for (ll i=0;i<s.length();i++)
        if (s[i]=='A') sa++;
        else if (s[i]=='B') sb++;
        else sc++;

    for (ll i=0;i<t.length();i++)
        if (t[i]=='A') ta++;
        else if (t[i]=='B') tb++;
        else tc++;
    ll p=sa-ta,q=sb-tb+sc-tc,kq=0,c=1,cntt=0;
    for (ll i=p-tc;i<=p+sc;i++)
    {
        if (i==0)
        {
            ll cc=c-same;
            if (cc<0) cc+=mod;
            kq=(kq+(cc*solve(i,q-i+p))%mod)%mod;
            ll k=modpow(2,n+1)-2;
            k=(k*k)%mod;
            kq=(kq+(same*k)%mod)%mod;
        }
        else kq=(kq+(c*solve(i,q-i+p))%mod)%mod;
        c=(c*nghichdao(cntt+1))%mod;
        c=(c*(sc+tc-cntt))%mod;
        cntt++;
    }
    cout<<kq;
}