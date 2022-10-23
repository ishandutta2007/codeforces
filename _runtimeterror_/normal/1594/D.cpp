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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<pii> ed;
    vector<int> p(n+1),sub(n+1,1);
    iota(all(p),0);
    function<int(int)> parent = [&](int x) {
        return p[x] = (p[x] == x ? x : parent(p[x]));
    };
    function<void(int,int)> merge = [&](int x,int y) {
        x = parent(x), y = parent(y);
        if(x == y) {
            return ;
        }
        if(sub[x] < sub[y]) {
            swap(x, y);
        }
        p[y] = x;
        sub[x] += sub[y];
    };
    for(int i=0;i<m;++i) {
        int x,y;
        cin >> x >> y;
        string s;
        cin >> s;
        if(s == "crewmate") {
            merge(x, y);
        }
        else {
            ed.push_back({x,y});
        }
    }
    for(auto [i,j]:ed) {
        if(parent(i) == parent(j)) {
            cout << "-1\n";
            return 0;
        }
        g[parent(i)].push_back(parent(j));
        g[parent(j)].push_back(parent(i));
    }
    vector<int> vis(n+1,-1);
    auto bfs = [&](int s) {
        if(parent(s) != s) {
            return 0;
        }
        vector<int> q = {s};
        vis[s] = 0;
        vector<int> cnt(2,0);
        cnt[0] += sub[s];
        for(int i=0;i<q.size();++i) {
            int u = q[i];
            for(auto &j:g[u]) {
                if(vis[j] == -1) {
                    vis[j] = 1 - vis[u];
                    cnt[vis[j]] += sub[j];
                    q.push_back(j);
                }
                else if(vis[j] == vis[u]) {
                    return -1;
                }
            }
        }
        return max(cnt[0], cnt[1]);
    };
    int ans = 0;
    for(int i=1;i<=n;++i) {
        if(vis[i] == -1) {
            int tmp = bfs(i);
            if(tmp == -1) {
                cout << "-1\n";
                return 0;
            }
            ans += tmp;
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