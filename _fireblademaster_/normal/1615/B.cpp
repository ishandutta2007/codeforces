#include <bits/stdc++.h>
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
int l, r;
int a[20][200005];
void prepare(int n) {
	for (int i = 0; i < 18; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = a[i][j - 1] + (j >> i & 1);
		}
	}
}

void init() {
	scanf("%d%d", &l, &r);
}

void solve() {
	int ans = 0;
	for (int i = 0; i < 18; ++i) {
		checkmax(ans, a[i][r] - a[i][l - 1]);
	}
	ans = (r - l + 1) - ans;
	printf("%d\n", ans);
}

int main() {
	prepare(200000);
	int t; scanf("%d", &t); while (t--) {
		init();
		solve();
	}
	return 0;
}