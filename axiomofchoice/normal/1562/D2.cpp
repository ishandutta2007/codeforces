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
#define GG { puts("No"); return; }
#define debug 1
char str[N];
int s[N] = { N / 2 };
vector<int> a[2][N];
void Solve() {
	int n = read(), q = read();
	repeat (i, -n, n + 1) {
		a[0][i + N / 2].clear();
		a[1][i + N / 2].clear();
	}
	scanf("%s", str + 1);
	repeat (i, 1, n + 1) {
		if ((str[i] == '+') ^ (i % 2))
			s[i] = s[i - 1] + 1;
		else
			s[i] = s[i - 1] - 1;
		a[(str[i] == '+') ^ (i % 2)][s[i - 1]].push_back(i);
	}
//	repeat (i, -n, n + 1) orz(a[0][i + N / 2]);
//	repeat (i, -n, n + 1) orz(a[1][i + N / 2]);
	while (q--) {
		int l = read(), r = read();
		if (s[l - 1] == s[r]) {
			puts("0");
			continue;
		}
		if ((r - l + 1) % 2 == 1) {
			puts("1");
			if (s[l - 1] < s[r]) {
				int h = (s[l - 1] + s[r]) / 2;
				int pos = lower_bound(a[1][h].begin(), a[1][h].end(), l) - a[1][h].begin();
				if (pos < (int)a[1][h].size()
					&& a[1][h][pos] <= r) {
					printf("%d\n", a[1][h][pos]);
				}
			} else {
				int h = (s[l - 1] + s[r] + 1) / 2;
				int pos = lower_bound(a[0][h].begin(), a[0][h].end(), l) - a[0][h].begin();
				if (pos < (int)a[0][h].size()
					&& a[0][h][pos] <= r) {
					printf("%d\n", a[0][h][pos]);
				}
			}
		} else {
			puts("2"); r--;
			if (s[l - 1] < s[r]) {
				int h = (s[l - 1] + s[r]) / 2;
				int pos = lower_bound(a[1][h].begin(), a[1][h].end(), l) - a[1][h].begin();
				if (pos < (int)a[1][h].size()
					&& a[1][h][pos] <= r) {
					printf("%d %d\n", a[1][h][pos], r + 1);
				}
			} else {
				int h = (s[l - 1] + s[r] + 1) / 2;
				int pos = lower_bound(a[0][h].begin(), a[0][h].end(), l) - a[0][h].begin();
				if (pos < (int)a[0][h].size()
					&& a[0][h][pos] <= r) {
					printf("%d %d\n", a[0][h][pos], r + 1);
				}
			}
		}
	}
}
signed main() {
	// freopen("data.txt", "r", stdin);
	int T = 1; T = read();
	repeat (ca, 1, T + 1) {
		Solve();
	}
	return 0;
}