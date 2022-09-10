#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
int color[N];
vector <int> G[N];

void dfs(int u, int p){
	for(auto v: G[u])
		if(v != p){
			color[v] = color[u] ^ 1;
			dfs(v, u);
		}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	set <int> cols;
	for(int i = 1; i <= n; ++i)
		if(G[i].size() == 1)
			cols.insert(color[i]);
	
	if(cols.size() == 1)
		printf("1 ");
	else
		printf("3 ");
	
	int ans = n - 1;
	for(int i = 1; i <= n; ++i){
		int nbh = 0;
		for(auto v: G[i])
			nbh += G[v].size() == 1;
		
		if(nbh > 0)
			ans -= nbh - 1;
	}
	
	printf("%d\n", ans);
	return 0;
}