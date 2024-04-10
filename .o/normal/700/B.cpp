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

const int N_ = 200500, lgN_ = 18;

int N, K;
int U[N_];
int par[N_][lgN_];
int in[N_], TIME;

int level[N_];

vector<int> gph[N_];

void dfs (int u, int p = 0) {
	par[u][0] = p;
	in[u] = ++TIME;
	for(auto v : gph[u]) if(v != p) {
		level[v] = level[u] + 1;
		dfs(v, u);
	}
}

int lca (int u, int v) {
	if(level[u] > level[v]) swap(u, v);
	for(int k = lgN_; --k >= 0; ) {
		if(((level[v] - level[u]) >> k) & 1) {
			v = par[v][k];
		}
	}
	if(u == v) return u;
	for(int k = lgN_; --k >= 0; ) {
		if(par[u][k] != par[v][k]) {
			u = par[u][k];
			v = par[v][k];
		}
	}
	return par[u][0];
}
int main() {
    scanf("%d%d", &N, &K);
    for(int i = 1; i <= K+K; i++) scanf("%d", U+i);

    for(int i = 1; i < N; i++) {
    	int u, v; scanf("%d%d", &u, &v);
    	gph[u].push_back(v);
    	gph[v].push_back(u);
    }

    dfs(1);

    sort(U+1, U+K+K+1, [](const int &a, const int &b) {
    	return in[a] < in[b];
    });


    for(int k = 1; k < lgN_; k++) {
    	for(int i = 1; i <= N; i++)
    		par[i][k] = par[par[i][k-1]][k-1];
    }

    ll ans = 0;

    for(int i = 1; i <= K; i++)
    	ans += level[U[i]] + level[U[i+K]] - 2 * level[lca(U[i], U[i+K])];

	printf("%lld\n", ans);
	return 0;
}