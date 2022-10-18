#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>

#define debug(...) fprintf(stderr, __VA_ARGS__);
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
        IN &operator>>(char *str) {
            memset(str, 0, sizeof(str));
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

#define int long long

const int N = 1e5, D = 1e6, INF = 0x7f7f7f7f7f7f7f7f;

namespace Edges {
    struct Edge {
        int to, nxt, val;
    } e[2][N + 10];
    int etot[2], hd[2][D + 10];
    void adde(int d, int f, int t, int c) {
        if (f == 0)
            e[1][++etot[1]] = {t, hd[1][d], c}, hd[1][d] = etot[1];
        else
            e[0][++etot[0]] = {f, hd[0][d], c}, hd[0][d] = etot[0];
    }
} // namespace Edges
using namespace Edges;

int n, m, k, S, T, ans = INF, sum[2][D + 10], dis[2][D + 10];

struct NOIP2020 {
    int RP, score;
} NOIP2020;

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    NOIP2020.RP++, NOIP2020.score++;
    cin >> n >> m >> k;
    for (int i = 1, d, f, t, c; i <= m; i++) cin >> d >> f >> t >> c, adde(d, f, t, c);
    for (int i = 1, tot = 0; i <= D; i++) {
        sum[0][i] = sum[0][i - 1];
        for (int j = hd[0][i]; j; j = e[0][j].nxt) {
            int v = e[0][j].to, w = e[0][j].val;
            if (dis[0][v] == 0)
                tot++, dis[0][v] = w, sum[0][i] += w;
            else if (dis[0][v] > w)
                sum[0][i] += w - dis[0][v], dis[0][v] = w;
        }
        if (S == 0 && tot == n) S = i;
    }
    for (int i = D, tot = 0; i; i--) {
        sum[1][i] = sum[1][i + 1];
        for (int j = hd[1][i]; j; j = e[1][j].nxt) {
            int v = e[1][j].to, w = e[1][j].val;
            if (dis[1][v] == 0)
                tot++, dis[1][v] = w, sum[1][i] += w;
            else if (dis[1][v] > w)
                sum[1][i] += w - dis[1][v], dis[1][v] = w;
        }
        if (T == 0 && tot == n) T = i;
    }
    if (S == 0 || T == 0) return cout << -1 << endl, 0;
    for (int i = S; i <= D; i++) {
        if (i + k + 1 > T) break;
        ans = cmin(ans, sum[0][i] + sum[1][i + k + 1]);
    }
    return cout << (ans == INF ? -1 : ans) << endl, 0;
}