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
    vector<string> a(n);
    vector<int> len(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        len[i] = sz(a[i]);
    }
    vector<map<int,int>> mp(n);
    vector<int> tsum(n,0);
    for(int i=0;i<n;++i) {
        int mn = 0;
        for(char c:a[i]) {
            tsum[i] += c == '(';
            tsum[i] -= c == ')';
            if(tsum[i] <= mn) {
                ++mp[i][tsum[i]];
                amin(mn, tsum[i]);
            }
        }
    }
    // dp[mask] -> mask and each prefix is good broo
    vector<ll> dp(1 << n, -INF);
    dp[0] = 0;
    vector<ll> sum(1 << n, 0);
    for(int i=1;i<(1 << n);++i) {
        for(int j=0;j<n;++j) {
            if(i & (1 << j)) {
                sum[i] += tsum[j];
            }
        }
    }
    ll ans = 0;
    for(int i=0;i<(1 << n);++i) {
        amax(ans, dp[i]);
        if(dp[i] == -INF) {
            continue;
        }
        for(int j=0;j<n;++j) {
            if((i & (1 << j)) == 0) {
                int f = mp[j].empty() ? 0 : mp[j].begin()->F;
                if(f + sum[i] < 0) {
                    int val = mp[j].count(-sum[i]) ? mp[j][-sum[i]] : 0;
                    amax(ans, dp[i] + val);
                }
                else {
                    int val = mp[j].count(-sum[i]) ? mp[j][-sum[i]] : 0;
                    amax(dp[i|(1 << j)], dp[i] + val);
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
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}