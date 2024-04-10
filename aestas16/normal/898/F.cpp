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

#include <cstring>

#define int long long

const int N = 1e6, BASE = 10, P = 1126654447, INF = 0x7f7f7f7f;

char str[N + 10];
int len, Pow[N + 10] = {1}, sum[N + 10] = {1};

int Hash(int l, int r) {
    if (l > r || l < 0 || r < 0) return -INF;
    return ((sum[r] - (sum[l - 1] * Pow[r - l + 1]) % P) + P) % P;
}

int qwq(int l, int r) { return str[l] != '0' || r - l + 1 < 2; }

int Chk(int l1, int r1, int l2, int r2, int c) {
    return (Hash(l1, r1) + Hash(l2, r2)) % P == c && qwq(l1, r1) && qwq(l2, r2);
}

void Print(int l1, int r1, int l2, int r2) {
    for (int i = l1; i <= r1; i++) cout << str[i];
    cout << '+';
    for (int i = l2; i <= r2; i++) cout << str[i];
    cout << '=';
    for (int i = r2 + 1; i <= len; i++) cout << str[i];
    cout << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    scanf("%s", str + 1), len = strlen(str + 1);
    for (int i = 1; i <= len; i++)
        sum[i] = ((sum[i - 1] * BASE) % P + str[i] - '0') % P, Pow[i] = (Pow[i - 1] * BASE) % P;
    for (int i = len >> 1; i <= len; i++) {
        int n = len - i + 1;
        if (i - n < 0 || qwq(i + 1, n) == 0) continue;
        int c = Hash(i, len);
        if (Chk(1, n - 1, n, i - 1, c)) return Print(1, n - 1, n, i - 1), 0;
        if (Chk(1, n, n + 1, i - 1, c)) return Print(1, n, n + 1, i - 1), 0;
        if (Chk(1, i - n - 1, i - n, i - 1, c)) return Print(1, i - n - 1, i - n, i - 1), 0;
        if (Chk(1, i - n, i - n + 1, i - 1, c)) return Print(1, i - n, i - n + 1, i - 1), 0;
    }
    return 0;
}