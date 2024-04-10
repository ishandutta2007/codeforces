#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = (l); x < (r); ++x)
#define LoopR(x, l, r) for(int x = (r)-1; x >= (l); --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << (x) << '\n', 0
#define YN(flag) ((flag)? "YES": "NO")
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
//#pragma GCC optimize ("O0")
using namespace std;

const int N = 100'010;
vector<int> A[N];
vector<int> T[N];
int vis[N][52] = {};
bool vis1[N][52] = {};
char gd[N][52];
bool fvis[N] = {};
int c[N][52];
int ans = 0;
int D, n, m;
pii scc[52*N]; int sccs = 0;
list<int> cmp[52*N];
ll ccnt[52*N] = {};
int dp[52*N] = {};

void dfs1(int su, int sd)
{
    static stack<pair<pii, int>> s;
    s.push({{su, sd}, 0});
    int u, d, i;
    back1:
    if(!s.size()) return;
    u = s.top().F.F;
    d = s.top().F.S;
    i = s.top().S;
    s.pop();
    back2:
    vis1[u][d] = 1;
    for(; i < A[u].size(); ++i)
        if(!vis1[A[u][i]][(d+1)%D])
        {
            s.push({{u, d}, i+1});
            u = A[u][i];
            d = (d+1)%D;
            i = 0;
            goto back2;
        }
    scc[sccs++] = {u, d};
    goto back1;
}


void bfs2(int su, int sd, int st)
{
    static queue<tuple<int, int, int>> Q;
    static set<int> cmpv;
    cmpv.clear();
    Q.emplace(su, sd, st); vis[su][sd] = st;
    while(Q.size())
    {
        int u = get<0>(Q.front());
        int d = get<1>(Q.front());
        int t = get<2>(Q.front());
        Q.pop();
        c[u][d] = t;
        if(!cmpv.count(u) && gd[u][d]-'0') {ccnt[t]++; cmpv.insert(u);}
        d = (d+D-1)%D;
        for(int v : T[u])
            if(!vis[v][d] && vis1[v][d])
                Q.emplace(v, d, t), vis[v][d] = t;
            else if (vis[v][d] < t && vis1[v][d])
                cmp[vis[v][d]].push_back(t);
    }
}

int main()
{
    FAST;
    cin >> n >> m >> D;
    //bool flag = 0;
    Loop(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        A[u-1].push_back(v-1);
        T[v-1].push_back(u-1);
    }
    Loop(i,0,n){
        cin >> gd[i];
    }
    //Loop(i,0,n) Loop(d,0,D) if(!vis[i][d]) dfs1(i, d);
    dfs1(0, 0);
    int dmy = 1; reverse(scc, scc+sccs);
    Loop(i,0,sccs) if(!vis[scc[i].F][scc[i].S] && vis1[scc[i].F][scc[i].S]) bfs2(scc[i].F, scc[i].S, dmy++);
    dp[dmy-1] = ccnt[dmy-1];
    LoopR(i,1,dmy-1)
    {
        dp[i] = 0;
        for(auto v : cmp[i])
            dp[i] = max(dp[i], dp[v]);
        dp[i] += ccnt[i];
    }
    cout << dp[c[0][0]] << '\n';
}