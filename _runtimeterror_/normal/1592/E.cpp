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

const int N = 2e6 + 5;

int last[N];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for(int i=0;i<=2e6;++i) {
        last[i] = N;
    }
    int mask = 0;
    int ans = 0;
    auto evaluate = [&](vector<int> a) {
        if(sz(a) == 0) {
            return ;
        }
        // debug(a);
        int n = a.size();
        int pxor = 0;
        last[0] = -1;
        for(int i=0;i<n;++i) {
            pxor ^= a[i];
            amax(ans, i - last[pxor]);
            if(last[pxor] == N) {
                last[pxor] = i;
            }
        }
        last[0] = N;
        pxor = 0;
        for(int i=0;i<n;++i) {
            pxor ^= a[i];
            last[pxor] = N;
        }
    };
    for(int i=20;i>=0;--i) {
        mask |= 1 << i;
        vector<int> t;
        for(int j=1;j<=n;++j) {
            if(a[j] & (1 << i)) {
                t.push_back(a[j] & mask);
            }
            else {
                evaluate(t);
                t.clear();
            }
        }
        evaluate(t);
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
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}