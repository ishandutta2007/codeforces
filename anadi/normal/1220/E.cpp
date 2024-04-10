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
int score[N];
long long ans = 0;

int s;
int deg[N];
LL best[N];
vector <int> G[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &score[i]);
		ans += score[i];
	}

	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	scanf("%d", &s);
	G[s].push_back(s);
	G[s].push_back(s);

	queue <int> Q;
	for(int i = 1; i <= n; ++i){
		deg[i] = G[i].size();
		if(deg[i] == 1){
			best[i] = score[i];
			Q.push(i);
		}
	}
	
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		ans -= score[u];
		for(auto v: G[u]){
			deg[v]--;
			if(deg[v] > 0)
				best[v] = max(best[v], best[u] + score[v]);
			
			if(deg[v] == 1)
				Q.push(v);
		}
	}
	
	LL tmp = 0;
	for(int i = 1; i <= n; ++i)
		if(deg[i] <= 1)
			tmp = max(tmp, best[i]);
	
	printf("%lld\n", ans + tmp);
	return 0;
}