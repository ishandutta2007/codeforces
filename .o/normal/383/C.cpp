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

const int N_ = 200505, Q_ = 200505;
int N, Q;
int V[N_];
vector<int> Gph[N_];
int Level[N_], R[N_], E[N_], TIME;
bool visited[N_];

void dfs (int u, int l = 0) {
	R[u] = ++TIME; visited[u] = 1; Level[u] = l;
	for(int e = 0; e < Gph[u].size(); e++) {
		int v = Gph[u][e];
		if(!visited[v]) dfs(v, l+1);
	}
	E[u] = TIME;
}

const int LEAF = 1<<18;
int Tree[2][N_+LEAF];

int get (int t, int x) {
	int ret = 0;
	for(x += LEAF; x > 0; x >>= 1) ret += Tree[t][x];
	return ret;
}

void update (int t, int x, int y, int d) {
	for(x += LEAF, y += LEAF; x <= y; ) {
		if((x & 1) == 1) Tree[t][x] += d;
		if((y & 1) == 0) Tree[t][y] += d;
		x = (x+1) >> 1;
		y = (y-1) >> 1;
	}
}

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", V+i);
	for(int i = 1; i <= N-1; i++) {
		int u, v; scanf("%d%d", &u, &v);
		Gph[u].push_back(v);
		Gph[v].push_back(u);
	}

	dfs(1);

	for(int i = 1; i <= N; i++) Tree[Level[i]&1][R[i]+LEAF] = V[i];

	while(Q--) {
		int q, u; scanf("%d%d", &q, &u);
		if(q == 1) {
			int val; scanf("%d", &val);
			update(Level[u] & 1, R[u], E[u], +val);
			update(!(Level[u] & 1), R[u], E[u], -val);
		}else {
			printf("%d\n", get(Level[u]&1, R[u]));
		}
	}
	return 0;
}