#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
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
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }
template<class T> void chmax(T& a, T b) { if (a < b) a = b; }

typedef int Ptype;
typedef pair<Ptype, Ptype> Pt;
const Pt Pinf = Pt(numeric_limits<Ptype>::max(), numeric_limits<Ptype>::max());
class RangeTree {
public:
	int n;
	vector<Pt> xsorted;

	vector<vector<Pt>> dat;
	vector<vector<Pii>> bsearch_speedup;
	RangeTree(vector<Pt>& a) {
		n = 1;
		while (n < sz(a)) n <<= 1;
		dat.resize(2 * n - 1);

		//sort by first
		sort(a.begin(), a.end());
		xsorted = a;
		xsorted.resize(n, Pinf);
		bsearch_speedup.resize(n);

		FOR(i, n) {
			int k = n - 1 + i;
			if (i < sz(a)) dat[k].push_back(a[i]);
			else dat[k].push_back(Pinf);
		}
		for (int i = n - 2; i >= 0; i--) {
			auto& cur_dat = dat[i], &lchild = dat[2 * i + 1], rchild = dat[2 * i + 2];
			cur_dat.resize(sz(lchild) + sz(rchild));
			//sort by second
			merge(lchild.begin(), lchild.end(), rchild.begin(), rchild.end(),
				cur_dat.begin(),
				[](const Pt& l, const Pt&  r) { return l.second != r.second ? l.second < r.second : l.first < r.first; }
			);
			//binary_search speed up with fractional cascading
			auto& bs = bsearch_speedup[i];
			bs.resize(sz(cur_dat));
			int a1 = 0, a2 = 0;
			FOR(k, sz(cur_dat)) {
				while (a1 < sz(lchild) && lchild[a1].second < cur_dat[k].second) a1++;
				bs[k].first = a1;
				while (a2 < sz(rchild) && rchild[a2].second < cur_dat[k].second) a2++;
				bs[k].second = a2;
			}
			bs.emplace_back(sz(lchild), sz(rchild));
		}
	}
	// [lx,rx) * [ly,ry) O(log n)
	int query(Ptype lx, Ptype rx, Ptype ly, Ptype ry) {
#define CMP [](const Pt& l, const Ptype val) { return l.second < val; }
		int ly_index = lower_bound(dat[0].begin(), dat[0].end(), ly, CMP) - dat[0].begin();
		int ry_index = lower_bound(dat[0].begin(), dat[0].end(), ry, CMP) - dat[0].begin();
#undef  CMP
		return query(lx, rx, ly_index, ry_index, 0, 0, n);
	}
	int query(Ptype lx, Ptype rx, int ly_index, int ry_index, int k, int a, int b) {
		if (rx <= xsorted[a].first || xsorted[b - 1].first < lx) return 0;
		if (lx <= xsorted[a].first && xsorted[b - 1].first < rx) {
			return ry_index - ly_index;
		}

		int nly_idx_f, nly_idx_s, nry_idx_f, nry_idx_s;
		tie(nly_idx_f, nly_idx_s) = bsearch_speedup[k][ly_index];
		tie(nry_idx_f, nry_idx_s) = bsearch_speedup[k][ry_index];
		int lval = query(lx, rx, nly_idx_f, nry_idx_f, 2 * k + 1, a, (a + b) / 2);
		int rval = query(lx, rx, nly_idx_s, nry_idx_s, 2 * k + 2, (a + b) / 2, b);
		return lval + rval;
	}
};

void range_tree_test() {
	vector<Pt> vpt = {
		Pt(0, 0),
		Pt(1, 0),
		Pt(2, 0),
		Pt(3, 0),
		Pt(0, 10),
		Pt(0, 20),
		Pt(0, 30),
		Pt(5, 5),
		Pt(-3, -3)
	};

	RangeTree rt(vpt);
	assert(rt.query(0, 1, 0, 1) == 1);
	assert(rt.query(0, 4, 0, 4) == 4);
	assert(rt.query(-10, 1, -10, 1) == 2);
	assert(rt.query(-100, 100, -100, 100) == 9);
}

vector<int> vx, vy;
ll solve(RangeTree& rt,int xup, int xdown, int yup, int ydown, int k) {
	if (xup + xdown > k) return numeric_limits<ll>::max();
	if (yup + ydown > k) return numeric_limits<ll>::max();
	ll xdiff = vx[sz(vx) - 1 - xdown] - vx[xup];
	ll ydiff = vy[sz(vy) - 1 - ydown] - vy[yup];
	xdiff = max(xdiff, 1LL);
	ydiff = max(ydiff, 1LL);

	int num = rt.query(vx[xup], vx[sz(vx) - 1 - xdown] + 1, vy[yup], vy[sz(vy) - 1 - ydown] + 1);
	if (num < sz(vx) - k) return numeric_limits<ll>::max();

	ll ans = ((xdiff + 1) / 2) * ((ydiff + 1) / 2);
	return ans;
}

int main() {
	int n, k; reader(n, k);

	vector<Pt> vp;
	FOR(i, n) {
		int x1, x2, y1, y2; reader(x1, y1, x2, y2);
		vp.emplace_back(x1 + x2, y1 + y2);
		vx.push_back(x1 + x2);
		vy.push_back(y1 + y2);
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	RangeTree rt(vp);

	ll ans = numeric_limits<ll>::max();
	FOR(xup, k + 1) FOR(xdown, k + 1) FOR(yup, k + 1) FOR(ydown, k + 1) {
		ll tmp = solve(rt, xup, xdown, yup, ydown, k);
		ans = min(ans, tmp);
	}
	writerLn(ans);
	
	return 0;
}