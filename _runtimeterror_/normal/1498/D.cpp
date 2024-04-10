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
    int n,m;
    cin>>n>>m;
    vector<ll> ans(m+1,INF);
    ans[0] = 0;
    for(int i=1;i<=n;++i)
    {
        ll t,x,y;
        cin>>t>>x>>y;
        if(t == 1)
        {
            ll u = ceil(x/1e5);
            for(int j=m;j>=0;--j)
            {
                if(ans[j] == INF)
                    continue;
                ll cur = j;
                for(int k=1;k<=y;++k)
                {
                    ll v = cur + u;
                    if(v > m || ans[v] != INF)
                        break;
                    ans[v] = i;
                    cur = v;
                }
            }
        }
        else
        {
            for(int j=m;j>=1;--j)
            {
                if(ans[j] == INF)
                    continue;
                ll cur = j;
                for(int k=1;k<=y;++k)
                {
                    ll v = ceil(cur*x/1e5);
                    if(v > m || ans[v] != INF)
                        break;
                    ans[v] = i;
                    cur = v;
                }
            }
        }
    }
    for(int i=1;i<=m;++i)
        cout<<(ans[i] == INF?-1:ans[i])<<" ";
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