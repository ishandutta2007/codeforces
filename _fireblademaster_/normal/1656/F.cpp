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

const int N = 1000005;
int n;
ll a[N], b[N], c[N];

void init() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    b[0] = c[0] = 0;
    for (int i = 1; i <= n; ++i) b[i] = b[i - 1] + a[i];
}

void solve() {
    ll ans = -8000000000000000000;
    ll w = (n - 2) * a[n] + b[n];
    if (w < 0) {
        printf("INF\n");
        return;
    }
    checkmax(ans, w * (-a[n]) + a[n] * b[n - 1]);
    w = (n - 2) * a[1] + b[n];
    if (w > 0) {
        printf("INF\n");
        return;
    }
    checkmax(ans, w * (-a[1]) + a[1] * (b[n] - b[1]));
    for (int i = 1; i < n; ++i) {
        //-a[i + 1] <= t <= -a[i]
        ll B = a[n] * i + b[i];
        ll A = a[n] * b[i];
        if (i + 1 <= n - 1) {
            A += (b[n - 1] - b[i]) * a[1];
            B += b[n - 1] - b[i] + a[1] * (n - 1 - i);
        }
        checkmax(ans, B * -a[i] + A);
        checkmax(ans, B * -a[i + 1] + A);
    }
    printf("%lld\n", ans);
    fill(a, a + n + 1, 0);
    fill(b, b + n + 1, 0);
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