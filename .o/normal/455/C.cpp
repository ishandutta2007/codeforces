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

const int N_ = 305005;

int N, M, Q;
vector<int> Gph[N_];

bool visited[N_];
int rec[N_];
int grp[N_];

void dfs (int u, int p, int r, int d, int &mxd, int &mxp) {
	visited[u] = true;
	if(r > 0) grp[u] = r; 
	if(d > mxd) mxd = d, mxp = u;
	for(int e = 0; e < Gph[u].size(); e++) {
		int v= Gph[u][e];
		if(v != p) dfs(v, u, r, d+1, mxd, mxp), rec[v] = u;
	}
}

vector<int> paths[N_];

int find_group (int u) {
	return (grp[u] == u) ? u : (grp[u] = find_group(grp[u]));
}

vector<int>* path_ptrs[N_];

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for(int i = 1; i <= M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		Gph[u].push_back(v);
		Gph[v].push_back(u);
	}
	
	for(int i = 1; i <= N; i++) grp[i] = i;
	for(int i = 1; i <= N; i++) if(!visited[i]) {
		int mxd = -1, mxp = -1;
		dfs(i, -1, i, 0, mxd, mxp);
		int u = mxp;
		
		mxd = mxp = -1;
		dfs(u, -1, -1, 0, mxd, mxp);
		int v = mxp;

		for(; u != v; v = rec[v]) paths[i].push_back(v);
		paths[i].push_back(u);
		path_ptrs[i] = &paths[i];
	}

	while(Q--) {
		int type; scanf("%d", &type);
		if(type == 1) {
			int x; scanf("%d", &x);
			printf("%d\n", path_ptrs[find_group(x)]->size() - 1);
		}else {
			int x,y; scanf("%d%d", &x, &y);
			x = find_group(x);
			y = find_group(y);

			if(x != y) {
				vector<int>* pthx = path_ptrs[x];
				vector<int>* pthy = path_ptrs[y];
				if(pthx->size() > pthy->size()) {
					swap(path_ptrs[x], path_ptrs[y]);
					swap(pthx, pthy);
				}

				int dx = pthx->size()-1, dy = pthy->size()-1;
				int lx = dx / 2 + dx % 2, ly = dy / 2 + dy % 2;
				int l = lx + ly + 1;

				if(l > dy) {
					pthy->resize(l + 1);
					for(int i = 0; i <= lx; i++) (*pthy)[ly+1+i] = (*pthx)[lx-i];
				}

				pthx->clear();
				grp[x] = y;
			}
		}
	}

	return 0;
}