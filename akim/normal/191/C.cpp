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
const int maxn = 100100;

vector<pair<int, int> > rb[maxn];
int binup[maxn][20], tin[maxn], tout[maxn], t = 0;
int added[maxn][20];
bool pm[maxn];
int ans[maxn];

void dfs(int u) {
	pm[u] = 1;
	tin[u] = t++;

	for(int j = 1; j < 20; j++) {
		binup[u][j] = binup[binup[u][j - 1]][j - 1];
	}

	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i].fs;
		if(pm[v]) continue;
		binup[v][0] = u;
		dfs(v);
	}
	tout[u] = t++;
}

void lca(int u, int v) {
	if(u == v) return;

	if(tin[u] > tin[v]) {
		swap(u, v);
	}
	if(tin[u] < tin[v] && tout[v] < tout[u]) {
		for(int i = 19; i >= 0; i--) {
			int nv = binup[v][i];
			if(tin[u] < tin[nv] && tout[nv] < tout[u]) {
				added[v][i]++;
				v = nv;
			}
		}
		added[v][0]++;
	} else {
		for(int i = 19; i >= 0; i--) {
			int nu = binup[u][i];
			if(!(tin[nu] <= tin[v] && tout[v] <= tout[nu])) {
				added[u][i]++;
				u = nu;
			}
		}
		added[u][0]++;
		u = binup[u][0];
		for(int i = 19; i >= 0; i--) {
			int nv = binup[v][i];
			if(tin[u] < tin[nv] && tout[nv] < tout[u]) {
				added[v][i]++;
				v = nv;
			}
		}
		added[v][0]++;
	}
}

void push(int u) {
	pm[u] = 0;

	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i].fs;
		if(pm[v] == 0) continue;
		push(v);
		ans[rb[u][i].sc] = added[v][0];
	}

	for(int j = 19; j > 0; j--) {
		added[binup[u][j - 1]][j - 1] += added[u][j];
		added[u][j - 1] += added[u][j];
	}

}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
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

	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(mp(v, i));
		rb[v].pb(mp(u, i));
	}

	dfs(0);

	int q;
	scanf("%d", &q);
	for(; q--; ) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		lca(u, v);
	}

	push(0);

	for(int i = 1; i < n; i++) {
		printf("%d ", ans[i]);
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