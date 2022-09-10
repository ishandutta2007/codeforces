#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;

int bit;
int n, m;
int d[N][2];
int choose[40];
vector <PII> G[N];

void dfs(int u, bool x){
	for(PII v: G[u]){
		bool cur = (v.nd & bit) ? 1 : 0;
		if(d[v.st][x ^ cur] == -1){
			d[v.st][x ^ cur] = d[u][x] ^ v.nd;
			dfs(v.st, x ^ cur);
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		G[u].pb({v, c});
		G[v].pb({u, c});
	}
	
	for(int i = 26; i >= 0; --i){
		for(int j = 1; j <= n; ++j)
			d[j][0] = d[j][1] = -1;
		d[1][0] = 0;
		
		bit = 1 << i;
		dfs(1, 0);
		choose[i] = d[1][1];
		
		if(choose[i] == -1)
			continue;
		
		for(int xd = 1; xd <= n; ++xd)
			for(int j = 0; j < int(G[xd].size()); ++j)
				if((G[xd][j].nd ^ choose[i]) < G[xd][j].nd)
					G[xd][j].nd ^= choose[i];
	}
	
	int res = max(d[n][0], d[n][1]);
	for(int i = 26; i >= 0; --i)
		if(choose[i] != -1 && (res & (1 << i)))
			res ^= choose[i];
	printf("%d\n", res);
	return 0;
}