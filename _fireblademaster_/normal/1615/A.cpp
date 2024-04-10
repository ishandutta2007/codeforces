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
constexpr int N = 106;
int n, sum = 0;
int a[N];
void init() {
	scanf("%d", &n), sum = 0;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += a[i];
}

void solve() {
	if (sum % n == 0) {
		printf("0\n");
	} else {
		printf("1\n");
	}
}

int main() {
	int t; scanf("%d", &t); while (t--) {
		init();
		solve();
	}
	return 0;
}