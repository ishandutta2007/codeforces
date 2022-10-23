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
constexpr int N = 1005;
int n;
struct node {
	int l, r, v;
}a[N];

void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].l, &a[i].r);
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		int l = a[i].l, r = a[i].r;
		if (l == r) {
			a[i].v = l;
			continue;
		}
		int mx = l - 1, mn = r + 1;
		for (int j = 1; j <= n; ++j) if (j != i) {
			if (a[j].l == l && a[j].r < r) {
				checkmax(mx, a[j].r);
			}
			if (a[j].r == r && a[j].l > l) {
				checkmin(mn, a[j].l);
			}
		}
		if (mx != l - 1) a[i].v = mx + 1;
		else if (mn != r + 1) a[i].v = mn - 1;
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d %d %d\n", a[i].l, a[i].r, a[i].v);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		init();
		solve();
	}
	return 0;
}