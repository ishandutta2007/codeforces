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
constexpr int N = 1000005;
int n;
char s[N];
int a[N];

void init() {
    scanf("%d%s", &n, s + 1);
    for (int i = n, p = 0; i >= 1; --i) {
        a[i] = 0;
        if (s[i] == ')') {
            a[i] = p;
            p = i;
        }
    }
}

void solve() {
    int ans0 = 0, ans1 = 0;
    for (int p = 1; p <= n; ) {
        if (s[p] == '(') {
            if (p == n) break;
            p += 2;
            ans0 += 1, ans1 += 2;
        } else {
            if (!a[p]) break;
            ans0 += 1, ans1 += a[p] - p + 1;
            p = a[p] + 1;
        }
    }
    printf("%d %d\n", ans0, n - ans1);
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