#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
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
    ll n,w;
    cin>>n>>w;
    vector<pll> v(n);
    for(int i=1;i<=n;++i)
    {
        cin>>v[i-1].F;
        v[i-1].S = i;
    }
    sort(all(v));
    vector<ll> ans;
    if(v[0].F>w)
    {
        cout<<"-1\n";return 0;
    }
    int idx = n;
    for(int i=0;i<n;++i)
    {
        if(v[i].F>(w+1)/2)
        {
            idx = i;
            break;
        }
    }
    ll cur = 0;
    if(idx<n  && v[idx].F>(w+1)/2 && v[idx].F <=w)
    {
        cout<<"1\n"<<v[idx].S<<"\n";
        return 0;
    }
    for(int i=idx-1;i>=0;--i)
    {
        cur += v[i].F;
        ans.pb(v[i].S);
        if(cur>=(w+1)/2)
            break;
    }
    if(cur<(w+1)/2)
        cout<<"-1\n";
    else
    {
        cout<<sz(ans)<<"\n";
        for(auto j:ans)
            cout<<j<<" ";
        cout<<"\n";
    }
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}