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

const int N_ = 100005;
int N;
vector<int> Tree[N_];
ll V[N_], D[N_];
ll res;

ll Table[N_][2];

void DFS (int u, int p) {
	for(int i = 0; i < Tree[u].size(); i++) {
		int v = Tree[u][i];
		if(v != p) {
			DFS(v, u);
			Table[u][0] = max(Table[u][0], Table[v][0]);
			Table[u][1] = max(Table[u][1], Table[v][1]);
		}
	}

	V[u] -= Table[u][0] - Table[u][1];
	if(V[u] > 0) Table[u][0] += V[u];
	else Table[u][1] -= V[u];
}

int main() {
	int i, j, k;

	scanf("%d", &N);
	
	for(i = 1; i < N; i++) {
		int u, v; scanf("%d%d", &u, &v);
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	for(i = 1; i <= N; i++) scanf("%I64d", V+i);

	if(N == 1) {
		printf("%I64d\n", abs(V[1]));
		return 0;
	}

	DFS(1, 0);

	printf("%I64d\n", Table[1][0]+Table[1][1]);
	return 0;
}