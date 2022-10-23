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
    ll n;
    cin >> n;
    vector<ll> a(n+1),b(n+1),l(n+1),m(n+1),r(n+1),ans(n+1);
    ll L = 0, R = 0;
    map<pii,vector<int>> mp;
    for(int i=1;i<=n;++i) {
        cin >> a[i] >> b[i] >> m[i];
        l[i] = a[i] - b[i] - min(a[i], m[i]) + m[i] - min(a[i], m[i]);
        r[i] = a[i] - b[i] + min(b[i], m[i]) - m[i] + min(b[i], m[i]);
        ans[i] = min(m[i], a[i]);
        mp[{a[i] + b[i] - m[i], (a[i] + b[i] + m[i]) & 1}].push_back(i);
        L += l[i], R += r[i];
    }
    ll cnt = 0;
    for(auto &[j,v]:mp) {
        sort(all(v),[&](int x,int y) {
            return l[x] < l[y];
        });
        ll rx = INF;
        vector<ll> t;
        auto make = [&](vector<ll> a, ll f) {
            cnt += sz(a) > 0;
            for(auto &i:a) {
                ll g = f - l[i];
                assert(g % 2 == 0);
                g /= 2;
                ans[i] -= g;
            }
        };
        for(auto &i:v) {
            if(l[i] > rx) {
                make(t, rx);
                t = {i};
                rx = r[i];
            }
            else {
                t.push_back(i);
                amin(rx, r[i]);
            }
        }
        make(t, rx);
    }
    cout << cnt << "\n";
    for(int i=1;i<=n;++i) {
        cout << ans[i] << " " << m[i] - ans[i] << "\n";
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