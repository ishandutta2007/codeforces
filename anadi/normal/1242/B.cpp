#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m;
set <int> S;
vector <int> G[N];

void dfs(int u){
	S.erase(u);
	for(int i = 0; i + 1 < (int)G[u].size(); ++i){
		int v = G[u][i], nxt = G[u][i + 1];
		auto it = S.upper_bound(v);
		if(it == S.end() || *it >= nxt)
			continue;

		dfs(*it);
		--i;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		G[i].push_back(0);

	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; ++i){
		S.insert(i);
		G[i].push_back(n + 1);
		sort(G[i].begin(), G[i].end());
	}
	
	int ans = -1;
	while(S.size()){
		auto it = *S.begin();
		dfs(it);
		++ans;
	}
	
	printf("%d\n", ans);
	return 0;
}