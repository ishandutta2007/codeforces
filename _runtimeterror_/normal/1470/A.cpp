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
    ll ans = 0;
    vector<int> a(n);
    vector<int> cnt(m+1,0);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }
    vector<ll> c(m+1);
    for(int i=1;i<=m;++i)
        cin>>c[i];

    multiset<ll> s;
    multiset<ll> pr;
    for(int i=1;i<=m;++i)
    {
        pr.insert(c[i]);
        for(int j=1;j<=cnt[i];++j)
        {
            if(!pr.empty() && !s.empty())
            {
                int u = *pr.begin(),v = *s.begin();
                if(u<=v)
                {
                    ans += *pr.begin();
                    s.insert(c[i]);
                    pr.erase(pr.begin());
                }
                else
                {
                    ans += *s.begin();
                    s.erase(s.begin());
                    s.insert(c[i]);
                }
            }
            else if(!pr.empty())
            {
                ans += *pr.begin();
                s.insert(c[i]);
                pr.erase(pr.begin());
            }
            else
            {
                ans += *s.begin();
                s.erase(s.begin());
                s.insert(c[i]);
            }
        }
    }
    cout<<ans<<"\n";
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