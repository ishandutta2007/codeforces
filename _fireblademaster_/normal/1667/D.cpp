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

const int N = 200010;
vector<int>g[N];
int f[N], ex[N], n;
void dfs(int u, int p) {
    if (p && g[u].size() == 1) {
        f[u] = 0;
        return;
    }
    int c0 = 0, c1 = 0;
    for (int v : g[u])
        if (v != p) {
            dfs(v, u);
            if (f[v] == -1) {
                f[u] = -1;
                return;
            }
            if (f[v] == 0) {
                c0++;
            } else {
                c1++;
            }
        }
    if (!p) {
        if (c0 == 1) {
            f[u] = 0;
        } else {
            f[u] = -1;
        }
        return;
    }
    if (c0 == c1 - 1 || c0 == c1) {
        f[u] = 0;
        return;
    }
    if (c0 == c1 + 1 || c0 == c1 + 2) {
        f[u] = 1;
        return;
    }
    f[u] = -1;
}
void make(int u, int p) {
    if (!p) {
        make(g[u][0], u);
        printf("%d %d\n", g[u][0], u);
        return;
    }
    int d = g[u].size();
    for (int v : g[u])
        if (v != p) {
            make(v, u);
        }
    static vector<int>t[2];
    t[0].clear(), t[1].clear();
    for (int v : g[u])
        if (v != p)
        { t[f[v]].push_back(v); }
    if (f[u] == 1)
    { ex[u] = t[0].back(), t[0].pop_back(); }
    int w = (g[u].size() + 1) & 1, q[2] = {0, 0};
    for (int i = 0; q[w] < t[w].size(); i++) {
        int v = t[w][q[w]++];
        printf("%d %d\n", u, v);
        w = !w;
    }
}
void init() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y), g[y].push_back(x);
    }
}

void solve() {
    int rt = 1;
    while (g[rt].size() != 1) {
        rt++;
    }
    dfs(rt, 0);
    if (f[rt] == -1) {
        puts("NO");
        return;
    }
    puts("YES");
    make(rt, 0);
    for (int i = 1; i <= n; i++)
        if (ex[i]) {
            printf("%d %d\n", i, ex[i]);
        }
}

void clear() {
    for (int i = 1; i <= n; i++) {
        g[i].clear(), f[i] = ex[i] = 0;
    }
}

#define CASES_WITH_T
int main() {
    //setIO("");
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