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
const int mod = 1e9 + 7, x = 864197532, N = 200005, logN = 18, K = 600, C = 100, M = 1e9;

vector <int> adj[N];

int dsu[N];

void init() {
    fop (i,0,N) dsu[i] = i;
}

int Find(int x) {
    if (x == dsu[x]) return x;
    return dsu[x] = Find(dsu[x]);
}

bool Union(int u, int v) {
    u = Find(u), v = Find(v);
    if (u == v) return false;
    dsu[u] = v;
    return true;
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
    int mx = 0;
    fop (i,0,n) if (adj[mx].size() < adj[i].size()) mx = i;
    init();
    vector <pii> ans;
    for (int i : adj[mx]) {
        ans.eb(i, mx);
        Union(i, mx);
    }
    fop (i,0,n) for (int j : adj[i]) if (Union(i, j)) ans.eb(i, j);
    for (pii A : ans) cout << A.X + 1 << ' ' << A.Y + 1 << endl;
}