#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             9000000000000000000
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
    vector<ll> a(n);
    ll sum = 0;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    int m;
    cin >> m;
    while(m--)
    {
        ll x,y;
        cin >> x >> y;
        auto it = lower_bound(all(a),x) - a.begin();
        ll ans = INF;
        if(it < n) {
            amin(ans, max(y - sum + a[it],0ll));
        }
        if(it > 0) {
            --it;
            amin(ans, max(y - sum + a[it],0ll) + max(0ll, x - a[it]));
        }
        cout << ans << "\n";
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
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}