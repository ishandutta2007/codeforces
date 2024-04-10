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
ll mod_inv(ll a, ll m) { ll x, y; extgcd<ll>(a, m, x, y); return (m + x % m) % m; }

const int MOD = ten(9) + 7;

void fwt(ll* v, int size) {
	if (size == 1) return;
	int s2 = size / 2;
	fwt(v, s2);
	fwt(v + s2, s2);
	FOR(i, s2) {
		ll A = v[i];
		ll B = v[i + s2];
		v[i] = (A + B) % MOD;
		v[i + s2] = (A - B) % MOD;
	}
}

void ifwt(ll* v, int size) {
	if (size == 1) return;
	int s2 = size / 2;
	ifwt(v, s2);
	ifwt(v + s2, s2);
	FOR(i, s2) {
		ll A = v[i];
		ll B = v[i + s2];
		v[i] = (A + B) * ((MOD + 1) / 2) % MOD;
		v[i + s2] = (A - B) * ((MOD + 1) / 2) % MOD;
	}
}

void xor_part(vector<ll>& a, vector<ll>& ret) {
	ret = a;
	fwt(ret.data(), sz(ret));
	FOR(i, sz(ret)) (ret[i] *= ret[i]) %= MOD;
	ifwt(ret.data(), sz(ret));
}

const int N = 17;
const int C = 1 << N;

void or_part(vector<ll>& a, vector<ll>& ret) {
	ret.resize(sz(a));
	FOR(i, C) {
		if (a[i] == 0) continue;
		int base = (C - 1) ^ i;
		int x = base;
		do {
			ret[i^x] += a[i] * a[x];
			x = (x - 1) & base;
		}
		while (x != base);
	}
}

ll fib[C + 10];
void init() {
	fib[1] = 1;
	FOR(i, C) {
		ll nt = fib[i] + fib[i + 1];
		if (nt >= MOD) nt -= MOD;
		fib[i+2] = nt;
	}
}

void fibify(vector<ll>& x) {
	FOR(i, C) {
		x[i] = x[i] % MOD * fib[i] % MOD;
	}
}

void zeta(vector<ll>& f) {
	FOR(i, N) {
		FOR(j, 1 << N) {
			if (!(j & 1 << i)) (f[j] += f[j | 1 << i]) %= MOD;
		}
	}
}

void fast_mebi(vector<ll>& f) {
	for(int i = N-1; i >= 0; i--) {
		FOR(j, 1 << N) {
			if (!(j & 1 << i)) (f[j] -= f[j | 1 << i]) %= MOD;
		}
	}
}

int main() {
	init();

	int n; reader(n);
	vector<int> a(n);
	FOR(i, n) reader(a[i]);
	
	vector<ll> v(C);
	for (auto x : a)v[x]++;

	vector<vector<ll>> vals(3);

	or_part(v, vals[0]);
	vals[1] = v;
	xor_part(v, vals[2]);

	FOR(i, 3) {
		fibify(vals[i]);
		zeta(vals[i]);
	}
	FOR(i, 2) {
		FOR(j, C) {
			(vals[2][j] *= vals[i][j]) %= MOD;
		}
	}
	
	fast_mebi(vals[2]);
	ll ans = 0;
	FOR(i, N) {
		ans += vals[2][1 << i];
	}
	ans = (ans % MOD + MOD) % MOD;
	writerLn(ans);


	return 0;
}