#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
LL ileX, ileY;
vector <int> G[N];

void dfs(int u, int p, int col){
	if(col)
		ileX++;
	else
		ileY++;
	
	for(int v: G[u])
		if(v != p)
			dfs(v, u, col ^ 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	dfs(1, 0, 0);
	printf("%lld\n", ileX * ileY - n + 1);
	return 0;
}