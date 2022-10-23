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


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    ordered_set<pii> s;
    ll ans = 0;
    auto small = [&](int x) {
        return s.order_of_key({x,-1});
    };
    auto big = [&](int x) {
        return sz(s) - s.order_of_key({x, 1e9+2});
    };
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        int sm = small(a[i]), g = big(a[i]);
        ans += min(sm, g);
        s.insert({a[i],i});
    }
    cout << ans << "\n";
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