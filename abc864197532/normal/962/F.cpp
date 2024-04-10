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
const int mod = 1e9 + 7, x = 864197532, N = 100005, logN = 18, K = 600, C = 100, M = 1e9;

vector <pii> adj[N];
vector <pii> E;
vector <vector <int>> bcc;
stack <int> stk;
bool vis[N], vis2[N];
int low[N], dep[N];

void dfs(int v, int pa, int w = -1) {
    if (~w) stk.push(w), vis2[w] = true;
    low[v] = dep[v] = ~pa ? dep[pa] + 1 : 0;
    vis[v] = true;
    for (pii A : adj[v]) if (A.X != pa) {
            if (vis[A.X]) {
                if (!vis2[A.Y]) stk.push(A.Y), vis2[A.Y] = true;
                low[v] = min(low[v], dep[A.X]);
            } else {
                dfs(A.X, v, A.Y);
                low[v] = min(low[v], low[A.X]);
                if (low[A.X] >= dep[v]) {
                    int x;
                    bcc.pb({});
                    do {
                        x = stk.top(); stk.pop();
                        bcc.back().pb(x);
                    } while (x != A.Y);
                }
            }
        }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    fop (i,0,m) {
        cin >> u >> v, u--, v--;
        adj[u].eb(v, i);
        adj[v].eb(u, i);
        E.eb(u, v);
    }
    fop (i,0,n) if (!vis[i]) dfs(i, -1);
    vector <int> ans;
    for (auto A : bcc) {
        set <int> s;
        for (int id : A) {
            s.insert(E[id].X);
            s.insert(E[id].Y);
        }
        if (s.size() == A.size()) {
            for (int id : A) ans.pb(id + 1);
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    printv(ans);
}