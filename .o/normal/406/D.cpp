#define _CRT_SECURE_NO_WARNINGS

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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 100005;

int N; ll X[N_], Y[N_];
int R[N_];
vector<int> stk;
vector<int> Gph[N_];
int parent[18][N_], depth[N_];

void DFS (int u) {
	for(int i = 0; i < Gph[u].size(); i++) {
		int v = Gph[u][i];
		depth[v] = depth[u] + 1;
		for(int k = 1; k < 18; k++) parent[k][v] = parent[k-1][ parent[k-1][v] ];
		DFS(v);
	}
}

int lca (int x, int y) {
	if(depth[x] < depth[y]) swap(x, y);
	for(int k = 0; k < 18; k++) if((depth[x] - depth[y]) & (1 << k)) x = parent[k][x];
	for(int k = 17; k >= 0; k--) if(parent[k][x] != parent[k][y]) x = parent[k][x], y = parent[k][y];
	return x == y ? x : parent[0][x];
}

int Q;

int main() {

	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%I64d%I64d", X+i, Y+i);
	
	stk.reserve(N);
	stk.push_back(N);

	for(int i = N-1; i > 0; i--) {
		while(stk.size() >= 2) {
			int t1 = stk[stk.size() - 1];
			int t2 = stk[stk.size() - 2];
			if((Y[t2] - Y[t1]) * (X[t1] - X[i]) > (Y[t1] - Y[i]) * (X[t2] - X[t1])) {
				stk.pop_back();
			}else {
				break;
			}
		}
		if(!stk.empty()) {
			parent[0][i] = stk.back();
			Gph[stk.back()].push_back(i);
		}
		stk.push_back(i);
	}

	DFS(N);

	scanf("%d", &Q);
	while(Q--) {
		int a, b; scanf("%d%d", &a, &b);
		printf("%d ", lca(a, b));
	}

	return 0;
}