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

const int N = 2e5, INF = 0x7f7f7f7f;

int n, tot, ans[N + 10];

struct Operation {
    int opt, x;
} op[N + 10];

namespace Heap {
    bool cmp(int _39, int _26) { return _39 > _26; }
    template <class T> struct heap {
        T h[N + 10];
        int sz;
        void push(T x) { h[++sz] = x, std::push_heap(h + 1, h + sz + 1, cmp); }
        void pop() { std::pop_heap(h + 1, h + sz + 1, cmp), sz--; }
        T top() { return h[1]; }
        int size() { return sz; }
        int empty() { return sz == 0; }
    };
} // namespace Heap
using namespace Heap;
heap<int> q;

struct CSP2020 {
    int RP, score;
} CSPJ2020, CSPS2020;

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    CSPJ2020.RP++, CSPJ2020.score++, CSPS2020.RP++, CSPS2020.score++;
    cin >> n;
    for (int i = 1, x; i <= n << 1; i++) {
        char opt;
        cin >> opt;
        if (opt == '+')
            op[i].opt = 1;
        else
            cin >> x, op[i] = {0, x};
    }
    for (int i = n << 1; i; i--) {
        int opt = op[i].opt, x = op[i].x;
        if (opt == 0) {
            if (q.empty())
                q.push(x);
            else {
                int Min = q.top();
                if (x >= Min) return cout << "NO" << endl, 0;
                q.push(x);
            }
        } else {
            if (q.empty()) return cout << "NO" << endl, 0;
            ans[++tot] = q.top(), q.pop();
        }
    }
    cout << "YES" << endl;
    for (int i = tot; i; i--) cout << ans[i] << ' ';
    return cout << endl, 0;
}