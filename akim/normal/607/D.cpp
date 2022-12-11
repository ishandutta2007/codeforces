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
const int maxn = 200100;

int n = 1;
int ord[maxn], a[maxn], par[maxn], tp[maxn], zp[maxn], childs[maxn];
int lef[maxn], rig[maxn];
int osz = 0;
vector<int> rb[maxn];

void dfs(int u) {
	lef[u] = osz;
	ord[osz++] = u;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		dfs(rb[u][i]);
	}
	rig[u] = osz - 1;
}

ll binpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b & 1) {
			res *= a;
			res %= mod;
		}
		b >>= 1;
		a *= a;
		a %= mod;
	}
	return(res);
}


ll mult[4 * maxn], val[4 * maxn], en[4 * maxn];

void build(int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl == tr) {
		mult[v] = 1;
		en[v] = 0;
		val[v] = 0;
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v * 2 + 1, tl, tm);
	build(v * 2 + 2, tm + 1, tr);
	mult[v] = 1;
	en[v] = 1;
	val[v] = mult[v] * en[v] * (val[v * 2 + 1] + val[v * 2 + 2]) % mod;
}

void enable(int pos, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl > pos || tr < pos) {
		return;
	}
	if(pos <= tl && tr <= pos) {
		en[v] = 1;
		val[v] = a[ord[tl]] * mult[v] * en[v] % mod;
		return;
	}
	int tm = (tl + tr) >> 1;
	enable(pos, v * 2 + 1, tl, tm);
	enable(pos, v * 2 + 2, tm + 1, tr);
	val[v] = mult[v] * en[v] * (val[v * 2 + 1] + val[v * 2 + 2]) % mod;
}

void update(int lf, int rg, ll mn, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl > rg || tr < lf) {
		return;
	}
	if(lf <= tl && tr <= rg) {
		mult[v] = mult[v] * mn % mod;
		if(tl == tr) {
			val[v] = a[ord[tl]] * mult[v] * en[v] % mod;
		} else {
			val[v] = mult[v] * en[v] * (val[v * 2 + 1] + val[v * 2 + 2]) % mod;
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	update(lf, rg, mn, v * 2 + 1, tl, tm);
	update(lf, rg, mn, v * 2 + 2, tm + 1, tr);
	val[v] = mult[v] * en[v] * (val[v * 2 + 1] + val[v * 2 + 2]) % mod;
}

ll getsum(int lf, int rg, int v = 0, int tl = 0, int tr = maxn - 1) {
	if(tl > rg || tr < lf) {
		return(0);
	}
	if(lf <= tl && tr <= rg) {
		return(val[v]);
	}
	int tm = (tl + tr) >> 1;
	return(mult[v] * en[v] * (getsum(lf, rg, v * 2 + 1, tl, tm) + getsum(lf, rg, v * 2 + 2, tm + 1, tr)) % mod);
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

	int m;
	scanf("%d%d", &a[0], &m);
	par[0] = -1;
	for(int i = 0; i < m; i++) {
		scanf("%d", &tp[i]);
		if(tp[i] == 1) {
			scanf("%d%d", &par[n], &a[n]);
			par[n]--;
			zp[i] = n;
			rb[par[n]].pb(n);
			n++;
		} else {
			scanf("%d", &zp[i]);
			zp[i]--;
		}
	}

	dfs(0);

	build();
	enable(lef[0]);

	for(int i = 0; i < m; i++) {
//		printf("%lld\n", getsum(lef[0], rig[0]));
//		for(int j = 0; j < n; j++) {
//			printf("%lld ", getsum(lef[j], lef[j]));
//		}printf("\n");
		if(tp[i] == 1) {
			int pr = par[zp[i]];
			enable(lef[zp[i]]);
			update(lef[pr], rig[pr], (childs[pr] + 2) * binpow(childs[pr] + 1, mod - 2) % mod);
			childs[pr]++;
		} else {
			ll val = zp[i] == 0 ? 1 : getsum(lef[par[zp[i]]], lef[par[zp[i]]]) * binpow(a[par[zp[i]]], mod - 2) % mod;
			printf("%lld\n", getsum(lef[zp[i]], rig[zp[i]]) * binpow(val, mod - 2) % mod);
		}
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