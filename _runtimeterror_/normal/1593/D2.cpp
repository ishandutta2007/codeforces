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
    ll ans = 0;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    sort(all(a));
    for(int i=0;i<n/2+1;++i) {
        if(a[i] == a[i + n/2 - 1]) {
            cout << "-1\n";
            return 0;
        }
    }
    for(int i=0;i<n;++i) {
        vector<int> b(n);
        for(int j=0;j<n;++j) {
            b[j] = abs(a[j] - a[i]);
        }
        for(int j=0;j<n;++j) {
            if(b[j] == 0) {
                continue;
            }
            vector<int> fs;
            for(int k=1;k*k<=b[j];++k) {
                if(b[j] % k == 0) {
                    fs.push_back(k);
                    fs.push_back(b[j] / k);
                }
            }
            for(auto &f:fs) {
                int cnt = 0;
                for(int k=0;k<n;++k) {
                    cnt += b[k] % f == 0;
                }
                if(cnt >= n / 2) {
                    amax(ans, f);
                }
            }
        }
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