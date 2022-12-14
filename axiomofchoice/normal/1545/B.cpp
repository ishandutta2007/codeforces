// #pragma GCC optimize(3)
#include <bits/stdc++.h>

template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
	return o<<'('<<x.first<<','<<x.second<<')';
}
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()

#define repeat(i, a, b) for (int i = (a), ib = (b); i < ib; i++)
#define repeat_back(i, a, b) for (int i = (b) - 1, ib = (a);i >= ib; i--)
#define mst(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define OK { puts("Yes"); return; }
#define GG { puts("No"); return; }
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
		template <typename T> T sqr(const T &x) { return x*x; }
		// int cansel_sync = (ios::sync_with_stdio(0), cin.tie(0), 0);
		template <typename T> void sortunique(vector<T> &a) {
			sort(a.begin(), a.end());
			a.erase(unique(a.begin(), a.end()), a.end());
		}
	const int N = 500010;
	const lf eps = 1e-9;
	const int mod = (0 ? 1000000007 : 998244353);
		int mul(int a, int b, int m = mod) { return 1ll * a * b % m; }
		int qpow(int a, ll b,int m = mod) {
			int ans = 1;
			for (; b; a = mul(a, a, m), b >>= 1) if (b & 1)
				ans = mul(ans, a, m);
			return ans;
		}
} using namespace start;
struct Comb {
	static const int N = 100010;
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
char s[N];
void Solve() {
	int n = read(), cnt0 = 0, cnt1 = 0, pre = 0;
	scanf("%s", s);
	repeat (i, 0, n) {
		if (s[i] == '1') {
			if (pre) cnt1++, pre = 0;
			else pre = 1;
		} else {
			pre = 0;
			cnt0++;
		}
	}
	print(C(cnt0 + cnt1, cnt0), 1);
}
signed main() {
	// freopen("data.txt", "r", stdin);
	int T = 1; T = read();
	repeat (ca, 1, T + 1) {
		Solve();
	}
	return 0;
}