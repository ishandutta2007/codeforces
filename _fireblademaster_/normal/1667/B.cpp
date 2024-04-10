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
const int N = 500005;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
int n, m = 0;
ll a[N], b[N];
int c[N];
ll dp[N], t[N];

void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    m = 0;
    for (int i = 0; i <= n; ++i) {
        b[++m] = a[i];
    }
    sort(b + 1, b + m + 1);
    m = unique(b + 1, b + m + 1) - b - 1;
    for (int i = 0; i <= n; ++i) {
        c[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    }
}

struct ctree1 {
    ll C[N];
    void init() {
        fill(C, C + m + 1, -Inf);
    }

    void update(int x, ll v) {
        while (x <= m) {
            checkmax(C[x], v);
            x += x & (-x);
        }
    }

    ll query(int x) {
        ll ans = -Inf;
        while (x) {
            checkmax(ans, C[x]);
            x -= x & (-x);
        }
        return ans;
    }
} t1;

struct ctree2 {
    ll C[N];
    void init() {
        fill(C, C + m + 1, -Inf);
    }

    void update(int x, ll v) {
        while (x) {
            checkmax(C[x], v);
            x -= x & (-x);
        }
    }

    ll query(int x) {
        ll ans = -Inf;
        while (x <= m) {
            checkmax(ans, C[x]);
            x += x & (-x);
        }
        return ans;
    }
} t2;

void solve() {
    fill(dp, dp + n + 1, -Inf);
    fill(t + 1, t + m + 1, -Inf);
    dp[0] = 0;
    t[c[0]] = 0;
    t1.init();
    t2.init();
    t1.update(c[0], 0);
    t2.update(c[0], 0);
    for (int i = 1; i <= n; ++i) {
        /*for (int j = 0; j < i; ++j) {
            if (c[i] > c[j]) {
                checkmax(dp[i], dp[j] - j + i);
            } else if (a[i] == a[j]) {
                checkmax(dp[i], dp[j]);
            } else {
                checkmax(dp[i], dp[j] + j - i);
            }
        }*/
        checkmax(dp[i], t[c[i]]);
        if (c[i] > 1) {
            checkmax(dp[i], t1.query(c[i] - 1) + i);
        }
        if (c[i] < m) {
            checkmax(dp[i], t2.query(c[i] + 1) - i);
        }
        t1.update(c[i], dp[i] - i);
        t2.update(c[i], dp[i] + i);
        checkmax(t[c[i]], dp[i]);
    }
    printf("%lld\n", dp[n]);
}

#define CASES_WITH_T
int main() {
    //setIO("");
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