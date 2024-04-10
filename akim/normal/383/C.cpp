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
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;*/
#endif

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

int a[maxn];
vector<int> rb[maxn];

int lf[2][maxn], rg[2][maxn], h[maxn], sz[2];
int fv[2][maxn];
bool pm[maxn];

void dfs(int u, int hh = 0) {
	pm[u] = 1;
	h[u] = hh;
	lf[0][u] = sz[0];
	lf[1][u] = sz[1];
	sz[hh & 1]++;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(pm[v]) continue;
		dfs(v, hh + 1);
	}
	rg[0][u] = sz[0];
	rg[1][u] = sz[1];
}

void add(int *fv, int u, int val) {
	for(; u < maxn; u |= u + 1) {
		fv[u] += val;
	}
}

int get(int *fv, int u) {
	int ret = 0;
	for(; u >= 0; u &= u + 1, u--) {
		ret += fv[u];
	}
	return(ret);
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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	dfs(0);

	for(int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int x, val;
			scanf("%d%d", &x, &val);
			x--;
			add(fv[h[x] & 1], lf[h[x] & 1][x], val);
			add(fv[h[x] & 1], rg[h[x] & 1][x], -val);
			add(fv[(h[x] & 1) ^ 1], lf[(h[x] & 1) ^ 1][x], -val);
			add(fv[(h[x] & 1) ^ 1], rg[(h[x] & 1) ^ 1][x], val);
		} else {
			int x;
			scanf("%d", &x);
			x--;
			printf("%d\n", a[x] + get(fv[h[x] & 1], lf[h[x] & 1][x]));
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