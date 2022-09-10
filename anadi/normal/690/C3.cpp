#include <bits/stdc++.h>

using namespace std;

const int mxn = 2e5 + 7;
const int mxt = 2e6 + 9;

vector <int> V[mxn];
int drzewko[mxt];
int last[mxn];
int firs[mxn];
int pre[mxn];
int Rev_Pre[mxn];
int czas = 0;
int K = 1;
int nr = 1;
int level[mxn];

void dfs(int u){
	pre[u] = nr;
	Rev_Pre[nr++] = u;
	firs[u] = ++czas;
	drzewko[czas] = pre[u];
	
	for(int i = 0; i < V[u].size(); ++i){
		level[V[u][i]] = level[u] + 1;
		dfs(V[u][i]);
		drzewko[++czas] = pre[u];
	}

	last[u] = czas;
}

void tree(){
	for(int i = K - 1; i >= 1; --i)
		drzewko[i] = min(drzewko[2 * i], drzewko[2 * i + 1]);
}

int lca(int a, int b){
	int from = min(firs[a], firs[b]);
	int to = max(last[a], last[b]);
	int result = mxn;
	
	while(from < to){
		if(from % 2 == 1){
			result = min(result, drzewko[from]);
			++from;
		}
		if(to % 2 == 0){
			result = min(result, drzewko[to]);
			--to;
		}
		
		from /= 2;
		to /= 2;
	}
	
	if(from == to)
		result = min(result, drzewko[from]);
	
	return level[a] + level[b] - 2 * level[Rev_Pre[result]];
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		int a;
		scanf("%d", &a);
		V[a].push_back(i);
	}
	
	while(K < (2 * n - 1))
		K *= 2;
	
	czas = K - 1;
	dfs(1);
	tree();
	
	int result = 0;
	int a1 = 1;
	int a2 = 1;
	for(int i = 1; i < n; ++i){
		int d1 = lca(a1, i + 1);
		int d2 = lca(a2, i + 1);
		if(d2 > d1){
			swap(a2, a1);
			swap(d2, d1);
		}
		
		if(d1 > result){
			result = d1;
			a2 = i + 1;
		}
		
		printf("%d\n", result);
	}

	return 0;
}