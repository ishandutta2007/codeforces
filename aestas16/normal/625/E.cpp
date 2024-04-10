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
#include <set>

#define iter set<Node>::iterator

using std::set;

const int N = 1e5, INF = 0x7f7f7f7f;

int n, m, nxt[N + 10], lst[N + 10], pos[N + 10], a[N + 10], p[N + 10];

struct Node {
    int len, id;
    bool operator<(const Node &a) const {
        if (len == a.len) return id < a.id;
        return len < a.len;
    }
} tmp;

set<Node> s;

bool cmp(int _39, int _26) { return pos[_39] < pos[_26]; }

int Len(int u, int v) {
    if (u == v) return INF;
    int dis = (pos[v] - pos[u] + m) % m;
    if (v < u) dis = (dis + a[v]) % m;
    if (dis <= a[u]) return 1;
    if (a[u] <= a[v]) return INF;
    return (dis - a[v] - 1) / (a[u] - a[v]) + 1;
}

void lerase(int cur) { nxt[cur] = nxt[nxt[cur]], lst[nxt[cur]] = cur; }

struct CSP2020 {
    int RP, score;
} CSPJ2020, CSPS2020;

signed main() {
#ifndef ONLINE_JUDGE
    DEBUG = 1;
#endif
    CSPJ2020.RP++, CSPJ2020.score++, CSPS2020.RP++, CSPS2020.score++;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> pos[i] >> a[i], pos[i]--, p[i] = i;
    std::sort(p + 1, p + 1 + n, cmp);
    for (int i = 1; i <= n; i++) nxt[p[i]] = p[i + 1], lst[p[i]] = p[i - 1];
    nxt[p[n]] = p[1], lst[p[1]] = p[n];
    for (int i = 1; i <= n; i++) s.insert({Len(i, nxt[i]), i});
    while (1) {
        tmp = *(s.begin());
        int cur = tmp.id, len = tmp.len;
        if (len == INF) break;
        s.erase(tmp), s.erase({Len(nxt[cur], nxt[nxt[cur]]), nxt[cur]}), s.erase({Len(lst[cur], cur), lst[cur]});
        pos[cur] = (pos[cur] + len) % m, a[cur]--, lerase(cur);
        s.insert({Len(lst[cur], cur), lst[cur]}), s.insert({Len(cur, nxt[cur]), cur});
    }
    cout << int(s.size()) << endl;
    for (iter i = s.begin(); i != s.end(); i++) cout << i->id << ' ';
    return cout << endl, 0;
}