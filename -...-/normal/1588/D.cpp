// Har Har Mahadev
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
    vector<vector<int>> a(n);
    for(int i=0;i<n;++i) {
        string s;
        cin >> s;
        for(int j=0;j<sz(s);++j) {
            if(s[j] >= 'a' && s[j] <= 'z') {
                a[i].push_back(s[j] - 'a');
            }
            else {
                a[i].push_back(26 + s[j] - 'A');
            }
        }
    }
    vector<vector<int>> tups;
    vector<vector<int>> mask_id(52,vector<int>(1 << n));
    map<vector<int>,int> masks;
    // vector<vector<vector<int>>> occs(52, vector<vector<int>>(n));
    for(int i=0;i<52;++i) {
        vector<vector<int>> ids(n);
        for(int j=0;j<n;++j) {
            for(int k=0;k<sz(a[j]);++k) {
                if(a[j][k] == i) {
                    ids[j].push_back(k);
                    // occs[i][j].push_back(k);
                }
            }
            assert(sz(ids[j]) <= 2);
            // if(occs[i][j].size() )
        }
        int cur = tups.size();
        int cnt = 0;
        for(int mask=0;mask<(1 << n);++mask) {
            vector<int> tup;
            for(int j=0;j<n;++j) {
                if(ids[j].empty()) {
                    continue;
                }
                if(mask & (1 << j)) {
                    tup.push_back(ids[j][min(1ll, sz(ids[j])-1)]);
                }
                else {
                    tup.push_back(ids[j][0]);
                }
            }
            if(sz(tup) == n) {
                tups.push_back(tup);
                ++cnt;
                masks[tup] = mask;
            }
        }
    }
    vector<vector<vector<int>>> last(n);
    for(int i=0;i<n;++i) {
        last[i].resize(sz(a[i]));
        for(int j=0;j<sz(a[i]);++j) {
            last[i][j].resize(52,-1);
            if(j > 0) {
                for(int k=0;k<52;++k) {
                    last[i][j][k] = last[i][j-1][k];
                }
            }
            last[i][j][a[i][j]] = j;
        }
    }
    sort(all(tups));
    tups.resize(unique(all(tups)) - tups.begin());
    for(int i=0;i<tups.size();++i) {
        int m = masks[tups[i]];
        mask_id[a[0][tups[i][0]]][m] = i;
        // debug(tups[i], m);
    }
    int ans = 0;
    vector<int> dp(tups.size());
    vector<int> par(tups.size());
    for(int i=0;i<tups.size();++i) {
        auto &v = tups[i];
        dp[i] = 1;
        par[i] = -1;
        // debug(v);
        for(int ch=0;ch<52;++ch) {
            
            int mask = 0;

            for(int j=0;j<n;++j) {
                if(v[j] == 0 || last[j][v[j]-1][ch] == -1) {
                    mask = -1;
                    break;
                }
                int sec = last[j][sz(a[j])-1][ch];
                int fir = sec;
                if(sec > 0 && last[j][sec-1][ch] != -1) {
                    fir = last[j][sec-1][ch];
                }
                int want = last[j][v[j]-1][ch];
                if(want == sec) {
                    mask |= (1 << j);
                }
            }
            if(mask >= 0) {
                int id = mask_id[ch][mask];
                if(dp[id] + 1 > dp[i])  {
                    dp[i] = dp[id] + 1;
                    par[i] = id;
                }
            }
        }
        amax(ans, dp[i]);
    }
    string aa = "";
    for(int i=0;i<tups.size();++i) {
        if(dp[i] == ans) {
            while(i != -1) {
                int val = a[0][tups[i][0]];
                if(val >= 26) {
                    aa += 'A' + val - 26;
                }
                else {
                    aa += 'a' + val;
                }
                i = par[i];
            }
            break;
        }
    }
    reverse(all(aa));
    cout << ans << "\n";
    cout << aa << "\n";
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