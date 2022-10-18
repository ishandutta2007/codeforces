#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Debug if (DEBUG)

#ifdef ONLINE_JUDGE
#define getchar() (_S == _T && (_T = (_S = _B) + fread(_B, 1, 1 << 15, stdin), _S == _T) ? EOF : *_S++)
#endif
#define putchar(c) (_P == _Q && (fwrite(_O, 1, 1 << 15, stdout), _P = _O), *_P++ = c)

using std::string;

namespace Template {
    char _B[1 << 15], *_S = _B, *_T = _B, _O[1 << 15], *_P = _O, *_Q = _O + (1 << 15);
    struct IN {
        template <class T> void fr(T &a) {
            register char ch = getchar();
            int w = 1;
            for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? w = -1 : 0;
            for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
            a = w * a;
        }
        IN &operator>>(long long &x) { return fr(x), *this; }
        IN &operator>>(signed &x) { return fr(x), *this; }
        IN &operator>>(unsigned &x) { return fr(x), *this; }
        IN &operator>>(char &c) {
            while (isspace(c = getchar())) {}
            return *this;
        }
        IN &operator>>(char *str) {
            memset(str, 0, sizeof(str) + 2);
            char ch;
            int tot = 0;
            while (isspace(ch = getchar())) {}
            str[tot++] = ch;
            while (!isspace(ch = getchar())) str[tot++] = ch;
            return *this;
        }
        IN &operator>>(string &str) {
            char ch;
            while (isspace(ch = getchar())) {}
            str = ch;
            while (!isspace(ch = getchar())) str += ch;
            return *this;
        }
    } cin;
    struct OUT {
        ~OUT() { fwrite(_O, 1, _P - _O, stdout); }
        template <class T> void fw(T x) {
            register int tot = 0;
            register char TMP[20];
            if (x == 0) return (void)(putchar('0'));
            if (x < 0) putchar('-'), x = -x;
            while (x) TMP[++tot] = x % 10 + '0', x /= 10;
            for (; tot; tot--) putchar(TMP[tot]);
        }
        OUT &operator<<(char c) { return putchar(c), *this; }
        OUT &operator<<(char *str) {
            int len = strlen(str);
            for (int i = 0; i < len; i++) putchar(str[i]);
            return *this;
        }
        OUT &operator<<(string str) {
            int len = str.length();
            for (int i = 0; i < len; i++) putchar(str[i]);
            return *this;
        }
        OUT &operator<<(long long x) { return fw(x), *this; }
        OUT &operator<<(signed x) { return fw(x), *this; }
        OUT &operator<<(unsigned x) { return fw(x), *this; }
    } cout;
    char endl = '\n', DEBUG = 0;
    template <class T> T cmin(T a, T b) { return a < b ? a : b; }
    template <class T> T cmax(T a, T b) { return a > b ? a : b; }
    template <class T> void cswp(T &a, T &b) {
        T t = a;
        a = b, b = t;
    }
} // namespace Template
using namespace Template;

#include <algorithm>
#include <queue>

#define int long long

using std::pair;
using std::priority_queue;

const int N = 70, N2 = (N >> 2) + 1, M = 2e2, INF = 0x3f3f3f3f3f3f3f3f;

int n, m, a, b, btot, itot, ans[N + 10], sz[N + 10], blo[N + 10], bloid[N + 10], id[N + 10], dis[(1 << N2) + 10][N + 10];
bool vis[(1 << N2) + 10][N + 10];

priority_queue<pair<int, pair<int, int> /**/> /**/> q;

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[(M << 1) + 10];
    int etot, hd[N + 10];
    void adde(int u, int v, int w) { e[++etot] = {v, hd[u], w}, hd[u] = etot; }
} // namespace Edges
using namespace Edges;

void dfs(int u, int idx) {
    blo[u] = idx, sz[idx]++;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to, w = e[i].val;
        if (blo[v]) continue;
        if (w == a) dfs(v, idx);
    }
}

struct CSP2020 {
    int RP, score;
} CSPJ2020, CSPS2020;

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    CSPJ2020.RP++, CSPJ2020.score++, CSPS2020.RP++, CSPS2020.score++;
    cin >> n >> m >> a >> b;
    for (int i = 1, u, v, w; i <= m; i++) cin >> u >> v >> w, adde(u, v, w), adde(v, u, w);
    for (int i = 1; i <= n; i++)
        if (blo[i] == 0) btot++, dfs(i, btot);
    for (int i = 1; i <= btot; ++i)
        if (sz[i] >= 4)
            bloid[i] = itot, itot++;
        else
            bloid[i] = -1;
    for (int i = 1; i <= n; i++) id[i] = bloid[blo[i]];
    memset(dis, 0x3f, sizeof(dis)), memset(ans, 0x3f, sizeof(ans));
    if (id[1] == -1)
        dis[0][1] = 0, q.push({0, {0, 1}});
    else
        dis[1 << id[1]][1] = 0, q.push({0, {1 << id[1], 1}});
    while (q.size()) {
        int sta = q.top().second.first, u = q.top().second.second;
        q.pop();
        if (vis[sta][u]) continue;
        vis[sta][u] = 1;
        if (ans[u] == INF) ans[u] = dis[sta][u];
        for (int i = hd[u]; i; i = e[i].nxt) {
            int nsta = sta, v = e[i].to, w = e[i].val;
            if (id[v] != -1) nsta |= 1 << id[v];
            if (((id[v] != -1 && nsta == sta) || (blo[u] == blo[v])) && w == b) continue;
            if (dis[sta][u] + w < dis[nsta][v]) q.push({-(dis[nsta][v] = dis[sta][u] + w), {nsta, v}});
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return cout << endl, 0;
}