#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>
 
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define Debug if (DEBUG)
 
#define putchar(c) (_P == _Q && (fwrite(_O, 1, 1 << 15, stdout), _P = _O), *_P++ = c)
 
using std::string;
 
namespace Template {
    char _O[1 << 15], *_P = _O, *_Q = _O + (1 << 15);
    struct IN {
        template <class T> void fr(T &a) {
            char ch = getchar();
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
        IN &operator>>(char *str) { return scanf("%s", str), *this; }
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
            int tot = 0;
            char TMP[20];
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
 
const int N = 1e3;
 
int n, rt, val, tot, tmp, mid, qaq = 1, sz[N + 10], Max[N + 10], dep[N + 10];
 
struct Node {
    int id, sz;
    bool operator<(const Node &a) const { return sz < a.sz; }
} qwq[N + 10];
 
namespace Edges {
    struct Edge {
        int to, nxt;
    } e[(N << 1) + 10];
    int hd[N + 10], etot;
    void adde(int x, int y) { e[++etot] = {y, hd[x]}, hd[x] = etot; }
} // namespace Edges
using namespace Edges;
 
void dfs1(int u, int fa) {
    sz[u] = 1;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
        dfs1(v, u), sz[u] += sz[v], Max[u] = cmax(Max[u], sz[v]);
    }
}
 
void dfs2(int u, int fa) {
    dep[u] = (val += qaq);
    cout << u << ' ' << fa << ' ' << dep[u] - dep[fa] << endl;
    for (int i = hd[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (v == fa) continue;
        dfs2(v, u);
    }
}
 
struct NOIP2020 {
    int RP, score;
} NOIP2020;
 
signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    NOIP2020.RP++, NOIP2020.score++;
    cin >> n;
    for (int i = 1, u, v; i < n; i++) cin >> u >> v, adde(u, v), adde(v, u);
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) {
        Max[i] = cmax(Max[i], sz[1] - sz[i]);
        if (Max[i] <= n >> 1) rt = i;
    }
    dfs1(rt, 0);
    for (int i = hd[rt]; i; i = e[i].nxt) {
        int v = e[i].to;
        qwq[++tot] = {v, sz[v]};
    }
    std::sort(qwq + 1, qwq + 1 + tot);
    for (int i = 1; i <= tot; i++) {
        if (tmp + qwq[i].sz > (n - 1) / 2) {
            mid = i;
            if (n - 1 < qwq[i].sz + (tmp << 1)) mid--;
            break;
        }
        tmp += qwq[i].sz;
    }
    for (int i = 1; i <= mid; i++) dfs2(qwq[i].id, rt);
    qaq = val + 1, val = 0;
    for (int i = mid + 1; i <= tot; i++) dfs2(qwq[i].id, rt);
    return 0;
}