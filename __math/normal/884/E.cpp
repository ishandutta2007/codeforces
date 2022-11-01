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

class UnionFind {
private:
	int n;
	vector<int> a;
public:
	UnionFind(int n) : n(n), a(n, -1) {}
	void clear() {
		memset(a.data(), -1, sizeof(int) * sz(a));
	}
	int find(int x) { return a[x] < 0 ? x : (a[x] = find(a[x])); }
	bool same(int x, int y) { return find(x) == find(y); }
	bool same(Pii& p) { return same(p.first, p.second); }
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (a[x] > a[y]) swap(x, y);
		a[x] += a[y];
		a[y] = x;
		n--;
		return true;
	}
	bool unite(Pii& p) { return unite(p.first, p.second); }
	int size() const { return n; }
	int size(int x) { return -a[find(x)]; }
};

int main() {
	int n, m; reader(n, m);
	UnionFind pv(m * 2), nt(m * 2);
	vector<bool> bpv(m), bnt(m);

	bool debug = false;

	ll ans = 0;
	FOR(i, n + 1) {
		nt.clear();
		bnt.clear();
		bnt.resize(m);

		static char buf[(1 << 14) + 10];
		if (i != n) {
			reader(buf);
		} else {
			FOR(j, m) buf[j] = '0';
		}
		if (!debug) {
			FOR(j, m / 4) {
				char c = buf[j];
				int val;
				if ('0' <= c && c <= '9')val = c - '0';
				else val = c - 'A' + 10;
				FOR(k, 4) {
					bnt[j * 4 + 3 - k] = (val >> k) & 1;
				}
			}
		} else {
			FOR(j, m) bnt[j] = buf[j] - '0';
		}
		FOR(j, m - 1) {
			if (bnt[j] && bnt[j + 1]) {
				nt.unite(j, j + 1);
			}
		}
		static int pvuf2compressed[(1 << 15) + 1];
		memset(pvuf2compressed, 0, sizeof(pvuf2compressed));
		FOR(j, m) {
			if (bpv[j]) pvuf2compressed[pv.find(j) + 1] = 1;
		}
		FOR(j, (1 << 15)) pvuf2compressed[j + 1] += pvuf2compressed[j];

		static int pvused[1 << 15];
		memset(pvused, 0, sizeof(pvused));
		FOR(j, m) {
			if (bpv[j] && bnt[j]) {
				pvused[pv.find(j)] = true;
				int cmpid = pvuf2compressed[pv.find(j)];
				nt.unite(j, m + cmpid);
			}
		}
		FOR(j, m) {
			if (!bpv[j]) continue;
			int uj = pv.find(j);
			if (pvused[uj] == 2) continue;

			if (pvused[uj] == 0) {
				ans++;
			}

			pvused[uj] = 2;
		}

		swap(pv, nt);
		swap(bpv, bnt);
	}

	writerLn(ans);

	return 0;
}