#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fi first
#define se second
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 200010;

vector<int>g[N];
int n, k;
void init() {
    scanf("%d%d", &n, &k);
    for (int i = 1, x, y; i < n; i++) {
        scanf("%d%d", &x, &y), g[x].push_back(y), g[y].push_back(x);
    }
}

int dep[N], fa[N], clv;
int mx[N], md[N];
int vis[N], T;

void clear() {
    for (int i = 1; i <= n; i++) {
        g[i].clear(), dep[i] = fa[i] = mx[i] = md[i] = vis[i] = 0;
    }
    clv = T = n = k = 0;
}
void dfs(int u, int p) {
    fa[u] = p;
    if (u != 1 && g[u].size() == 1) {
        ++clv;
    }
    mx[u] = 1, md[u] = u;
    for (int v : g[u])
        if (v != p) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
            if (mx[v] + 1 > mx[u]) {
                mx[u] = mx[v] + 1, md[u] = md[v];
            }
        }
}

void solve() {
    dfs(1, 0);
    if (clv <= k) {
        ll ans = 0;
        for (int i = clv; i <= k; i++) {
            ans = max(ans, 1ll * i * (n - i));
        }
        printf("%lld\n", ans);
        return;
    }
    int w = 0;
    priority_queue<pair<int, int>>q;
    q.push({mx[1], md[1]});
    for (int _ = 0; _ < k; _++) {
        auto p = q.top();
        q.pop();
        w += p.fi;
        ++T;
        for (int u = p.se; u && !vis[u]; u = fa[u]) {
            vis[u] = T;
        }
        for (int u = p.se; u && vis[u] == T; u = fa[u]) {
            for (int v : g[u])
                if (!vis[v])
                    q.push({mx[v], md[v]});
        }
    }
    ll ans = 1e18;
    for (int i = 0; i + w <= n; i++) {
        ans = min(ans, 1ll * (n - k - i) * (k - i));
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d",&t);
    while (t--) {
        init();
        solve();
        clear();
    }
    return 0;
}