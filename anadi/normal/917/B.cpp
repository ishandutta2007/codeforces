#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

const int N = 107;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int edge[N][N];
int dp[N][N][30];

bool solve(int u, int v, int last){
	if(dp[u][v][last] != 0)
		return dp[u][v][last] == 2;
	
	bool canWin = false;
	for(int i = 1; i <= n; ++i)
		if(edge[u][i] < INF && last <= edge[u][i])
			canWin |= !solve(v, i, edge[u][i]);
	
	dp[u][v][last] = canWin ? 2 : 1;
	return dp[u][v][last] == 2;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			edge[i][j] = INF;

	for(int i = 1; i <= m; ++i){
		int u, v;
		char c;
		scanf("%d %d %c", &u, &v, &c);
		edge[u][v] = c - 'a';
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j)
			if(solve(i, j, 0))
				printf("A");
			else
				printf("B");
		puts("");
	}

	return 0;
}