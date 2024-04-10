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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+1),b(n+1),l(n+1),r(n+1),ans(n+1,m);
    ll L = 0, R = 0;
    for(int i=1;i<=n;++i) {
        cin >> a[i] >> b[i];
        l[i] = a[i] - b[i] - min(a[i], m) + m - min(a[i], m);
        r[i] = a[i] - b[i] + min(b[i], m) - m + min(b[i], m);
        ans[i] = min(m, a[i]);
        L += l[i], R += r[i];
    }
    if(L > 0) {
        cout << L << "\n";
        for(int i=1;i<=n;++i) {
            cout << min(m, a[i]) << " " << m - min(m, a[i]) << "\n";
        }
    }
    else if(R < 0) {
        cout << -R << "\n";
        for(int i=1;i<=n;++i) {
            cout << m - min(m, b[i]) << " " << min(m, b[i]) << "\n";
        }
    }
    else {
        assert(R >= 0);
        cout << R % 2 << "\n";
        for(int i=1;i<=n;++i) {
            if(L == 0 || L == 1) {
                continue;
            }
            int can = r[i] - l[i];
            assert(can % 2 == 0);
            if(L + can < 0) {
                ans[i] = m - min(b[i], m);
                L += can;
            }
            else {
                int want = (-L + 1)/2;
                ans[i] -= want;
                break;
            }
        }
        for(int i=1;i<=n;++i) {
            cout << ans[i] << " " << m - ans[i] << "\n";
        }
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