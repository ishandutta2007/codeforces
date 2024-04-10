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
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, Q;
const int lgN_ = 17, N_ = 100500;
vector<int> gph[N_];


int parent[lgN_][N_];
int level[N_];
int dfn[N_], tour[N_], out[N_], TIME;

void dfs (int u, int p = -1) {
	dfn[u] = ++TIME;
	tour[TIME] = u;
	for(auto v : gph[u]) if(v != p) {
		parent[0][v] = u;
		for(int k = 1; k < lgN_; k++) 
			parent[k][v] = parent[k-1][parent[k-1][v]];
		level[v] = level[u] + 1;

		dfs(v, u);
	}
	out[u] = TIME;
}

int lca (int u, int v) {
	if(level[u] > level[v]) swap(u, v);
	for(int k = lgN_; --k >= 0; ) {
		if(((level[v] - level[u]) >> k) & 1)
			v = parent[k][v];
	}
	if(u == v) return u;

	for(int k = lgN_; --k >= 0; ) {
		if(parent[k][u] != parent[k][v])
			u = parent[k][u], v = parent[k][v];
	}

	return parent[0][u];
}

ll tb[N_][2];
const ll INF = (int)1e7;
vector<int> compressed_gph[N_];
bool is_imp[N_];
bool chk[N_];

int ans;

int solve (int u) {
	int bad = 0;
	for(auto v : compressed_gph[u]) {
		bad += solve(v);
	}
	if(is_imp[u]) {
		ans += bad;
		return 1;
	}
	if(bad <= 1) {
		return bad;
	}
	ans += 1;
	return 0;
}

int main() {
	scanf("%d", &N);
	for(int e = 1; e <= N-1; e++) {
		int u, v; scanf("%d%d", &u, &v);
		gph[u].push_back(v);
		gph[v].push_back(u);
	}

	dfs(1);

	scanf("%d", &Q);
	while(Q--) {
		int k; scanf("%d", &k);
		vector<int> imp(k);
		for(auto &u : imp) scanf("%d", &u), is_imp[u] = chk[u] = true;
		sort(imp.begin(), imp.end(), [](const int &u, const int &v) {
			return dfn[u] < dfn[v];
		});

		vector<int> compressed_vertices = imp;
		for(int i = 0; i+1 < imp.size(); i++) {
			compressed_vertices.push_back(lca(imp[i], imp[i+1]));
		}
		compressed_vertices.push_back(1);

		sort(compressed_vertices.begin(), compressed_vertices.end(), [](const int &u, const int &v) {
			return dfn[u] < dfn[v];
		});
		compressed_vertices.resize(
			unique(compressed_vertices.begin(), compressed_vertices.end()) 
			- compressed_vertices.begin()
		);

		ans = 0;
		
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		for(int u : compressed_vertices) {
			while(!pq.empty()) {
				pii t = pq.top(); 
				if(dfn[u] <= t.first) {
					int p = tour[-t.second];
					compressed_gph[p].push_back(u);
					if(level[u] - level[p] == 1 && is_imp[u] && is_imp[p]) ans = -1;
					break;
				}else {
					pq.pop();
				}
			}
			pq.push(pii(out[u], -dfn[u]));
		}


		if(ans != -1) {
			solve(1);
		}

		printf("%d\n", ans);

		for(int u : compressed_vertices) {
			compressed_gph[u].clear();
			chk[u] = is_imp[u] = false;
		}
		ans = 0;
	}
    return 0;
}