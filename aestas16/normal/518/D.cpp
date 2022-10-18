#include <cctype>
#include <cstdio>
#include <string>

#define debug(...) fprintf(stderr, __VA_ARGS__);
#define Debug if (DEBUG)

using std::string;

namespace Template {
    struct IN {
        template <class T> void fr(T &a) {
            T s = 0;
            int w = 1;
            char ch = getchar();
            while (ch < '0' || ch > '9') {
                ch == '-' ? w = -1 : 0;
                ch = getchar();
            }
            while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
            a = w * s;
        }
        IN &operator>>(long long &x) { return fr(x), *this; }
        IN &operator>>(signed &x) { return fr(x), *this; }
        IN &operator>>(unsigned &x) { return fr(x), *this; }
        IN &operator>>(char &c) {
            while (isspace(c = getchar())) {}
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
        OUT &operator<<(char c) { return putchar(c), *this; }
        OUT &operator<<(string str) {
            int len = str.length();
            for (int i = 0; i < len; i++) putchar(str[i]);
            return *this;
        }
        OUT &operator<<(long long x) { return printf("%lld", x), *this; }
        OUT &operator<<(signed x) { return printf("%d", x), *this; }
        OUT &operator<<(unsigned x) { return printf("%u", x), *this; }
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

const int N = 2e3;

int n, t;
double p, f[N + 10][N + 10];

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    cin >> n, scanf("%lf", &p), cin >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= t; j++) f[i][j] = (1 - p) * f[i][j - 1] + p * (f[i - 1][j - 1] + 1);
    return !printf("%.7lf\n", f[n][t]);
}