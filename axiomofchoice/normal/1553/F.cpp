// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)
#define mst(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define int ll
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
		template <typename T> T sqr(const T &x) { return x*x; }
		// int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
		template <typename T> void sortunique(vector<T> &a) {
			sort(a.begin(), a.end());
			a.erase(unique(a.begin(), a.end()), a.end());
		}
	const int N = 600010;
	const lf eps = 1e-9;
	const int mod = (1 ? 1000000007 : 998244353);
		ll D(ll x){return x>=mod?x-mod:x;}
		int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
		int qpow(int a, ll b, int m = mod) {
			int ans = 1;
			for (; b; a = mul(a, a, m), b >>= 1) if (b & 1)
				ans = mul(ans, a, m);
			return ans;
		}
	struct Comb {
		static const int N = 1000010;
		int fac[N], inv[N];
		Comb() {
			fac[0] = 1;
			repeat (i, 1, N)
				fac[i] = 1ll * fac[i - 1] * i % mod;
			inv[N - 1] = qpow(fac[N - 1], mod - 2, mod);
			repeat_back (i, 1, N)
				inv[i - 1] = 1ll * inv[i] * i % mod;
		}
		int operator()(int a, int b) { // a >= b
			if (a < b || b < 0) return 0;
			return 1ll * fac[a] * inv[a - b] % mod * inv[b] % mod;
		}
		int A(int a, int b) { // a >= b
			if (a < b || b < 0) return 0;
			return 1ll * fac[a] * inv[a - b] % mod;
		}
	} C;
	template<int a>
	struct Pow {
		int p[N];
		Pow() {
			p[0] = 0;
			repeat (i, 1, N) p[i] = 1ll * p[i - 1] * a % mod;
		}
		int operator[](int n) { return p[n]; }
	};
} using namespace start;
#define OK { puts("Yes"); return; }
#define GG { puts("No"); return; }
#define debug if (1)
struct zkw {
	const ll a0 = 0;
	int n; ll a[N * 4];
	void init(int inn, ll in[] = nullptr) { // A[x] = a0 or in[x]
		n = 1; while (n < inn) n <<= 1;
		fill(a + n, a + n * 2, a0);
		if (in) repeat (i, 0, inn) a[n + i] = in[i];
		repeat_back (i, 1, n) up(i);
	}
	void up(int x) { // private
		a[x] = a[x * 2] + a[x * 2 + 1];
	}
	void add(int x) { // A[x] += k
		x += n;
		a[x] += 1;
		while (x >>= 1) up(x);
	}
	ll sum(int l, int r) { // U(A[l, r])
		ll ans = a0; l += n - 1, r += n + 1;
		while (l + 1 < r){
			if (~l & 1) ans = (ans + a[l + 1]);
			if ( r & 1) ans = (ans + a[r - 1]);
			l >>= 1, r >>= 1;
		}
		return ans;
	}
} zkw;

struct zkw2 {
	const ll a0 = 0;
	int n; ll a[N * 4];
	void init(int inn, ll in[] = nullptr) { // A[x] = a0 or in[x]
		n = 1; while (n < inn) n <<= 1;
		fill(a + n, a + n * 2, a0);
		if (in) repeat (i, 0, inn) a[n + i] = in[i];
		repeat_back (i, 1, n) up(i);
	}
	void up(int x) { // private
		a[x] = a[x * 2] + a[x * 2 + 1];
	}
	void add(int x, ll k) { // A[x] += k
		x += n;
		a[x] += k;
		while (x >>= 1) up(x);
	}
	ll sum(int l, int r) { // U(A[l, r])
		ll ans = a0; l += n - 1, r += n + 1;
		while (l + 1 < r){
			if (~l & 1) ans = (ans + a[l + 1]);
			if ( r & 1) ans = (ans + a[r - 1]);
			l >>= 1, r >>= 1;
		}
		return ans;
	}
} tr;

int ans[N];
void Solve() {
	int n = read();
	zkw.init(300000); tr.init(300000);
	ll sum = 0;
	repeat (i, 0, n) {
		int x = read(); sum += x;
		zkw.add(x);
		if (i) ans[i] = ans[i - 1]; 
		ans[i] += sum;
		ans[i] += x * i - tr.sum(0, x);
		for (int j = x; j <= 300000; j += x) {
			// orz(j, j + x - 1);
			// cout << tr.qb(j, j + x - 1) << endl; pause;
			ans[i] -= zkw.sum(j, min(300000ll, j + x - 1)) * j;
			tr.add(j, j / x * x);
			tr.add(min(300000ll, j + x - 1) + 1, -j / x * x);
		}
		print(ans[i], i == n - 1);
	}
}
signed main() {
	// freopen("data.txt", "r", stdin);
	int T = 1; // T = read();
	repeat (ca, 1, T + 1) {
		Solve();
	}
	return 0;
}