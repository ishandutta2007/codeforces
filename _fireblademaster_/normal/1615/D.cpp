#include <iostream>
#include <cstdio>
#include <cstring>
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
const int N = 400010;
int x[N], y[N], pre[N], z[N], f[N], n, m;
int nxt[N << 1], to[N << 1], w[N << 1], head[N], cnt;
void add(int u, int v, int w0) {nxt[++cnt] = head[u]; w[cnt] = w0; to[cnt] = v; head[u] = cnt;}
int find(int x) {return x == f[x] ? f[x] : (f[x] = find(f[x]));}
void merge(int x, int y, int w) {
    int hx = find(x), hy = find(y);
    if (hx == hy) {
        return;
    }
    f[hy] = hx;
    add(x, y, w), add(y, x, w);
}
int dep[N];
void dfs(int u, int p) {
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == p) {
            continue;
        }
        dep[v] = dep[u] ^ w[i];
        dfs(v, u);
    }
}
void clear() {
    for (int i = 1; i <= n; i++) {
        f[i] = head[i] = dep[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        x[i] = y[i] = z[i] = pre[i] = 0;
    }
    cnt = n = m = 0;
}
void init() {
    scanf("%d%d", &n, &m);
    m += n - 1;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
        pre[i] = z[i];
        if (z[i] != -1) {
            z[i] = __builtin_popcount(z[i]) & 1;
        }
    }
    for (int i = n; i <= m; i++) {
        scanf("%d%d%d", &x[i], &y[i], &z[i]);
    }
}

void solve() {
    for (int i = 1; i <= m; i++)
        if (z[i] != -1) {
            merge(x[i], y[i], z[i]);
        }
    for (int i = 1; i <= n; i++) {
        dep[i] = -1;
    }
    for (int i = 1; i <= n; i++)
        if (dep[i] == -1) {
            dep[i] = 0, dfs(i, 0);
        }
    bool can = true;
    for (int i = 1; i <= m; i++)
        if (z[i] != -1) {
            if ((dep[x[i]]^dep[y[i]]) != z[i]) {
                can = false;
                break;
            }
        } else {
            z[i] = dep[x[i]] ^ dep[y[i]];
        }
    if (!can) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i < n; i++)
        if (pre[i] != -1) {
            printf("%d %d %d\n", x[i], y[i], pre[i]);
        } else {
            printf("%d %d %d\n", x[i], y[i], z[i]);
        }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        solve();
        clear();
    }
    return 0;
}