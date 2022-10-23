#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
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
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x) {
    x = 0;
    int c = gc();
    int flag = 0;
    while (c < '0' || c > '9') {
        flag |= (c == '-'), c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
    }
    if (flag) {
        x = -x;
    }
}
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}

const int N = 200010, mod = 998244353;
int n;
typedef map<int, int> fac;
int pre[N];
fac factor(int x) {
    fac a;
    while (x > 1) {
        a[pre[x]]++, x /= pre[x];
    }
    return a;
}
int ksm(int a, int b = mod - 2) {
    int r = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
        if (b & 1) {
            r = 1ll * r * a % mod;
        }
    return r;
}
void mul(fac &a, const fac &b) {for (auto [v, w] : b) a[v] += w;}
void add(fac &a, const fac &b) {for (auto [v, w] : b) a[v] = max(a[v], w);}
void div(fac &a, const fac &b) {
    for (auto [v, w] : b)
        if (a.count(v)) {
            if (a[v] < w) {
                a.erase(v);
            } else {
                a[v] -= w;
            }
        }
}
int siz[N], son[N], soni[N];
int nxt[N << 1], to[N << 1], wx[N << 1], wy[N << 1], head[N], cnt;
void add(int u, int v, int x, int y) {nxt[++cnt] = head[u]; to[cnt] = v; wx[cnt] = x, wy[cnt] = y; head[u] = cnt;}
void dfs0(int u, int p) {
    siz[u] = 1;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == p) {
            continue;
        }
        dfs0(v, u), siz[u] += siz[v];
        if (siz[son[u]] < siz[v]) {
            son[u] = v, soni[u] = i;
        }
    }
}
fac f[N];
void dfs1(int u, int p) {
    if (son[u]) {
        dfs1(son[u], u), f[u].swap(f[son[u]]);
        mul(f[u], factor(wx[soni[u]]));
        div(f[u], factor(wy[soni[u]]));
    }
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == p || v == son[u]) {
            continue;
        }
        dfs1(v, u);
        mul(f[v], factor(wx[i]));
        div(f[v], factor(wy[i]));
        add(f[u], f[v]);
    }
}

int ans = 0;

void dfs2(int u, int p, int w) {
    ans = (ans + w) % mod;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == p) {
            continue;
        }
        dfs2(v, u, 1ll * w * wy[i] % mod * ksm(wx[i]) % mod);
    }
}

void init() {
    scanf("%d", &n);
    for (int i = 1, u, v, x, y; i < n; i++) {
        scanf("%d%d%d%d", &u, &v, &x, &y);
        add(u, v, x, y), add(v, u, y, x);
    }
    for (int i = 2; i <= n; i++)
        if (!pre[i]) {
            pre[i] = i;
            for (int j = 2; 1ll * i * j <= n; j++)
                if (!pre[i * j]) {
                    pre[i * j] = i;
                }
        }
}

void solve() {
    dfs0(1, 0);
    dfs1(1, 0);
    int res = 1;
    for (auto [v, w] : f[1]) {
        res = 1ll * res * ksm(v, w) % mod;
    }
    dfs2(1, 0, res);
    printf("%d\n", ans);
}
void clear() {
    for (int i = 1; i <= n; i++) {
        head[i] = 0;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        f[i].clear(), siz[i] = son[i] = soni[i] = pre[i] = 0;
    }
    ans = 0;
}

#define CASES_WITH_T
int main() {
    int t = 1;
    #ifdef CASES_WITH_T
    scanf("%d", &t);
    #endif
    while (t--) {
        init();
        solve();
        clear();
    }
    return 0;
}