#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5007;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, s;
bool reach[N][N];
vector <int> G[N];

int t;
void dfs(int u){
	reach[t][u] = true;
	for(int v: G[u])
		if(!reach[t][v])
			dfs(v);
}

int main(){
//	ios_base::sync_with_stdio(false);
	cin >> n >> m >> s;
	
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
	}
	
	priority_queue <PII> Q;
	for(int i = 1; i <= n; ++i){
		t = i;
		dfs(i);
		
		int sum = 0;
		for(int j = 1; j <= n; ++j)
			sum += reach[i][j];
		Q.push({sum, i});
	}
	
	int res = 0;
	while(!Q.empty()){
		int u = Q.top().nd;
		Q.pop();
		
		if(reach[s][u])
			continue;
		
		++res;
		for(int i = 1; i <= n; ++i)
			reach[s][i] |= reach[u][i];
	}
	
	printf("%d\n", res);
	return 0;
}