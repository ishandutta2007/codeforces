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
template<class T, class S, class U, class V> void writerLn(T x, S y, U z, V v) { writer(x, ' '); writer(y, ' '); writer(z, ' '); writer(v, '\n'); }
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


ll solve(vector<Pii>& vp) {
	if (sz(vp) < 4) return 0;
	vector<Pii> blk;

	const int C = ten(5) * 4 + 10;
	static int lt[2][C + 1], rt[2][C + 1];
	memset(lt, 0x2f, sizeof(lt));
	memset(rt, 0, sizeof(rt));

	for (auto& kv : vp) {
		if ((kv.first + kv.second) % 2 != 0) {
			kv.first++;
		}
		int a = kv.first + kv.second;
		a += 2 * ten(5);
		a /= 2;
		int b = kv.first - kv.second;
		b += 2 * ten(5);
		b /= 2;
		blk.emplace_back(a, b);
	}

	sort(blk.begin(), blk.end());
	{
		const int dir = 0;
		int blki = 0;
		FOR(i, C) {
			while (blki < sz(blk) && blk[blki].first == i) {
				chmin(lt[dir][i], blk[blki].second);
				chmax(rt[dir][i], blk[blki].second);
				blki++;
			}
			chmin(lt[dir][i + 1], lt[dir][i]);
			chmax(rt[dir][i + 1], rt[dir][i]);
		}
	}
	{
		const int dir = 1;
		reverse(blk.begin(), blk.end());
		int blki = 0;
		for(int i = C - 1; i >= 0; i--) {
			while (blki < sz(blk) && blk[blki].first == i) {
				chmin(lt[dir][i], blk[blki].second);
				chmax(rt[dir][i], blk[blki].second);
				blki++;
			}
			if (i) chmin(lt[dir][i - 1], lt[dir][i]);
			if (i) chmax(rt[dir][i - 1], rt[dir][i]);
		}
	}

	ll ans = 0;
	FOR(i, C - 1) {
		int l = max(lt[0][i], lt[1][i + 1]);
		int r = min(rt[0][i], rt[1][i + 1]);
		int diff = r - l;
		if (diff > 0) {
			ans += diff;
		}
	}

	return ans;
}

int main() {
	int n; reader(n);
	vector<Pii> o[2];
	FOR(i, n) {
		int x, y; reader(x, y);
		if ((x + y) % 2 == 0) o[0].emplace_back(x, y);
		else o[1].emplace_back(x, y);
	}

	ll ans1 = solve(o[0]);
	ll ans2 = solve(o[1]);
	ll ans = ans1 + ans2;
	writerLn(ans);

	return 0;
}