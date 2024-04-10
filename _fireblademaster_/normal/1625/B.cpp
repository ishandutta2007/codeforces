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
int n;
void init() {
	scanf("%d", &n);
}

void solve() {
	map<int, int> Map;
	int ans = -1;
	for (int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		if (Map.count(x)) {
			checkmax(ans, n - i + Map[x]);
		}
		Map[x] = i;
	}
	printf("%d\n", ans);
}

#define CASES_WITH_T
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