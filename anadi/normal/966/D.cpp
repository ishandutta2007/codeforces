#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
int d[N];
int p[N];
vector <int> res;
vector <int> G[N];
vector <int> G2[N];

void bfs(){
	queue <int> Q;
	for(int i = 1; i <= n; ++i)
		d[i] = -1;
	d[1] = 0;

	Q.push(1);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		
		for(int v: G[u])
			if(d[v] == -1){
				p[v] = u;
				d[v] = d[u] + 1;
				Q.push(v);
			}
	}
}

int cnt, sum;
bool vis[N];

void dfs(int u){
	vis[u] = true;
	++cnt, sum += G2[u].size();
	
	for(int v: G2[u])
		if(!vis[v])
			dfs(v);
}

vector <int> myGraph;
void dfs2(int u){
	vis[u] = false;
	for(int v: G2[u])
		if(vis[v])
			dfs2(v);
	myGraph.pb(u);
}

void bfs2(int s){
	for(int i = 1; i <= n; ++i)
		d[i] = -1;
	d[s] = 0;
	
	queue <int> Q;
	Q.push(s);
	
	while(!Q.empty()){
		int u = Q.front();
//		printf("%d ", u);
		Q.pop();
		
		for(int v: G2[u])
			if(d[v] == -1){
				d[v] = d[u] + 1;
				p[v] = u;
				Q.push(v);
			}
	}
}

void getAns(int u){
	dfs2(u);
	for(int v: myGraph)
		if(G2[v].size() + 1 < myGraph.size())
			u = v;

	bfs2(u);
	for(int v: myGraph)
		if(d[v] == 2){
			res = {1, u, p[v], v, u, n};
			break;
		}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
		
		if(u != 1 && v != 1){
			G2[u].push_back(v);
			G2[v].push_back(u);
		}
	}
	
	bfs();
	if(d[n] >= 0 && d[n] <= 4){
		int t = n;
		while(t != 1){
			res.push_back(t);
			t = p[t];
		}
		
		res.push_back(1);
		reverse(res.begin(), res.end());
	}
	
	int t = -1;
	for(int i = 2; i < n; ++i)
		if(d[i] == 2)
			t = i;
	
	if(t != -1){
		vector <int> maybe = {1, p[t], t, 1, n};
		if(maybe.size() < res.size() || res.size() == 0)
			res = maybe;
	}
	else if(res.size() == 0){
		for(int i = 2; i < n; ++i)
			if(!vis[i] && d[i] == 1){
				sum = 0, cnt = 0;
				dfs(i);
				
				if(1LL * cnt * (cnt - 1) == sum)
					continue;
				
				getAns(i);
				break;
			}
	}
	
	if(res.size() == 0){
		puts("-1");
		return 0;
	}
	
	printf("%d\n", int(res.size()) - 1);
	for(int v: res)
		printf("%d ", v);
	return 0;
}