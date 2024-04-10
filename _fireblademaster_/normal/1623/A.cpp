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
int n, m;
int x, y, ex, ey;
void init() {
	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &ex, &ey);
}

void solve() {
	if (x == ex || y == ey) {
		printf("0\n");
		return;
	}
	int dx = 1, dy = 1;
	for (int i = 1; ; ++i) {
		if (x + dx > n) dx = -dx;
		if (x + dx < 1) dx = -dx;
		if (y + dy > m) dy = -dy;
		if (y + dy < 1) dy = -dy;
		x += dx, y += dy;
		if (x == ex || y == ey) {
			printf("%d\n", i);
			return;
		}
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