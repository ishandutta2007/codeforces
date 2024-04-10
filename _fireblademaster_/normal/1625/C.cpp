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
const int N = 505;
const ll Inf = 0x3f3f3f3f3f3f3f3f;
int n, l, k;
int d[N], a[N];
void init() {
	scanf("%d%d%d", &n, &l, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
	}
	d[n + 1] = l;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
}

void solve() {
	vector<vector<ll>> dp(n + 2, vector<ll>(k + 1, Inf));
	dp[1][0] = 0;
	for (int i = 1; i <= n; ++i) {
		vector<vector<ll>> aux(n + 2, vector<ll>(k + 1, Inf));
		for (int j = 1; j <= i; ++j) {
			for (int t = 0; t <= k; ++t) {
				if (dp[j][t] < Inf) {
					ll w = (ll)a[j] * (d[i + 1] - d[i]);
					checkmin(aux[i + 1][t], dp[j][t] + w);
					if (t < k) checkmin(aux[j][t + 1], dp[j][t] + w);
				}
			}
		}
		dp = aux;
	}
	ll ans = Inf;
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 0; j <= k; ++j) {
			checkmin(ans, dp[i][j]);
		}
	}
	printf("%lld\n", ans);
}

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