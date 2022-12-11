#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

vector<int> rb[maxn];
bitset<1000> deo[4 * maxn], all;
int mv[4 * maxn];
int a[maxn], b[maxn], sz;
int lf[maxn], rg[maxn];
bool pm[maxn], rw[1000];
int m;

void build(int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl == tr) {
		deo[v][a[b[tl]]] = 1;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	deo[v] = (deo[v * 2 + 1] | deo[v * 2 + 2]);
}

void push(int v, int tl, int tr) {
	if(!mv[v]) return;
	deo[v] = (((deo[v] << mv[v]) | (deo[v] >> (m - mv[v]))) & all);
	if(tl == tr) {
		mv[v] = 0;
		return;
	}
	mv[v * 2 + 1] += mv[v];
	mv[v * 2 + 1] -= mv[v * 2 + 1] >= m ? m : 0;
	mv[v * 2 + 2] += mv[v];
	mv[v * 2 + 2] -= mv[v * 2 + 2] >= m ? m : 0;
	mv[v] = 0;
}

void upd(int lf, int rg, int val, int v = 0, int tl = 0, int tr = maxn - 1) {
	push(v, tl, tr);
	if(rg < tl || tr < lf) {
		return;
	}
	if(lf <= tl && tr <= rg) {
		mv[v] += val;
		mv[v] -= mv[v] >= m ? m : 0;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(lf, rg, val, v * 2 + 1, tl, tm);
	upd(lf, rg, val, v * 2 + 2, tm + 1, tr);
	deo[v] = (deo[v * 2 + 1] | deo[v * 2 + 2]);
}

bitset<1000> get(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	push(v, tl, tr);
	if(rg < tl || tr < lf) {
		return bitset<1000>();
	}
	if(lf <= tl && tr <= rg) {
		return(deo[v]);
	}
	int tm = (tl + tr) >> 1;
	return(get(lf, rg, v * 2 + 1, tl, tm) | get(lf, rg, v * 2 + 2, tm + 1, tr));
}

void dfs(int u) {
	pm[u] = 1;
	lf[u] = sz;
	b[sz++] = u;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(pm[v]) continue;
		dfs(v);
	}
	rg[u] = sz - 1;
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	rw[0] = rw[1] = 1;
	for(int i = 2; i < 1000; i++) {
		if(!rw[i]) {
			for(int j = i + i; j < 1000; j += i) {
				rw[j] = 1;
			}
		}
	}

	int n;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] %= m;
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	for(int i = 0; i < m; i++) all[i] = 1;

	dfs(0);
	build();
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int v, x;
			scanf("%d%d", &v, &x);
			v--;
			upd(lf[v], rg[v], x % m);
		} else {
			int u;
			scanf("%d", &u);
			u--;
			bitset<1000> ans = get(lf[u], rg[u]);
			int cnt = 0;
			for(int i = 0; i < m; i++) {
				if(!rw[i] && ans[i] == 1) {
					cnt++;
				}
			}
			printf("%d\n", cnt);
		}
//		for(int j = 0; j < m; j++) {
//			printf("%d ", deo[0][j] == 1);
//		}printf("\n");
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim