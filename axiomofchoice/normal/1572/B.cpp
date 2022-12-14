// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)
#define mst(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
// #define int ll
using namespace std;
namespace start {
	typedef long long ll; const int inf = INT_MAX >> 1; const ll INF = INT64_MAX >> 1;
	typedef double lf; const lf pi = acos(-1);
	typedef pair<int, int> pii;
	mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
		ll read() { ll x; if (scanf("%lld", &x) != 1) exit(0); return x; } // will detect EOF
		ll readfast() {
			ll x = 0, tag = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') tag = -1;
			for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; // ungetc(c, stdin);
			return x * tag;
		}
		template <typename T> void write(T x) {
			if (x < 0) x = -x, putchar('-');
			if (x >= 10) write(x / 10);
			putchar(x % 10 + 48);
		}
		void print(ll x, bool e = 0) { printf("%lld%c", x, " \n"[e]); }
		lf readf() { lf x; if (scanf("%lf",&x) != 1) exit(0); return x; } // will detect EOF
		void printlf(lf x, bool e = 0) { printf("%.12f%c", x, " \n"[e]); }
		template <typename T> vector<T> &operator<<(vector<T> &a, const T &b) { a.push_back(b); return a; }
		template <typename T> T sqr(const T &x) { return x * x; }
		// int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
		template <typename T> void sortunique(vector<T> &a) {
			sort(a.begin(), a.end());
			a.erase(unique(a.begin(), a.end()), a.end());
		}
	const int N = 600010;
	const lf eps = 1e-9;
	const int mod = (1 ? 1000000007 : 998244353);
		// ll D(ll x) { return x >= mod ? x - mod : x; }
		int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
		int qpow(int a, ll b, int m = mod) {
			int ans = 1;
			for (; b; a = mul(a, a, m), b >>= 1) if (b & 1)
				ans = mul(ans, a, m);
			return ans;
		}
} using namespace start;
#define OK { puts("Yes"); return; }
#define GG { puts("NO"); return; }
#define debug 1
int a[N];
void Solve() {
	int n = read();
	repeat (i, 0, n) { a[i] = read(); } a[n] = 0;
	int sum = accumulate(a, a + n, 0);
	if (sum % 2 == 1 || sum == n) GG;
	vector<int> ans;
	auto work = [&ans](int x) {
		int t = a[x] ^ a[x + 1] ^ a[x + 2];
		a[x] = a[x + 1] = a[x + 2] = t;
		ans << (x + 1);
	};
	if (a[0]) {
		int p = 0;
		while (1) {
			if (p == n - 1) {
				break;
			} else if (a[p + 1] == 1) {
				p++;
			} else if (p % 2 != 0) {
				for (int i = p - 1; i >= 0; i -= 2)
					work(i);
				break;
			} else if (a[p + 2] == 1) {
				work(p);
				p--;
			} else {
				work(p);
			}
		}
	}
	if (a[0]) GG;
	int p = 0;
	while (p < n) {
		if (a[p + 1] == 0) {
			p++;
		} else if (a[p + 2]) {
			work(p);
		} else {
			work(p + 1);
		}
	}
	puts("YES");
	print(ans.size(), 1);
	for (auto i : ans) print(i, 0);
	puts("");
}
signed main() {
	// freopen("data.txt", "r", stdin);
	int T = 1; T = read();
	repeat (ca, 1, T + 1) {
		Solve();
	}
	return 0;
}