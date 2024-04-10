#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
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
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

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

typedef pair<Pii, int> P;
typedef pair<Pii, Pii> P2;

pair<ll, Pii> solve(vector<P>&a, vector<P2>& b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ret = 0;
	Pii ret_ids;
	int al = 0;
	int rmax = 0;
	int rmax_id = -1;
	FOR(i, sz(b)) {
		while (al < sz(a) && a[al].first.first <= b[i].first.first) {
			if (rmax < a[al].first.second) {
				rmax = a[al].first.second;
				rmax_id = al;
			}
			al++;
		}
		ll df = min<ll>(b[i].first.second, rmax) - b[i].first.first;
		ll val = df * b[i].second.first;
		if (val > ret) {
			ret_ids.first = rmax_id;
			ret_ids.second = i;
			ret = val;
		}
	}

	ret_ids.first = a[ret_ids.first].second;
	ret_ids.second = b[ret_ids.second].second.second;

	return make_pair(ret, ret_ids);
}

//0-indexed
//       k
//     /   \
// 2k+1     2k+2
// ke (k-1)/2
class RMQ {
public:
	vector<Pii> mn;
	int n;

	void init(int size) {
		n = 1;
		while (n < size) n <<= 1;
		mn.resize(2 * n - 1, Pii(-1,-1));
		// for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	void propagate(int i) {
		int l = i * 2 + 1, r = i * 2 + 2;
		mn[i] = max(mn[l], mn[r]);
	}

	//k(0-indexed)valXV
	void update(int k, Pii val) {
		k += n - 1;
		mn[k] = max(mn[k],val);
		while (k > 0) {
			k = (k - 1) / 2;
			propagate(k);
		}
	}

	//[a,b)A(lAl)
	Pii query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	//[a,b)l
	// k = _
	// [l,r)k
	Pii query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return Pii(-1, -1); //O
		if (a <= l && r <= b) return mn[k]; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1; //q_
		Pii lval = query(a, b, nl, l, md);
		Pii rval = query(a, b, nr, md, r);
		return max(lval, rval);
	}
};

pair<ll, Pii> solve2(vector<P> a, vector<P2> b) {
	//sort(a.begin(), a.end());
	//sort(b.begin(), b.end());

	vector<ll> adiff;
	FOR(i, sz(a)) adiff.push_back(a[i].first.second - a[i].first.first);

	vector<int> cm;
	FOR(i, sz(a)) {
		cm.push_back(a[i].first.first);
		cm.push_back(a[i].first.second);
	}
	FOR(i, sz(b)) {
		cm.push_back(b[i].first.first);
		cm.push_back(b[i].first.second);
	}
	sort(cm.begin(), cm.end());
	cm.erase(unique(cm.begin(), cm.end()), cm.end());
	FOR(i, sz(a)) {
		a[i].first.first = lower_bound(cm.begin(), cm.end(), a[i].first.first) - cm.begin();
		a[i].first.second = lower_bound(cm.begin(), cm.end(), a[i].first.second) - cm.begin();
	}
	FOR(i, sz(b)) {
		b[i].first.first = lower_bound(cm.begin(), cm.end(), b[i].first.first) - cm.begin();
		b[i].first.second = lower_bound(cm.begin(), cm.end(), b[i].first.second) - cm.begin();
	}

	RMQ rmq;
	rmq.init(sz(cm));

	ll ret = 0;
	Pii ret_ids;
	int bl = 0;
	FOR(i,sz(a)) {
		while (bl < sz(b) && b[bl].first.first <= a[i].first.first) {
			rmq.update(b[bl].first.second,b[bl].second);
			bl++;
		}
		
		auto cur = rmq.query(a[i].first.second, sz(cm));
		ll cur_val = cur.first * ll(adiff[i]);
		if (cur_val > ret) {
			ret = cur_val;
			ret_ids.first = i;
			ret_ids.second = cur.second;
		}
	}

	ret_ids.first = a[ret_ids.first].second;
	// ret_ids.second = b[ret_ids.second].second.second;

	return make_pair(ret, ret_ids);
}

pair<ll, Pii> greedy(vector<P>& a, vector<P2>& b) {
	ll val = 0;
	Pii ids;
	FOR(i, sz(a)) {
		FOR(j, sz(b)) {
			int l = max(a[i].first.first, b[j].first.first);
			int r = min(a[i].first.second, b[j].first.second);
			ll cur = (r - l) * ll(b[j].second.first);
			if (val < cur) {
				val = cur;
				ids.first = a[i].second;
				ids.second = b[j].second.second;
			}
		}
	}
	return make_pair(val, ids);
}

int main() {
	int n, m; reader(n, m);
	vector<P> vp(n);
	FOR(i, n)  reader(vp[i].first.first, vp[i].first.second);
	FOR(i, n) vp[i].second = i;
	vector<P2> vs(m);
	FOR(i, m) reader(vs[i].first.first, vs[i].first.second, vs[i].second.first);
	FOR(i, m) vs[i].second.second = i;

	//auto a = vp;
	//auto b = vs;

	auto ans1 = solve(vp, vs);
	auto ans3 = solve2(vp, vs);

	const int INF = ten(9) + 1;
	FOR(i, n) {
		vp[i].first.first = INF - vp[i].first.first;
		vp[i].first.second = INF - vp[i].first.second;
		swap(vp[i].first.first, vp[i].first.second);
	}
	FOR(i, m) {
		vs[i].first.first = INF - vs[i].first.first;
		vs[i].first.second = INF - vs[i].first.second;
		swap(vs[i].first.first, vs[i].first.second);
	}

	auto ans2 = solve(vp, vs);
	auto ans = (ans1.first > ans2.first) ? ans1 : ans2;
	ans = (ans.first > ans3.first) ? ans : ans3;

	//auto test = greedy(a, b);
	//if (ans.first != test.first) {
	//	cout << "?";
	//}
	//{
	//	int l = max(a[ans.second.first].first.first, b[ans.second.second].first.first);
	//	int r = min(a[ans.second.first].first.second, b[ans.second.second].first.second);
	//	ll cur = (r - l) * ll(b[ans.second.second].second.first);
	//	if (cur != ans.first) {
	//		cout << "?";
	//	}
	//}

	cout << ans.first << endl;
	if (ans.first) {
		cout << ans.second.first + 1 << " " << ans.second.second + 1 << endl;
	}
}