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
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 400010, mod = 1000000007;
int n, m, rb, cb, rd, cd, p, ip;
int ksm(int a, int b = mod - 2) {
    int r = 1;
    for (; b; b >>= 1, a = 1ll * a * a % mod)
        if (b & 1) {
            r = 1ll * r * a % mod;
        }
    return r;
}
void init() {
    scanf("%d%d%d%d%d%d%d", &n, &m, &rb, &cb, &rd, &cd, &p);
    p = 1ll * p * ksm(100) % mod;
    ip = (mod + 1 - p) % mod;
}

int f[N], ft;
void solve() {
    int tt = 0, x = rb, y = cb, ox = 1, oy = 1;
    if (x == n) {
        ox = -1;
    }
    if (y == m) {
        oy = -1;
    }
    int vx = ox, vy = oy;
    while (true) {
        if (x + vx > n || x + vx <= 0) {
            vx = -vx;
        }
        if (y + vy > m || y + vy <= 0) {
            vy = -vy;
        }
        if (tt && x == rb && y == cb && vx == ox && vy == oy) {
            break;
        }
        if (x == rd || y == cd) {
            f[ft++] = tt;
        }
        x += vx, y += vy, ++tt;
    }
    int ans = 0, ex = ksm(ip, ft);
    for (int i = 0; i < ft; i++) {
        ans = (ans + 1ll * ksm(ip, i) * p % mod * f[i]) % mod;
    }
    ans = (ans + 1ll * ex * tt) % mod;
    ans = 1ll * ans * ksm(1 - ex + mod) % mod;
    printf("%d\n", ans);
}

void clear() {
    memset(f, 0, sizeof(f));
    ft = 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        solve();
        clear();
    }
    return 0;
}