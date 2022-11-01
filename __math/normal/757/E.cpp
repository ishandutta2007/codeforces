#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

const int MOD = ten(9) + 7;
const int N = ten(6) + 1;
int factors[N];

void init_factor() {
	for (int i = 2; i < N; i += 2) factors[i] = 2;
	for (int i = 3; i < N; i += 2) factors[i] = i;
	for (int i = 3; i < N; i += 2) if (factors[i] == i)
		for (int j = 3 * i; j < N; j += 2 * i) factors[j] = i;
}

ll f0(int n) {
	int ret = 0;
	while (n != 1) {
		int p = factors[n];
		while (n % p == 0)n /= p;
		ret++;
	}
	return 1LL << ret;
}

ll f(int r, int n) {
	if (r == 0) {
		return f0(n);
	}
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			ret += f(r - 1, i);
		}
	}
	return ret % MOD;
}

int dp[ten(6) + 1][21];
void init() {
	init_factor();
	dp[0][0] = 1;
	FOR(i, 20) dp[0][i + 1] = 2;
	for(int j = 1; j <= ten(6); j++) {
		dp[j][0] = 1;
		for (int k = 0; k <= 20; k++) {
			int tmp = dp[j][k] + dp[j - 1][k + 1];
			if (tmp >= MOD) tmp -= MOD;
			dp[j][k + 1] = tmp;
		}
	}
}

int main() {
	init();

	//FOR(r, 10) {
	//	FOR(i, 20) {
	//		cout << f(r, 1 << i) << " ";
	//	}
	//	cout << endl;
	//}

	int q; reader(q);
	FOR(i, q) {
		int r, n; reader(r, n);

		ll ans = 1;
		while (n != 1) {
			int p = factors[n];
			int cnt = 0;
			while (n % p == 0)n /= p, cnt++;
			ans = ans * dp[r][cnt] % MOD;
		}
		writerLn(ans);
	}

	return 0;
}