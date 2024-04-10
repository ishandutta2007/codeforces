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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    set<pii> s;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        if(a[i] == 0) {
            continue;
        }
        s.insert({a[i],i});
    }
    vector<pii> ans;
    while(sz(s) >= 2) {
        auto f = *s.begin();
        auto g = *s.rbegin();
        s.erase(f),s.erase(g);
        ans.push_back({f.S,g.S});
        --f.F;
        --g.F;
        if(f.F > 0) {
            s.insert(f);
        }
        if(g.F > 0) {
            s.insert(g);
        }
    }
    cout << sz(ans) << "\n";
    for(auto &[i,j]:ans) {
        cout << i << " " << j << "\n";
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
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}