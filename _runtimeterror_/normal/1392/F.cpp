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


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    ll sum = 0;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        sum += a[i];
    }
    bool good = true;
    for(int i=2;i<=n;++i) {
        if(a[i] == a[i-1] + 1) {
            continue;
        }
        good = false;
    }
    if(good) {
        for(int i=1;i<=n;++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    for(int i=1;i<=n-1;++i) {
        ll x = n * 1ll * (n - 1)/2 + i;
        if(sum >= x && (sum - x) % n == 0 && (sum - x) / n + 1 >= a[1]) {
            sum -= x;
            sum /= n;
            for(int j=1;j<=i;++j) {
                cout << j + sum << " "; 
            }
            cout << i + sum << " ";
            for(int j=i+2;j<=n;++j) {
                cout << j - 1 + sum << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    for(int i=1;i<=n;++i) {
        cout << i + (sum - n * 1ll * (n + 1) / 2) / n << " ";
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