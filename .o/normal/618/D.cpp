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

const int N_ = 200500;
int N; ll X, Y;
vector<int> gph[N_];
ll ans = (ll)1e18;

int solve (int u, int p, int &x) {
	int ch = 0;
	for(auto v : gph[u]) {
		if(v == p) continue;
		ch += solve(v, u, x);
	}
	if(ch >= 2) {
		x += (p > 0) ? (ch-1) : (ch-2);
		return 0;
	}else {
		return 1;
	}
}

int main() {
	scanf("%d%lld%lld", &N, &X, &Y); // X : tree, Y: others
	for(int e = 1; e < N; e++) {
		int u, v; scanf("%d%d", &u, &v);
		gph[u].push_back(v);
		gph[v].push_back(u);
	}

	if(N <= 10 && 0) {
		bool adj[15][15];
		memset(adj, 0, sizeof adj);
		for(int u = 1; u <= N; u++) {
			for(auto v : gph[u]) adj[u][v] = true;
		}

		int P[15];
		for(int u = 1; u <= N; u++) P[u] = u;

		do {
			ll val = 0;
			for(int i = 2; i <= N; i++) val += (adj[P[i-1]][P[i]]) ? X : Y;
			ans = min(ans, val);
		}while(next_permutation(P+1, P+N+1));

	}else {
		if(X < Y) {
			int y = 0; solve(1, -1, y);
			int x = N-1-y;
			ans = X * x + Y * y;
		}else if(X >= Y) {
			ans = Y * (N-1);
			for(int u = 1; u <= N; u++) {
				if(gph[u].size() == N-1) ans = Y * (N-2) + X;
			}
		}
	}

	printf("%I64d\n", ans);

    return 0;
}