#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLD pair <LD, LD>
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int N = 1e5 + 9;

int n;
LD dp[N];
int pod[N];
vector <int> V[N];

int dfs(int u){
	for(int i = 0; i < V[u].size(); ++i)
		pod[u] += dfs(V[u][i]);
	return pod[u] + 1;
}

void DFS(int u){
	for(int i = 0; i < V[u].size(); ++i){
		dp[V[u][i]] = ((LD)(pod[u] - pod[V[u][i]] - 1)) / 2.0 + dp[u] + 1.0;
		DFS(V[u][i]);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		int a;
		scanf("%d", &a);
		V[a].pb(i);
	}
	
	dfs(1);
	DFS(1);

	for(int i = 1; i <= n; ++i)
		printf("%.6lf ", dp[i] + 1.0);
	return 0;
}