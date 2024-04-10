#define _USE_MATH_DEFINES
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

// #pragma comment(linker,"/STACK:36777216")

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

template<class T> void chmax(T& l, const T r){ l = max(l, r); }
template<class T> void chmin(T& l, const T r){ l = min(l, r); }

template<class T> T extgcd(T a, T b, T& x, T& y){ for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m){ T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

struct P {
	ll up, dem;
	int id;
	P(){}
	P(ll up, ll dem, int id) : up(up), dem(dem), id(id) {}

	bool operator<(const P& r){
		ll x = up * r.dem;
		ll y = r.up * dem;
		return x < y;
	}
};

P INF = { 2, 1, -1 };

P add(P& l, P& r){
	if (l < r) return l;
	else return r;
}

class seg_tree {
public:
	vector<P> dat;
	int n;

	void init(vector<P>& v){
		init(&v[0], sz(v));
	}

	void init(P* d, int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), INF);
		for (int i = 0; i < size; i++) dat[n - 1 + i] = d[i];
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	void propagate(int i) {
		dat[i] = add(dat[i * 2 + 1], dat[i * 2 + 2]);
	}

	//k(0-indexed)valXV
	void update(int k, P val) {
		k += n - 1;
		dat[k] = val;
		while (k > 0) {
			k = (k - 1) / 2;
			propagate(k);
		}
	}

	//[a,b)l
	P query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	//[a,b)l
	// k = _
	// [l,r)k
	P query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return INF; //O
		if (a <= l && r <= b) return dat[k]; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1; //q_
		P lval = query(a, b, nl, l, md);
		P rval = query(a, b, nr, md, r);

		return add(lval, rval); //calc
	}

	P at(int idx){
		return dat[n - 1 + idx];
	}
};

vector<int> e[ten(5)];
bool life_city[ten(5)];

int main(){
	int n, m, k; reader(n, m ,k);
	FOR(i, k){
		int x; reader(x); x--;
		life_city[x] = true;
	}

	FOR(i, m){
		int a, b; reader(a, b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}

	vector<P> vp(n);
	FOR(i, n){
		vp[i].up = 0;
		vp[i].dem = sz(e[i]);
		vp[i].id = i;
	}

	FOR(i, n) for (auto to : e[i]) {
		if (life_city[i] || life_city[to]) continue;
		vp[i].up++;
		vp[to].up++;
	}
	FOR(i, n) if (life_city[i]) vp[i] = INF; else vp[i].up /= 2;

	seg_tree seg;
	seg.init(vp);

	vector<int> del_idx;
	P max = { -1, 1, -1 };
	int timing = -1;
	int time = -1;
	while (true) {
		time++;
		P val = seg.query(0, n);
		if (val.id == -1) break;
		if (max < val) {
			max = val;
			timing = time;
		}
		del_idx.push_back(val.id);
		seg.update(val.id, INF);
		for (auto to : e[val.id]) {
			P tval = seg.at(to);
			if (tval.id != -1) {
				seg.update(to, P(tval.up - 1, tval.dem, tval.id));
			}
		}
	}

	static bool ans_table[ten(5)];
	memset(ans_table, 1, sizeof(ans_table));
	FOR(i, n) if (life_city[i]) ans_table[i] = false;
	FOR(i, timing) ans_table[del_idx[i]] = false;

	vector<int> ans;
	FOR(i, n) if (ans_table[i]) ans.push_back(i + 1);

	writerLn(sz(ans));
	writerArr(&ans[0], sz(ans));
}