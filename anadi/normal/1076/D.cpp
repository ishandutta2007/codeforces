#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m, k;
vector <int> res;

PII p[N];
LL dist[N];
bool vis[N];
vector <PII> T[N];
vector <pair <PII, int> > G[N];

void Dijkstra(int s){
	for(int i = 1; i <= n; ++i)
		dist[i] = INF;
	dist[s] = 0;
	
	priority_queue <PLL> Q;
	Q.push({0, s});
	
	while(!Q.empty()){
		int u = Q.top().nd;
		Q.pop();
		
		if(vis[u])
			continue;
		vis[u] = true;
		
		if(p[u].st > 0)
			T[p[u].st].push_back({u, p[u].nd});
		
		for(auto v: G[u])
			if(dist[v.st.st] > dist[u] + v.st.nd){
				dist[v.st.st] = dist[u] + v.st.nd;
				p[v.st.st] = {u, v.nd};
				Q.push({-dist[v.st.st], v.st.st});
			}
	}
}

void dfs(int u){
	for(auto v: T[u]){
		if((int)res.size() < k)
			res.push_back(v.nd);
		dfs(v.st);
	}
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);

	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);

		G[u].push_back({{v, c}, i});
		G[v].push_back({{u, c}, i});
	}
	
	Dijkstra(1);
	dfs(1);
	
	printf("%d\n", (int)res.size());
	for(int v: res)
		printf("%d ", v);
	return 0;
}