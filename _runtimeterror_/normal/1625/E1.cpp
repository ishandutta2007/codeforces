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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> p(n+1, vector<int>(20, 0));
    vector<vector<ll>> cnt(n+1, vector<ll>(20, 0));
    vector<ll> sum(n+1, 0), dp(n+1, 0);
    map<int,int> last;
    last[0] = 0;
    vector<int> st = {0};
    map<int,int> cof;
    cof[0] = 1;
    for(int i=1;i<=n;++i) {
        sum[i] = sum[i-1] + (s[i-1] == '(' ? 1 : -1);
        dp[i] = dp[i-1];
        if(last.count(sum[i]) && s[i-1] == ')') {
            p[i][0] = last[sum[i]];
            cnt[i][0] = dp[i] - dp[last[sum[i]]] + 1;
        }
        else {
            p[i][0] = i;
        }
        last[sum[i]] = i;
        while(!st.empty() && sum[i] < st.back()) {
            --cof[st.back()];
            st.pop_back();
        }
        st.push_back(sum[i]);
        dp[i] += cof[sum[i]];
        ++cof[sum[i]];
        debug(i, cnt[i][0]);
    }
    for(int j=1;j<20;++j) {
        for(int i=1;i<=n;++i) {
            p[i][j] = p[p[i][j-1]][j-1];
            cnt[i][j] = cnt[i][j-1] + cnt[p[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=q;++i) {
        int tt, l, r;
        cin >> tt >> l >> r;
        --l;
        ll ans = 0;
        int jumps = 0;
        for(int j=19;j>=0;--j) {
            if(p[r][j] > l) {
                ans += cnt[r][j];
                jumps += (1 << j);
                r = p[r][j];
            }
        }
        ++jumps;
        ans += cnt[r][0];
        ans += jumps * 1ll * (jumps - 1)/2;
        debug(ans, jumps);
        cout << ans << "\n";
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
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}