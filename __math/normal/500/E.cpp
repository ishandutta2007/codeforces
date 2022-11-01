#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
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
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

//0-indexed
//       k
//     /   \
// 2k+1     2k+2
// ke (k-1)/2
// //calc AX\[X
class seg_tree {
public:
	vector<int> dat;
	int n;

	void init(int* d, int size) {
		n = 1;
		while (n < size) n <<= 1;
		dat.resize(2 * n - 1);
		fill(dat.begin(), dat.end(), 0);
		for (int i = 0; i < size; i++) dat[n - 1 + i] = d[i];
		for (int i = n - 2; i >= 0; i--) propagate(i);
	}

	void propagate(int i) {
		dat[i] = max(dat[i * 2 + 1], dat[i * 2 + 2]);
	}

	//k(0-indexed)valXV
	void update(int k, int val) {
		k += n - 1;
		dat[k] = val;
		while (k > 0) {
			k = (k - 1) / 2;
			propagate(k);
		}
	}

	//[a,b)l
	int query(int a, int b) {
		return query(a, b, 0, 0, n);
	}

	//[a,b)l
	// k = _
	// [l,r)k
	int query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l) return 0; //O
		if (a <= l && r <= b) return dat[k]; //[l,r)  [a,b)

		//[l,r)[a,b)
		int md = (l + r) / 2; //[l,md),[md,r)
		int nl = k * 2 + 1, nr = nl + 1; //q_
		int lval = query(a, b, nl, l, md);
		int rval = query(a, b, nr, md, r);

		return max(lval, rval); //calc
	}
};
seg_tree st;

const int MAX_SIZE = 2 * ten(5) + 1;
vector<Pii> e[MAX_SIZE];
class LCA {
public:
	int V, logV;
	vector<int> depth;
	vector<ll> len;
	vector<vector<int> > parent;

	LCA() {}

	void init(int V) {
		this->V = V;
		logV = 0;
		while (V >= (1 << logV)) logV++;
		this->depth = vector<int>(V);
		this->len = vector<ll>(V);
		this->parent = vector<vector<int> >(logV, vector<int>(V));

		dfs(V - 1, -1, 0, 0);
		build();
	}

	void dfs(int v, int par, int d, ll l) {
		depth[v] = d;
		parent[0][v] = par;
		len[v] = l;
		for (auto to : e[v]) {
			if (par == to.first) continue;
			dfs(to.first, v, d + 1, to.second + l);
		}
	}

	void build() {
		for (int k = 0; k + 1 < logV; k++) {
			for (int v = 0; v < V; v++) {
				if (parent[k][v] < 0) parent[k + 1][v] = -1;
				else parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}

	int query(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < logV; k++) {
			if ((depth[v] - depth[u]) >> k & 1)
				v = parent[k][v];
		}
		if (u == v) return u;

		for (int k = logV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}

	int prev_parent(int u, int par){
		for (int k = logV - 1; k >= 0; k--) {
			int diff = depth[u] - depth[par];
			if ((diff - (1 << k)) > 0){
				u = parent[k][u];
			}
		}
		return u;
	}

	ll get_len(int u, int v) {
		return len[u] + len[v] - 2 * len[query(u, v)];
	}
};


int main(){
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<Pii> v(n);
	FOR(i, n) {
		cin >> v[i].first >> v[i].second;
		v[i].second += v[i].first;
	}

	vector<int> ft;
	FOR(i, n) ft.push_back(v[i].first);
	
	vector<int> st_init;
	FOR(i, n) st_init.push_back(v[i].second);
	st.init(&st_init[0],sz(st_init));

	static int to[2 * ten(5) + 10],nmax[2*ten(5)+10];
	to[n - 1] = n;
	nmax[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		int r = upper_bound(ft.begin(), ft.end(), v[i].second) - ft.begin();
		int _nmax = st.query(i, r);
		int nto = upper_bound(ft.begin(), ft.end(), _nmax) - ft.begin();
		st.update(i, _nmax);
		to[i] = nto;
		nmax[i] = _nmax;

		// printf("%d : to = %d,rmax = %d\n", i, nto, _nmax);
	}

	FOR(i, n){
		int t = to[i];
		int cost = 0;
		if (t < n) {
			cost = ft[t] - nmax[i];
		}
		if (i == t) continue;
		e[i].push_back(Pii(t, cost));
		e[t].push_back(Pii(i, cost));
	}

	LCA lca;
	lca.init(n + 1);

	int q; cin >> q;
	FOR(i, q){
		int l, r; cin >> l >> r;
		l--; r--;
		int A = lca.query(l, r);
		if (A != r) {
			A = lca.prev_parent(l, A);
		}
		ll ans = lca.get_len(l, A);
		cout << ans << endl;
	}

}