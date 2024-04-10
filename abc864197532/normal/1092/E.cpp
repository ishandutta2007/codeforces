#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << endl;\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 1000, logN = 18, K = 600, C = 100, M = 1e9;

vector <int> adj[N];
int dep[N];
bool vis[N];
vector <vector <int>> cur;

void dfscc(int v, int pa) {
    vis[v] = true;
    cur.back().pb(v);
    for (int u : adj[v]) if (u != pa) {
        dfscc(u, v);
    }
}

void dfs(int v, int pa) {
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    fop (i,0,m) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fop (i,0,n) if (!vis[i]) {
        cur.pb({});
        dfscc(i, -1);
    }
    vector <pii> re;
    vector <int> dia;
    for (auto A : cur) {
        re.pb(mp(1 << 30, -1));
        dia.pb(0);
        for (int v : A) {
            dfs(v, -1);
            int mx = 0;
            for (int u : A) {
                mx = max(mx, dep[u]);
            }
            dia.back() = max(dia.back(), mx);
            re.back() = min(re.back(), mp(mx, v));
        }
    }
    sort(rall(re));
    int tans = *max_element(all(dia));
    if (re.size() == 1) {
        cout << tans << endl;
    } else if (re.size() == 2) {
        cout << max(re[0].X + re[1].X + 1, tans) << endl;
    } else {
        cout << max({re[0].X + re[1].X + 1, re[1].X + re[2].X + 2, tans}) << endl;
    }
    fop (i,1,re.size()) cout << re[0].Y + 1 << ' ' << re[i].Y + 1 << endl;
}