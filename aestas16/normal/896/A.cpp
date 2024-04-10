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

// What are you doing at the end of the world? Are you busy? Will you save us?

#define int long long

const int N = 1e5, K = 1e18;

char qwq[] = " \"?";
char qaq[] = " \"? Are you busy? Will you send \"";
char quq[] = " What are you doing while sending \"";
char qvq[] = " What are you doing at the end of the world? Are you busy? Will you save us?";
int f[N + 10] = {0, 75};

char dfs(int pos, int id) {
    if (id == 1) return qvq[pos];
    if (pos > 34 + f[id - 1] + 32 + f[id - 1]) return qwq[pos - 34 - f[id - 1] - 32 - f[id - 1]];
    if (pos > 34 + f[id - 1] + 32) return dfs(pos - 34 - f[id - 1] - 32, id - 1);
    if (pos > 34 + f[id - 1]) return qaq[pos - 34 - f[id - 1]];
    if (pos > 34) return dfs(pos - 34, id - 1);
    return quq[pos];
}

struct NOIP2020 {
    int RP, score;
} NOIP2020;

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    NOIP2020.RP++, NOIP2020.score++;
    for (int i = 1; i <= N; i++) {
        f[i + 1] = 34 + f[i] + 32 + f[i] + 2;
        if (f[i + 1] > K) f[i + 1] = K;
    }
    // cout << f[20] << endl;
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        if (k > f[n + 1])
            cout << '.';
        else
            cout << dfs(k, n + 1);
    }
    return cout << endl, 0;
}
// What are you doing while sending ""? Are you busy? Will you send ""?