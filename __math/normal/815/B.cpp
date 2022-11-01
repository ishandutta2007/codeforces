#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

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
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

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
template<class T> T CRT(T m1, T r1, T m2, T r2) { T a1, a2; extgcd(m1, m2, a1, a2); T ret = (m1*a1*r2 + m2*a2*r1) % (m1*m2); return ret < 0 ? ret + m1 * m2 : ret; }

const int MOD = ten(9) + 7;

const int N = ten(6);
ll inverse[N];
void init_inverse() {
	/*
	M%i = M - (M/i) * i
	(M%i)*i^-1 = M*i^-1 - M/i (mod M)
	(M%i)*i^-1 = M-M/i(mod M)
	i^-1 = (M-M/i) * (M%i)^-1
	*/
	inverse[1] = 1;
	for (int i = 2; i < N; i++) inverse[i] = (MOD - MOD / i) * inverse[MOD%i] % MOD;
}

ll fact[N], infact[N];
void init_fast_fact() {
	init_inverse();
	fact[0] = fact[1] = 1;
	for (int i = 2; i < N; i++) fact[i] = fact[i - 1] * i % MOD;
	infact[0] = infact[1] = 1;
	for (int i = 2; i < N; i++) infact[i] = infact[i - 1] * inverse[i] % MOD;
}

ll fast_nCk(int n, int k) {
	if (n < 0 || k < 0) return 0;
	if (k > n) return 0;
	ll ret = fact[n] * infact[k] % MOD * infact[n - k] % MOD;
	return ret;
}

ll add(ll a, ll b) {
	a += b;
	return a % MOD;
}
ll a[ten(5) * 2];

int main() {
	init_fast_fact();

	int n; reader(n);
	FOR(i, n) reader(a[i]);
	if (n != 1 && n % 2 == 1) {
		static ll b[ten(5) * 2];
		FOR(i, n - 1) {
			if (i % 2 == 0) {
				b[i] = add(a[i], a[i + 1]);
			} else {
				b[i] = add(a[i], -a[i + 1]);
			}
		}
		memcpy(a, b, sizeof(b));
		n--;
	}
	ll ans = 0;
	if (n > 1) {
		int sign = n % 4  == 0 ? -1 : 1;
		FOR(i, n / 2) {
			ll cmb = fast_nCk(n / 2 - 1, i);
			ll tmp = (a[i * 2] + sign * a[i * 2 + 1]) * cmb % MOD;
			ans = (ans + tmp) % MOD;
		}
	} else {
		ans = a[0];
	}

	ans = (ans % MOD + MOD) % MOD;
	writerLn(ans);


	return 0;
}