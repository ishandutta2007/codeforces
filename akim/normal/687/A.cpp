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
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
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

vector<int> rb[maxn];
bool pm[maxn];
int color[maxn];
bool ok = 1;

void dfs(int u, int col = 0) {
	pm[u] = 1;
	color[u] = col;
	for(int i = 0; i < (int)rb[u].size(); i++) {
		int v = rb[u][i];
		if(pm[v]) {
			if(color[v] == color[u]) {
				ok = 0;
			}
			continue;
		}
		dfs(v, 1 - col);
	}
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
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		rb[u].pb(v), rb[v].pb(u);
	}

	for(int i = 0; i < n; i++) {
		if(!pm[i]) {
			dfs(i);
		}
	}

	int c0 = 0, c1 = 0;
	for(int i = 0; i < n; i++) {
		if(color[i] == 0) {
			c0++;
		} else {
			c1++;
		}
	}

	if(!ok) {
		printf("-1");
		return(0);
	}

	printf("%d\n", c0);
	for(int i = 0; i < n; i++) {
		if(color[i] == 0) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");

	printf("%d\n", c1);
	for(int i = 0; i < n; i++) {
		if(color[i] == 1) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");

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