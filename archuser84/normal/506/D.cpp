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
//#pragma GCC optimize ("Ofast")
using namespace std;

const int N = 1e5;
const int S = 320;
int par[S][N];
int cmp[N]; int bigs = 0;
int cnte[N];
vector<int> cnt[N];
int done[N];
int n, m;

int root(int i, int c) { return par[c][i] >= 0? par[c][i] = root(par[c][i], c): i; }

void unite(int a, int b, int c)
{
    a = root(a, c);
    b = root(b, c);
    if(a != b) par[c][b] = a;
}

vector<pair<int, pii>> E;
vector<int> A[N];

bool vis[N] = {};
void dfs(int u, int r)
{
    vis[u] = 1;
    if(r > u) cnt[u].push_back(r);
    for(int v : A[u])
        if(!vis[v])
            dfs(v, r);
}


int main()
{
    FAST;
    cin >> n >> m;
    Loop(i,0,m)
    {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--; c--;
        E.push_back({c, {u, v}});
        cnte[c]++;
    }
    memset(done, -1, sizeof done);
    memset(par, -1, sizeof par);
    Loop(i,0,n) if(cnte[i] > S) cmp[i] = bigs++;
    E.push_back({m+1, {n+1, n+1}}); sort(all(E));
    int l = -1;
    vector<pair<int, pii>> tmp;
    for(auto e : E)
    {
        if(cnte[e.F] > S) {unite(e.S.F, e.S.S, cmp[e.F]); continue;}
        if(e.F != l)
        {
            for(auto e : tmp) A[e.S.F].clear(), A[e.S.S].clear();
            for(auto e : tmp) A[e.S.F].push_back(e.S.S), A[e.S.S].push_back(e.S.F);
            for(auto e : tmp){
                if(done[e.S.F] != e.F)
                {
                    for(auto e : tmp) vis[e.S.F] = 0, vis[e.S.S] = 0;
                    dfs(e.S.F, e.S.F);
                    done[e.S.F] = e.F;
                }
                if(done[e.S.S] != e.F)
                {
                    for(auto e : tmp) vis[e.S.F] = 0, vis[e.S.S] = 0;
                    dfs(e.S.S, e.S.S);
                    done[e.S.S] = e.F;
                }
            }
            l = e.F;
            tmp.clear();
        }
        tmp.push_back(e);
    }
    Loop(i,0,n) sort(all(cnt[i]));
    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b) swap(a, b);
        int ans = upper_bound(all(cnt[a]), b) - lower_bound(all(cnt[a]), b);
        Loop(c,0,bigs) if(root(a, c) == root(b, c)) ++ans;
        cout << ans << '\n';
    }
}