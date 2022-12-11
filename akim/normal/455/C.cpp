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
const int maxn = 300100;

int snm[maxn], d[maxn];
vector<int> rb[maxn];
bool pm[maxn];

int getroot(int u) {
	return(snm[u] == u ? u : snm[u] = getroot(snm[u]));
}

void merge(int u, int v) {
	u = getroot(u), v = getroot(v);
	if(u == v) {
		return;
	}
	snm[v] = u;
	d[u] = max(d[u] - d[u] / 2 + d[v] - d[v] / 2 + 1, max(d[u], d[v]));
}

void dfs(int u) {
	pm[u] = 1;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(pm[v]) continue;
		dfs(v);
		merge(u, v);
	}
}

pair<int, int> getfarest(int u, int p = -1, int d = 0) {
	pair<int, int> ret = mp(d, u);
	for(int i = 0; i < (int) rb[u].size(); i++) {
		int v = rb[u][i];
		if(v == p) continue;
		ret = max(ret, getfarest(v, u, d + 1));
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

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < n; i++) {
		snm[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v);
		rb[v].pb(u);
	}

	for(int i = 0; i < n; i++) {
		if(!pm[i]) {
			dfs(i);
			d[i] = getfarest(getfarest(i).sc).fs;
//			cout << d[i] << " ";
		}
	}

	for(int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if(t == 1) {
			int u;
			scanf("%d", &u);
			printf("%d\n", d[getroot(--u)]);
		} else {
			int u, v;
			scanf("%d%d", &u, &v);
			u = getroot(--u), v = getroot(--v);
			merge(u, v);
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