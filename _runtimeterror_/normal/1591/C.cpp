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
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, k;
    cin >> n >> k;
    vector<ll> pos, neg;
    for(int i=0;i<n;++i) {
        int x;
        cin >> x;
        if(x > 0) {
            pos.push_back(x);
        }
        else {
            neg.push_back(-x);
        }
    }   
    pos.push_back(0);
    neg.push_back(0);
    sort(all(pos)), sort(all(neg));
    ll ans = INF;
    auto solve = [&]() {
        auto get = [&](vector<ll> &a) {
            ll cnt = 1;
            ll ans = 0;
            for(int i=sz(a)-2;i>=0;--i) {
                ans += 2 * ((cnt + k - 1)/k) * (a[i+1] - a[i]);
                ++cnt;
            }
            return ans;
        };  
        auto last_k = [&](vector<ll> &a) {
            return a.back();
        };
        amin(ans, get(pos) + get(neg) - last_k(pos));
        debug(ans);
    };
    solve();
    swap(pos, neg);
    solve();
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