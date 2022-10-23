#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
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
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 1010;
const ll inf = 1000000000000000;

namespace dinic {
    int all;
    const int M = 400010;
    struct road {
        int nxt, to;
        ll w;
    } r[M];
    int head[N], cnt;
    void add(int u, int v, ll w) {
        r[++cnt] = (road) {head[u], v, w};
        head[u] = cnt;
        r[++cnt] = (road) {head[v], u, 0};
        head[v] = cnt;
    }
    int dis[N], cur[N];
    queue<int>q;
    bool bfs(int s, int t) {
        for (int i = 1; i <= all; i++) {
            dis[i] = 0, cur[i] = head[i];
        }
        dis[s] = 1;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = head[u]; i; i = r[i].nxt)
                if (r[i].w) {
                    int v = r[i].to;
                    if (!dis[v]) {
                        dis[v] = dis[u] + 1, q.push(v);
                    }
                }
        }
        return dis[t];
    }
    ll dfs(int u, int t, ll flow = inf) {
        if (u == t || !flow) {
            return flow;
        }
        ll res = 0;
        for (int &i = cur[u]; i; i = r[i].nxt) {
            int v = r[i].to;
            ll f;
            if (dis[v] == dis[u] + 1 && (f = dfs(v, t, min(flow, r[i].w)))) {
                flow -= f;
                res += f;
                r[i].w -= f;
                r[i ^ 1].w += f;
                if (!flow) {
                    break;
                }
            }
        }
        return res;
    }
    ll work(int s, int t) {ll res = 0; while (bfs(s, t)) res += dfs(s, t); return res;}
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            head[i] = cur[i] = 0;
        }
        cnt = 1;
        all = n;
    }
}
using dinic::add;
using dinic::work;
vector<int>g[N];
int a[N], n, m;
void init() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y), g[x].push_back(y);
    }
}
int l[N], r[N];
void solve() {
    int s = n + 1, t = n + 2;
    for (int i = 1; i <= n; i++) {
        l[i] = 0, r[i] = 1e9 + 1;
    }
    ll ans = 0;
    for (int _ = 0; _ <= 40; _++) {
        dinic::init(t);
        for (int i = 1; i <= n; i++) {
            int mid = (l[i] + r[i]) >> 1;
            add(s, i, abs(a[i] - mid));
            add(i, t, abs(a[i] - (mid + 1)));
        }
        for (int u = 1; u <= n; u++)
            for (int v : g[u])
                if (l[u] == l[v] && r[u] == r[v]) {
                    add(u, v, inf);
                }
        ans = dinic::work(s, t);
        for (int i = 1; i <= n; i++) {
            int mid = (l[i] + r[i]) >> 1;
            if (dinic::dis[i]) {
                l[i] = mid + 1;
            } else {
                r[i] = mid;
            }
        }
    }
    cerr << ans << endl;
    for (int i = 1; i <= n; i++) {
        printf("%d ", l[i]);
    }
}

int main() {
    init();
    solve();
    return 0;
}