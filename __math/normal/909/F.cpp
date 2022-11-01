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

bool solve1(int n, vector<int>& ret) {
	if (n % 2 != 0) {
		return false;
	}
	if (n == 0) return true;

	int top = 0;
	FOR(j, 25) if (n & (1 << j)) {
		top = 1 << j;
	}
	int cur = top * 2 - 2;
	FOR(i, n) {
		ret[i % n] = top * 2 - 2 - i;
	}

	int rem = cur - n;
	solve1(rem, ret);

	bool ok = true;
	FOR(i, n) if (ret[i] == i + 1 || (ret[i] & (i + 1)) != 0) ok = false;
	if (!ok) {
		cout << "?";
	}

	return true;
}

bool solve2(int n, vector<int>& ret) {
	if (n <= 5) {
		return false;
	}
	if ((n&-n) == n) {
		return false;
	}
	if (n == 6) {
		ret = { 3,6,1,5,4,2 };
		return true;
	} else if (n == 7) {
		ret = { 3,6,1,5,4,7,2 };
		return true;
	}

	ret = { 3,6,1,5,4,7,2 };
	ret.resize(n);
	for (int start = 8; start < n; start *= 2) {
		int len = min(n - start + 1, start);
		FOR(i, len) {
			if (i == 0) {
				ret[start - 1 + len - 1] = start + i;
			} else {
				ret[start - 1 + i - 1] = start + i;
			}
		}
	}

	bool ok = true;
	FOR(i, n) if (ret[i] == i + 1 || (ret[i] & (i + 1)) == 0) ok = false;
	if (!ok) {
		cout << "?";
	}

	return true;
}

int main() {
	int n;
	reader(n);

	{
		vector<int> ret(n);
		auto ans = solve1(n, ret);
		if (ans) {
			puts("YES");
			writerArr(ret);
		} else {
			puts("NO");
		}
	}

	{
		vector<int> ret;
		auto ans = solve2(n, ret);
		if (ans) {
			puts("YES");
			writerArr(ret);
		} else {
			puts("NO");
		}
	}


	return 0;
}