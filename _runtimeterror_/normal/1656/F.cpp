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
    vector<ll> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }

    ll ans = -9e18;

    sort(all(a));
    vector<ll> sum(n + 10, 0);
    for(int i=1;i<=n;++i) {
        sum[i] = sum[i-1] + a[i - 1];
    }
    for(int i=0;i<=n;++i) {
        ll cf = 0, cost = 0;
        cf += sum[i] + i * a[n - 1];
        cf += sum[n] - sum[i] + (n - i) * a[0];
        cost += sum[i] * a[n - 1];
        cost += (sum[n] - sum[i]) * a[0];
        if(i == 0) {
            cf -= a[0] + a[0];
            cost -= a[0] * a[0];
        }
        else if(i == n) {
            cf -= 2 * a[n-1];
            cost -= a[n-1] * a[n-1];
        }
        else {
            cf -= a[0] + a[n-1];
            cost -= a[0] * a[n-1];
        }

        ll l = -1e12, r = 1e12;
        if(i > 0) {
            r = -a[i - 1];
        }
        if(i < n) {
            l = -a[i];
        }
        if(i == 0 and cf > 0) {
            cout << "INF\n";
            return 0;
        }
        if(i == n and cf < 0) {
            cout << "INF\n";
            return 0;
        }
        if(i < n) {
            amax(ans, cost + cf * l);
        }
        if(i > 0) {
            amax(ans, cost + cf * r);
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}