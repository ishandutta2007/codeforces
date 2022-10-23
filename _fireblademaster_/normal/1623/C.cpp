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
constexpr int N = 200005;
int n;
int a[N];
ll b[N], c[N];

void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
}

bool check(int lim) {
	for (int i = 1; i <= n; ++i) c[i] = 0;
	for (int i = n; i >= 1; --i) {
		if (a[i] + c[i] < lim) return 0;
		if (i >= 3) {
			ll w = min((ll)a[i], (ll)a[i] + c[i] - lim) / 3;
			c[i - 2] += w * 2;
			c[i - 1] += w;
		}
	}
	return 1;
}

void solve() {
	int l = 0, r = 1000000000, mid, best = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) best = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", best);
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