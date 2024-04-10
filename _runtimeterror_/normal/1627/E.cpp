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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<pll>> low(n+1), high(n+1);
    // low me dp[i][j] - x[i] * j
    // high me dp[i][j] + x[i] * j
    vector<ll> x(n+1);
    for(int i=1;i<=n;++i) {
        cin >> x[i];
    }
    low[1].insert({1, -x[1]});
    high[1].insert({1, x[1]});
    vector<array<ll, 5>> p(k);
    for(int i=0;i<k;++i) {
        for(int j=0;j<5;++j) {
            cin >> p[i][j];
        }
    }
    sort(all(p));
    auto query = [&](int i, int j) {
        if(low[i].empty()) {
            return (ll)INF;
        }
        ll ans = INF;
        auto it = low[i].upper_bound(make_pair(j+1ll, -INF));
        if(it != low[i].begin()) {
            --it;
            amin(ans, x[i] * j + (it->S));
        }
        it = high[i].lower_bound(make_pair(j*1ll, -INF));
        if(it != high[i].end()) {
            amin(ans, -x[i] * j + (it->S));
        }
        return ans;
    };
    auto add = [&](int i, int j, ll val) {
        ll f = val - x[i] * j;
        while(true) {
            auto it = low[i].lower_bound(make_pair(j+0ll,-INF));
            if(it == low[i].end() || it->S <= f) {
                break;
            }
            low[i].erase(it);
        }
        auto it = low[i].upper_bound(make_pair(j+1ll,-INF));
        if(low[i].empty() || it == low[i].begin()) {
            low[i].insert({j, f});
        }
        else {
            --it;
            if(it->S > f) {
                low[i].insert({j, f});
            }
        }
        
        f = val + x[i] * j;
        while(true) {
            auto it = high[i].lower_bound(make_pair(j + 1ll,-INF));
            if(high[i].empty() || it == high[i].begin()) {
                break;
            }
            --it;
            if(it->S < f) {
                break;
            }
            high[i].erase(it);
        }
        it = high[i].lower_bound(make_pair(j + 1ll,-INF));
        if(high[i].empty() || it == high[i].end()) {
            high[i].insert({j, f});
        }
        else {
            if(it->S > f) {
                high[i].insert({j, f});
            }
        }
    };
    for(int i=0;i<k;++i) {
        ll f = query(p[i][0], p[i][1]);
        add(p[i][2], p[i][3], -p[i][4] + f);
    }
    ll ans = query(n, m);
    if(ans > 1e16) {
        cout << "NO ESCAPE\n";
        return 0;
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
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}