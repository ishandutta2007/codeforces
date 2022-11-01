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

class sparse_table {
	vector<vector<int>> dat;
	vector<int> logTable;
	int n;

	int zero_element() const {
		return numeric_limits<int>::min();
	}
	int prop(int a, int b) const {
		return max(a, b);
	}

public:
	sparse_table(vector<int>& a) {
		n = sz(a);
		logTable.resize(n + 1);
		logTable[0] = logTable[1] = 0;
		for (int i = 2; i <= n; i++) logTable[i] = logTable[i >> 1] + 1;

		int logN = logTable[n];
		dat.resize(logN + 1, vector<int>(n, zero_element()));
		FOR(i, n) dat[0][i] = a[i];
		for (int i = 1; i <= logN; i++) {
			int l = 1 << i;
			for (int j = 0; j + l <= n; j++) {
				dat[i][j] = prop(dat[i - 1][j], dat[i - 1][j + l / 2]);
			}
		}
	}

	int query(int l, int r) {
		int k = logTable[r - l];
		return prop(dat[k][l], dat[k][r - (1 << k)]);
	}

};


int main() {
	int n; reader(n);
	vector<int> a(n);
	FOR(i, n) reader(a[i]);

	ll ans = 0;
	sparse_table st(a);
	vector<int> pv, nt;
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			pv.push_back(i);
		} else {
			int cur = a[i];
			nt.clear();
			nt.push_back(i);
			for (auto c : pv) {
				if ((cur | a[c]) == cur) continue;
				cur |= a[c];
				nt.push_back(c);
			}
			swap(nt, pv);
		}

		int cc = 0;
		FOR(j, sz(pv)) {
			cc |= a[pv[j]];

			const int ll = pv[j];
			const int rr = j == sz(pv) - 1 ? n : pv[j + 1];

			int l = ll - 1, r = rr;
			while (r - l != 1) {
				int md = (l + r) / 2;
				int mmax = st.query(i, md + 1);

				if (cc <= mmax) {
					r = md;
				} else {
					l = md;
				}
			}

			int cans = l - ll + 1;
			ans += cans;
		}
	}

	writerLn(ans);

	return 0;
}