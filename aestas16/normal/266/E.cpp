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

#define int long long
#define now seg[cur]
#define ls cur << 1
#define rs cur << 1 | 1
#define lch seg[ls]
#define rch seg[rs]

const int N = 1e5, P = 1e9 + 7;

char opt;
int n, m, l, r, k, a[N + 10], Pow[N + 10][6], tmp[10][10];

struct Node {
    int l, r, ctag, sum[6];
    Node(int l = 0, int r = 0, int ctag = -1) : l(l), r(r), ctag(ctag) {}
} seg[(N << 2) + 10];

int qpow(int a, int b) {
    int ret = 1;
    for (; b; a = a * a % P, b >>= 1) b & 1 ? ret = ret * a % P : 0;
    return ret;
}

void pushup(int cur) {
    for (int i = 0; i <= 5; i++) now.sum[i] = (lch.sum[i] + rch.sum[i]) % P;
}
void revise(int cur, int val) {
    now.ctag = val;
    for (int i = 0; i <= 5; i++) now.sum[i] = val * (Pow[now.r][i] - Pow[now.l - 1][i] + P) % P;
}
void pushdown(int cur) {
    if (now.ctag != -1) revise(ls, now.ctag), revise(rs, now.ctag), now.ctag = -1;
}

void build(int cur, int l, int r) {
    now = Node(l, r, -1);
    if (l == r) {
        for (int i = 0; i <= 5; i++) now.sum[i] = a[l] * qpow(l, i) % P;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid), build(rs, mid + 1, r), pushup(cur);
}

void modify(int cur, int l, int r, int val) {
    if (now.l > r || now.r < l || l > r) return;
    if (now.l >= l && now.r <= r) return revise(cur, val);
    pushdown(cur), modify(ls, l, r, val), modify(rs, l, r, val), pushup(cur);
}
int qsum(int cur, int l, int r, int t) {
    if (now.l > r || now.r < l || l > r) return 0;
    if (now.l >= l && now.r <= r) return now.sum[t];
    int ret = 0;
    pushdown(cur), ret = (ret + qsum(ls, l, r, t)) % P, ret = (ret + qsum(rs, l, r, t)) % P, pushup(cur);
    return ret;
}

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    cin >> n >> m, tmp[0][0] = 1;
    // for (int j = 0; j <= 5; ++j) Pow[0][j] = qpow(0, j);
    for (int i = 1; i <= 5; i++) {
        tmp[i][0] = tmp[i][i] = 1;
        for (int j = 1; j < i; j++) tmp[i][j] = (tmp[i - 1][j] + tmp[i - 1][j - 1]) % P;
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 5; j++) Pow[i][j] = (Pow[i - 1][j] + qpow(i, j)) % P;
    build(1, 1, n);
    while (m--) {
        cin >> opt >> l >> r >> k;
        if (opt == '=')
            modify(1, l, r, k);
        else if (opt == '?') {
            int ans = 0;
            for (int j = 0, temp; j <= k; j++)
                temp = tmp[k][j] * qpow((1 - l + P) % P, k - j) % P * qsum(1, l, r, j) % P, ans = (ans + temp) % P;
            cout << ans << endl;
        }
    }
    return 0;
}