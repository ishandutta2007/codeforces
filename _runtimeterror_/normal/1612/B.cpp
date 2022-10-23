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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ans(n+1);
    ans[n/2] = a;
    ans[n/2+1] = b;
    int cur = n;
    for(int i=n/2-1;i>=1;--i) {
        if(cur == b) {
            --cur;
        }
        ans[i] = cur;
        --cur;
    }
    cur = 1;
    for(int i=n/2+2;i<=n;++i) {
        if(cur == a) {
            ++cur;
        }
        ans[i] = cur;
        ++cur;
    }
    set<int> s;
    int u = n;
    for(int i=1;i<=n/2;++i) {
        s.insert(ans[i]);
        if(ans[i] < 1 || ans[i] > n) {
            cout << "-1\n";
            return 0;
        }
        amin(u, ans[i]);
    }
    if(u != a) {
        cout << "-1\n";
        return 0;
    }
    u = 1;
    for(int i=n/2+1;i<=n;++i) {
        s.insert(ans[i]);
        if(ans[i] < 1 || ans[i] > n) {
            cout << "-1\n";
            return 0;
        }
        amax(u, ans[i]);
    }
    if(u != b || sz(s) != n) {
        cout << "-1\n";
        return 0;
    }
    for(int i=1;i<=n;++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
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