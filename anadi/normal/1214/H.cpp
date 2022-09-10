#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;

int n, k;
int ans[N];
vector <int> G[N];

int par[N];
int dist[N];
bool onPath[N];
vector <int> path;

void nie(){
	puts("No");
	exit(0);
}

void write(){
	puts("Yes");
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	puts("");
	exit(0);
}

void solveTwo(int u, int p){
	for(auto v: G[u])
		if(v != p){
			ans[v] = ans[u] ^ 3;
			solveTwo(v, u);
		}
}

int maxDepth = 0;
void solveSubtree(int u, int p, int dir, int d){
	ans[u] = (ans[p] - 1 + dir + k) % k + 1;
	maxDepth = max(maxDepth, d);

	for(auto v: G[u])
		if(v != p)
			solveSubtree(v, u, dir, d + 1);
}

void dfs(int u, int p, int d){
	dist[u] = d;
	par[u] = p;
	
	for(auto v: G[u])
		if(v != p)
			dfs(v, u, d + 1);
}

void getPath(){
	dfs(1, 0, 0);
	int best = 1;

	for(int i = 1; i <= n; ++i)
		if(dist[i] > dist[best])
			best = i;
	
	dfs(best, 0, 0);
	best = 1;
	
	for(int i = 1; i <= n; ++i)
		if(dist[i] > dist[best])
			best = i;
	
	while(best != 0){
		onPath[best] = true;
		path.push_back(best);
		best = par[best];
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if(k == 2){
		ans[1] = 1;
		solveTwo(1, 0);
		write();
	}

	getPath();
	if(path.size() < k){
		for(int i = 1; i <= n; ++i)
			ans[i] = 1;
		write();
	}
	
	for(int i = 0; i < (int)path.size(); ++i)
		ans[path[i]] = i % k + 1;
	
	int Left = 0, Right = path.size();
	for(auto u: path){
		++Left;
		for(auto v: G[u]){
			if(onPath[v])
				continue;
			
			maxDepth = 0;
			if(Left < Right)
				solveSubtree(v, u, -1, 1);
			else
				solveSubtree(v, u, 1, 1);

			if(maxDepth + Left >= k && maxDepth + Right >= k)
				nie();
		}
		
		--Right;
	}
	
	write();
	return 0;
}