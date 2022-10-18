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

const int N = 1e2;

int a, b, c;
double ansa, ansb, ansc, f[N + 10][N + 10][N + 10];

struct NOIP2020 {
    int RP, score;
} NOIP2020;

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    NOIP2020.RP++, NOIP2020.score++;
    cin >> a >> b >> c, f[a][b][c] = 1;
    for (int i = a; ~i; i--)
        for (int j = b; ~j; j--)
            for (int k = c; ~k; k--) {
                double frac = i * j + j * k + i * k;
                if (i && j) f[i][j - 1][k] += f[i][j][k] * i * j / frac;
                if (j && k) f[i][j][k - 1] += f[i][j][k] * j * k / frac;
                if (i && k) f[i - 1][j][k] += f[i][j][k] * i * k / frac;
            }
    for (int i = 0; i <= a; i++) ansa += f[i][0][0];
    for (int i = 0; i <= b; i++) ansb += f[0][i][0];
    for (int i = 0; i <= c; i++) ansc += f[0][0][i];
    return printf("%.9lf %.9lf %.9lf\n", ansa, ansb, ansc), 0;
}