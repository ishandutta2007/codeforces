#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 607;
const int M = N + N;

int n, m, k;
int deg[N];
int edge[N][2];

int d[M];
queue <int> Q;

int res[N];
int cap[M][M];
int flow[M][M];
vector <int> G[M];

void addEdge(int u, int v, int c){
	G[u].push_back(v);
	G[v].push_back(u);

	cap[u][v] = c;
	flow[v][u] = cap[v][u] = c;
}

bool bfs(){
	for(int i = 0; i <= n + m + 1; ++i)
		d[i] = -1;
	d[0] = 0;
	
	Q.push(0);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(int v: G[u])
			if(d[v] == -1 && flow[u][v] < cap[u][v]){
				Q.push(v);
				d[v] = u;
			}
	}
	
	return d[n + m + 1] != -1;
}

void Flow(){
	while(bfs()){
		int t = n + m + 1;
		while(t != 0){
			flow[d[t]][t]++;
			flow[t][d[t]]--;
			t = d[t];
		}
	}
}

void solve(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < N; ++i)
		deg[i] = 0, res[i] = 0;
	
	for(int i = 0; i <= n + m + 1; ++i){
		for(int j = 0; j <= n + m + 1; ++j)
			cap[i][j] = flow[i][j] = 0;
		G[i].clear();
	}
	
	for(int i = 1; i <= m; ++i){
		scanf("%d %d", &edge[i][0], &edge[i][1]);
		deg[edge[i][0]]++, deg[edge[i][1]]++;

		addEdge(edge[i][0], n + i, 1);
		addEdge(edge[i][1], n + i, 1);
		addEdge(n + i, n + m + 1, 1);
	}
	
	for(int i = 1; i <= n; ++i){
		if(deg[i] > 2 * k){
			for(int j = 1; j <= m; ++j)
				printf("0 ");
			puts("");
			return;
		}
		
		addEdge(0, i, max(0, 2 * (deg[i] - k)));
	}
	
	Flow(); int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(flow[0][i] < 2 * (deg[i] - k)){
			for(int j = 1; j <= m; ++j)
				printf("0 ");
			puts("");
			return;			
		}
		
		vector <int> e;
		for(int v: G[i])
			if(flow[i][v] == cap[i][v] && v > 0){
				e.push_back(v - n);
//				printf("%d ", v);
			}
//		puts("");
		for(int j = 0; j < e.size(); j += 2)
			res[e[j]] = res[e[j + 1]] = ++cnt;
	}
	
	for(int i = 1; i <= m; ++i){
		if(res[i] == 0)
			res[i] = ++cnt;
		printf("%d ", res[i]);
	}
	
	puts("");
}

int main(){
	int cases;
	scanf("%d", &cases);
	
	while(cases--)
		solve();
	return 0;
}