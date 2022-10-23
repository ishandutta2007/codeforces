#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             4000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    ll x,y;
    string s;
    cin>>s;
    cin>>x>>y;
    ll ans = 0;
    ll n = sz(s);
    ll one = 0,z = 0;
    for(int i=0;i<n;++i)
        one += s[i]=='1',z += s[i]=='0';
    ll pone = 0;
    ll zero = 0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
            ans += pone*y;
        else if(s[i]=='1')
            ans += zero*x;
        zero += s[i]=='0';
        pone += s[i]=='1';
    }
    // cout<<ans<<"\n";
    vector<ll> c1,c2;
    pone = 0;
    zero = 0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='?')
        {
            c1.pb(pone*y + (one-pone)*x);
            c2.pb(zero*x + (z-zero)*y);
        }
        zero += s[i]=='0';
        pone += s[i]=='1';
    }
    // cout<<ans<<"\n";
    ll mx = INF;
    vector<ll> sf1(sz(c1)+10),sf2(sz(c2)+10);
    sf1[0] = 0;
    for(int i=1;i<=sz(c1);++i)
        sf1[i] = sf1[i-1] + c1[i-1];
    sf2[sz(c2)+1] = 0;
    for(int i=sz(c2);i>=1;--i)
        sf2[i] = sf2[i+1] + c2[i-1];
    amin(mx,sf2[1]);
    for(int i=1;i<=sz(c1);++i)
    {
        amin(mx,sf1[i]+sf2[i+1] + 1LL*i*(sz(c1)-i)*x);
    }
    sf1[0] = 0;
    for(int i=1;i<=sz(c1);++i)
        sf1[i] = sf1[i-1] + c2[i-1];
    sf2[sz(c2)+1] = 0;
    for(int i=sz(c2);i>=1;--i)
        sf2[i] = sf2[i+1] + c1[i-1];
    amin(mx,sf2[1]);
    for(int i=1;i<=sz(c1);++i)
    {
        amin(mx,sf1[i]+sf2[i+1] + 1LL*i*(sz(c1)-i)*y);
    }
    cout<<ans+mx<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}