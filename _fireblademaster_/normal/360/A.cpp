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
    x = 0; int c = gc(); int flag = 0;
    while (c < '0' || c > '9') flag |= (c == '-'), c = gc();
    while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = gc();
    if (flag) x = -x;
}
template <class T> bool checkmax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template <class T> bool checkmin(T &a, T b) {return b < a ? a = b, 1 : 0;}
const int N = 5005;
int n, q, m = 0;
int a[N];
int lim[N];
int b[N][N];
int l, r, d;
vector<array<int, 4>> E;

void init() {
    scanf("%d%d", &n, &q);
    fill(lim + 1, lim + n + 1, 1000000000);
    for (int i = 1; i <= q; ++i) {
        int op, l, r, d;
        scanf("%d%d%d%d", &op, &l, &r, &d);
        if (op == 1) {
            for (int j = l; j <= r; ++j) a[j] += d;
        } else {
            for (int j = l; j <= r; ++j) checkmin(lim[j], d - a[j]);
        }
        E.push_back({op, l, r, d});
    }
}

void solve() {
    fill(a + 1, a + n + 1, 0);
    for (auto &[op, l, r, d] : E) {
        if (op == 1) {
            for (int j = l; j <= r; ++j) a[j] += d;
        } else {
            bool ok = 0;
            for (int j = l; j <= r; ++j) if (lim[j] + a[j] == d) ok = 1;
            if (!ok) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i <= n; ++i) printf("%d%c", lim[i], " \n"[i == n]);
}

//#define CASES_WITH_T
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