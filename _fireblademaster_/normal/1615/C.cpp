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
const int N = 100005, inf = 0x3f3f3f3f;
int n, A, B;
char s[N], t[N];
void init() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	A = B = 0;
	for (int i = 1; i <= n; ++i) {
		A += s[i] == '0';
		B += t[i] == '0';
	}
}

void solve() {
	if (B != A && B != n - 1 - A) {
		printf("-1\n");
		return;
	}
	int tot = 0;
	for (int i = 1; i <= n; ++i) {
		tot += s[i] != t[i];
	}
	if (tot == 0) {
		printf("0\n");
		return;
	}
	if (A == n) {
		printf("-1\n");
		return;
	}
	int ans = inf;
	if (A == B) {
		checkmin(ans, tot);
	}
	for (int i = 1; i <= n; ++i) {
		s[i] = '1' + '0' - s[i];
	}
	int tmp = 0;
	for (int i = 1; i <= n; ++i) {
		tmp += s[i] != t[i];
	}
	if (A + B == n - 1) {
		for (int i = 1; i <= n; ++i) if (s[i] == '0') {
			int w = tmp - (s[i] != t[i]) + (s[i] == t[i]);
			checkmin(ans, w + 1);
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t); while (t--) {
		init();
		solve();
	}
	return 0;
}