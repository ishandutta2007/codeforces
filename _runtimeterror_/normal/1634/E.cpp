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
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    vector<string> ans(m);
    map<int, int> mp;
    for(int i=0;i<m;++i) {
        int n;
        cin >> n;
        a[i].resize(n);
        ans[i] = string(n, '0');
        for(int j=0;j<n;++j) {
            cin >> a[i][j];
            ++mp[a[i][j]];
        }
    }
    for(auto &j:mp) {
        if(j.S & 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";

    map<int, set<pii>> ocs;
    vector<set<pii>> ocs2(m);

    for(int i=0;i<m;++i) {
        map<int, int> last;
        for(int j=0;j<sz(a[i]);++j) {
            if(!last.count(a[i][j]) || last[a[i][j]] == -1) {
                last[a[i][j]] = j;
            }
            else {
                ans[i][last[a[i][j]]] = 'L';
                ans[i][j] = 'R';
                last[a[i][j]] = -1;
            }
        }
        for(int j=0;j<sz(a[i]);++j) {
            if(ans[i][j] == '0') {
                ocs[a[i][j]].insert({i, j});
                ocs2[i].insert({a[i][j], j});
            }
        }
    }
    for(int i=0;i<m;++i) {
        int n = sz(a[i]);
        for(int j=0;j<n;++j) {
            if(ans[i][j] == '0') {
                int cur = 0;
                int row = i, col = j;
                while(1) {
                    ocs[a[row][col]].erase({row, col});
                    ocs2[row].erase({a[row][col], col});
                    ans[row][col] = cur ? 'R' : 'L';
                    if(row == i && cur == 1) {
                        break;
                    }
                    if(cur == 0) {
                        int u = a[row][col];
                        row = ocs[u].begin()->F;
                        col = ocs[u].begin()->S;
                    }
                    else {
                        col = ocs2[row].begin()->S;
                    }
                    cur ^= 1;
                }
            }
        }
    }

    for(int i=0;i<m;++i) {
        cout << ans[i] << "\n";
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}