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

struct val_t {
	int dp[15];
};

vector<Pii> v_tbl;
int base[5];
vector<vector<Pii>> to(15);

void init() {
	base[0] = 0;
	base[1] = 5;
	base[2] = 5 + 4;
	base[3] = 5 + 4 + 3;
	base[4] = 5 + 4 + 3 + 2;

	for (int l = 0; l < 5; l++) {
		for (int r = l; r < 5; r++) {
			v_tbl.emplace_back(l, r);
		}
	}
	for (int l = 0; l < 5; l++) {
		for (int r = l; r < 5; r++) {
			const int from = base[l] + r - l;
			for (int r2 = r; r2 < 5; r2++) {
				const int t = base[r] + r2 - r;
				const int t2 = base[l] + r2 - l;
				to[from].emplace_back(t, t2);
			}
		}
	}
}


void chmin(int&l, int r) {
	l = min(l, r);
}
struct add_t {
	val_t val;
	static add_t zero() { return add_t(); }
	add_t() {
		memset(&val, 0x2f, sizeof(val));
		FOR(i, 5) val.dp[base[i]] = 0;
	}
	add_t(val_t val) : val(val) {}
	operator val_t () const { return val; }
	add_t  operator+ (const add_t & r) const {
		add_t ret;
		memset(&ret.val, 0x2f, sizeof(val));

		FOR(i, 15) for (auto& e : to[i]) {
			int use = e.first;
			int tt = e.second;
			int nval = val.dp[i] + r.val.dp[use];
			chmin(ret.val.dp[tt], nval);
		}
		return ret;
	}
};

using P = add_t;
class seg_tree {
public:
	vector<P> dat;
	int n;

	void propagate(int i) {
		dat[i] = dat[i * 2 + 1] + dat[i * 2 + 2];
	}

	void init(P* d, int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		// memset(dat.data(), 0, sizeof(dat));
		fill(dat.begin(), dat.end(), P::zero());
		for (int i = 0; i < size; i++) dat[n - 1 + i] = d[i];
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	//[a,b)
	P query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	P query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return P::zero();
		if (a <= l && r <= b) return dat[k];

		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1;
		P lval = query(a, b, nl, l, md);
		P rval = query(a, b, nr, md, r);

		return lval + rval;
	}
};

int main() {
	init();

	int n, q; reader(n, q);
	string s; reader(s);

	static P init_p[2 * ten(5) + 1];
	FOR(i, n) {
		auto& v = init_p[i].val;
		v = P::zero();
		auto& dp = v.dp;
		FOR(id, 15) {
			int l, r; tie(l, r) = v_tbl[id];
			if (s[i] == '2') {
				if (r == 0) dp[id]++;
				if (l == 0 && r == 1) dp[id] = 0;
			} else if (s[i] == '0') {
				if (r == 1) dp[id]++;
				if (l == 1 && r == 2) dp[id] = 0;
			} else if (s[i] == '1') {
				if (r == 2) dp[id]++;
				if (l == 2 && r == 3) dp[id] = 0;
			} else if (s[i] == '6') {
				if (r == 3 || r == 4) dp[id]++;
			} else if (s[i] == '7') {
				if (r == 3) dp[id]++;
				if (l == 3 && r == 4) dp[id] = 0;
			}
		}
	}

	seg_tree st;
	st.init(init_p, n);
	auto valll = st.query(0, 5);

	//FOR(i, n) for (int j = i + 1; j <= n; j++) {
	//	auto val = st.query(i, j);
	//	int ans = val.val.dp[4];
	//	if (ans > n) ans = -1;
	//	printf("(%d,%d) : %d\n",i, j, ans);
	//}

	FOR(i, q) {
		int a, b; reader(a, b);
		a--;
		auto val = st.query(a, b);
		int ans = val.val.dp[4];
		if (ans > n) ans = -1;
		writerLn(ans);
	}

	return 0;
}