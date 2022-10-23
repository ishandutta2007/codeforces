#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define setIO(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define closefile fclose(stdin), fclose(stdout)
#define m_p make_pair
#define sz(x) (int)x.size()
#define see(x) cerr << x << " "
#define seeln(x) cerr << x << endl
#define out(x) cerr << #x << " = " << x << " "
#define outln(x) cerr << #x << " = " << x << endl
#define outarr(x, l, r) {cerr << #x"[" << l << " ~ " << r << "] = "; for (int _i = l; _i <= r; ++_i) cerr << x[_i] << " "; cerr << endl;}
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define gc() getchar()
//#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;
template <class T> void read(T &x) {
    x = 0;
    int c = gc();
    int flag = 0;
    while (c < '0' || c > '9') {
        flag |= (c == '-'), c = gc();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
    }
    if (flag) {
        x = -x;
    }
}
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}

const int N = 200010, mx = 200000, mod = 998244353;
int fac[N], inv[N];

int ksm(int a, int b = mod - 2) {
    int r = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
        if (b & 1) {
            r = 1ll * r * a % mod;
        }
    return r;
}
int C(int x, int y) {return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;}
void init_c(int n = N - 10) {
    for (int i = fac[0] = 1; i <= n; i++) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    inv[n] = ksm(fac[n]);
    for (int i = n - 1; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    }
}
int a[N], b[N], c[N], n, m;
void add(int &x, int y) {x = (x + y >= mod ? x + y - mod : x + y);}
void dec(int &x, int y) {x = (x - y < 0 ? x - y + mod : x - y);}

namespace sum {
    int t[N];
    void Add(int x, int v) {for (; x <= mx; x += x & -x) add(t[x], v);}
    void Dec(int x, int v) {for (; x <= mx; x += x & -x) dec(t[x], v);}
    int qry(int x) {int v = 0; for (; x; x -= x & -x) add(v, t[x]); return v;}
}

void init() {
    init_c();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
}

void solve() {
    int iv = 1;
    for (int i = 1; i <= n; i++) {
        c[a[i]]++;
    }
    for (int i = 1; i <= mx; i++) {
        iv = 1ll * iv * inv[c[i]] % mod, sum::Add(i, c[i]);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        add(ans, 1ll * fac[n - i]*iv % mod * sum::qry(b[i] - 1) % mod);
        if (c[b[i]] == 0) {
            break;
        }
        iv = 1ll * iv * fac[c[b[i]]] % mod * inv[c[b[i]] - 1] % mod;
        sum::Dec(b[i], c[b[i]]);
        sum::Add(b[i], --c[b[i]]);
        if (i == n && i != m) {
            add(ans, 1);
        }
    }
    printf("%d\n", ans);
}

//#define CASES_WITH_T
int main() {
    int t = 1;
    #ifdef CASES_WITH_T
    scanf("%d", &t);
    #endif
    while (t--) {
        init();
        solve();
    }
    return 0;
}