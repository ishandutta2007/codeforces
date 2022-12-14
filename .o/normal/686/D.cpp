#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <unordered_set>
 #include <cfloat>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 300500;

const int lgN_ = 19;

int N, Q;
vector<int> gph[N_];
int sz[N_];
int nxt[lgN_][N_];
int ans[N_];
// centroid:   ,      (?)


void dfs (int u) {
	sz[u] = 1;

	int x = 0;
	for(auto v : gph[u]) {
		dfs(v);
		if(sz[v] > sz[x]) x = v;
		sz[u] += sz[v];
	}

	nxt[0][u] = x;
	for(int p = 1; p < lgN_; p++) 
		nxt[p][u] = nxt[p-1][nxt[p-1][u]];

	if(x == 0) {
		ans[u] = u;
		return;
	}

	// ans
	int target = sz[u] / 2;
	if(sz[x] <= target) {
		ans[u] = u;
	}else {
		for(int p = lgN_-1; p >= 0; p--) {
			int y = nxt[p][x];
			if(target < sz[y]) x = y;
		}
		ans[u] = x;
	}
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int u = 2; u <= N; u++) {
		int p; scanf("%d", &p);
		gph[p].push_back(u);
	}

	dfs(1);

	while(Q--) {
		int u; scanf("%d", &u);
		printf("%d\n", ans[u]);
	}


	return 0;
}