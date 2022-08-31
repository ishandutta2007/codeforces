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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(all(b));
    int mn = 1e9, x = -1;
    int want = (n + k + 1)/2;
    for(int i=0;i+want-1<n;++i) {
        if(b[i + want - 1] - b[i] < mn) {
            mn = b[i + want - 1] - b[i];
            x = b[i];
        }
    }
    cout << x << " " << x + mn << "\n";
    int l = 0, sum = 0;
    want = 1;
    for(int i=0;i<n;++i) {
        sum += a[i] >= x && a[i] <= x + mn;
        sum -= a[i] < x || a[i] > x + mn;
        if(want == k) {
            cout << l + 1 << " " << n << "\n";
            break;
        }
        if(sum == want) {
            cout << l + 1 << " " << i + 1 << "\n";
            ++want;
            l = i + 1;
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}