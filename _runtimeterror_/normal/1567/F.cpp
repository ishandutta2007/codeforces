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
    int n,m;
    cin >> n >> m;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin >> a[i][j];
    vector<vector<int>> g(n*m+10);
    vector<int> dx = {0,-1,0,1}, dy = {-1,0,1,0};
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j)
        {
            if(a[i][j] == '.')
                continue;
            vector<int> t;
            for(int k=0;k<4;++k)
            {
                int u = i + dx[k], v = j + dy[k];
                if(a[u][v] == '.')
                    t.push_back(v + (u - 1) * m);
            }
            if(sz(t) & 1) {
                cout << "NO\n";
                return 0;
            }
            for(int i=0;i<sz(t);++i)
                g[t[i]].push_back(t[(i+1)%sz(t)]),g[t[(i+1) % sz(t)]].push_back(t[i]);
        }
    }
    vector<vector<int>> ans(n+1,vector<int>(m+1));
    vector<int> vis(n*m+10,-1);
    auto bfs = [&](int s)
    {
        queue<int> q;
        q.push(s);
        vis[s] = 0;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(auto &j:g[x])
            {
                if(vis[j] == -1)
                {
                    vis[j] = 1 - vis[x];
                    // debug(vis[x]);
                    q.push(j);
                }
                else if(vis[j] == vis[x]) {
                    cout << "NO\n";
                    exit(0);
                }

            }
        }
    };
    for(int i=1;i<=n*m;++i)
        if(vis[i] == -1)
            bfs(i);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            ans[i][j] = vis[(i-1)*m+j] == 0 ? 1 : 4;
        }
    }
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i][j] == '.')
                continue;
            ans[i][j] = 0;
            for(int k=0;k<4;++k)
            {
                int u = i + dx[k], v = j + dy[k];
                if(a[u][v] == '.')
                    ans[i][j] += ans[u][v];
            }
        }
    }
    cout << "YES\n";
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
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