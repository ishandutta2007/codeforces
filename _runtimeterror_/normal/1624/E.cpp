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
    int n, m;
    cin >> n >> m;
    map<string, array<int,3>> mp;
    for(int i=0;i<n;++i) {
        string s;
        cin >> s;
        for(int j=0;j<m;++j) {
            string t;
            for(int k=j;k<m;++k) {
                t += s[k];
                if(sz(t) > 3) {
                    break;
                }
                if(sz(t) >= 2) {
                    mp[t] = {j+1, k+1, i+1};
                }
            }
        }
    }
    string s;
    cin >> s;
    vector<int> dp(m+1,0);
    dp[0] = 1;
    for(int i=2;i<=m;++i) {
        for(int len=2;len<=3;++len) {
            if(i - len >= 0) {
                if(mp.count(s.substr(i-len,len))) {
                    dp[i] |= dp[i-len];
                }
            }
        }
    }
    if(!dp[m]) {
        cout << "-1\n";
        return 0;
    }
    vector<array<int,3>> ans;
    int last = m;
    for(int i=m;i>=1;--i) {
        if(last != i) {
            continue;
        }
        for(int len=2;len<=3;++len) {
            if(i - len >= 0 && mp.count(s.substr(i-len, len)) && dp[i-len]) {
                ans.push_back(mp[s.substr(i-len, len)]);
                last -= len;
                break;
            }
        }
    }
    cout << sz(ans) << "\n";
    reverse(all(ans));
    for(auto [i, j, k]:ans) {
        cout << i << " " << j << " " << k << "\n";
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}