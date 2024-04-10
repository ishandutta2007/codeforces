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
    int n;
    cin >> n;
    vector<int> a(n+1);
    map<int, int> last;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        last[a[i]] = i;
    }
    int ans = 0;
    for(int i=1;i<=n;++i) {
        int len = 0, r = last[a[i]];
        int cnt = 0;
        int cur = i;
        while(true) {
            int pv = r;
            ++cnt;
            while(cur <= pv) {
                amax(r, last[a[cur]]);
                ++len;
                ++cur;
            }
            if(r == pv) {
                i = r;
                break;
            }
        }
        ans += len - 1;
        ans -= len >= 2;
        ans -= cnt - 1;
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
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}