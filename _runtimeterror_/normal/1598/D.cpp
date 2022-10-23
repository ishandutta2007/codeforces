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
    int n;
    cin >> n;
    vector<map<ll,ll>> mp(n+1);
    map<ll,ll> X, Y;
    for(int i=1;i<=n;++i) {
        int x, y;
        cin >> x >> y;
        ++mp[x][y];
        ++X[x], ++Y[y];
    }
    ll ans = 0;
    ll sum = 0, cur = 0;
    for(auto &[j,k]:X) {
        ans += cur * k;
        cur += sum * k;
        sum += k;
    }
    sum = cur = 0;
    for(auto &[j,k]:Y) {
        ans += cur * k;
        cur += sum * k;
        sum += k;
    }    
    vector<ll> z(n+1), t(n+1), m(n+1), f(n+1), fsum(n+1);
    ll x = 0,tx = 0;
    sum = cur = 0;
    for(auto &maps:mp) {
        ll total = 0;
        for(auto &[i,j]:maps) {
            ans += x * t[i] - t[i] * t[i] - z[i] + m[i] + tx;
            // debug(x * t[i] + t[i] * t[i] + z[i] - m[i]);
            ans -= cur;
            total += j;
        }   

        for(auto &[i,j]:maps) {
            t[i] += j;
            x += j;
            tx += fsum[i] * j;
            f[i] += fsum[i] * j;
            fsum[i] += j;
            z[i] += j * total;
            m[i] += j * j;
        }
        cur += total * sum;
        sum += total;
        // debug(ans,cur);
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