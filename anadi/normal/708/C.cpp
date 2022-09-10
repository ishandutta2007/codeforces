#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PDD pair <D, D>
#define pb push_back

const int N = 4e5 + 7;
const LL INF = 100000000000000000LL;

int n;
vector <int> V[N];
int pod[N];
int ans[N];
int ile = 0;
int centroid = 0;
int mx, mx2;
int half = n / 2;

void dfs(int u, int p){
	bool ok = true;
	pod[u] = 1;
	
	for(int i = 0; i < V[u].size(); ++i)
		if(V[u][i] != p){
			dfs(V[u][i], u);
			if(pod[V[u][i]] > half)
				ok = false;
			pod[u] += pod[V[u][i]];
		}
	
	if(n - pod[u] > half)
		ok = false;
	if(ok){
		++ile;
		centroid = u;
	}
}

int DFS(int v, int p){
	pod[v] = 1;
	
	for(auto i: V[v])
		if(i != p)
			pod[v] += DFS(i, v);
	return pod[v];
}

void wyn(int u, int p, int t){
	if(t == mx)
		n - pod[u] - pod[mx2] <= half ? ans[u] = 1 : ans[u] = 0;
	else
		n - pod[u] - pod[mx] <= half ? ans[u] = 1 : ans[u] = 0;
	for(auto i: V[u])
		if(i != p)
			wyn(i, u, t);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		V[a].pb(b);
		V[b].pb(a);
	}
	
	half = n / 2;
	dfs(1, 1);
	
	if(ile == 2){
		for(int i = 1; i <= n; ++i)
			printf("1 ");
		return 0;
	}
	
	DFS(centroid, centroid);
	if(pod[V[centroid][0]] > pod[V[centroid][1]])
		mx2 = 1;
	else
		mx = 1;
	
	for(int i = 2; i < V[centroid].size(); ++i){
		if(pod[V[centroid][i]] > pod[V[centroid][mx]]){
			mx2 = mx;
			mx = i;
		}
		else if(pod[V[centroid][i]] > pod[V[centroid][mx2]])
			mx2 = i;
	}
	
	mx = V[centroid][mx];
	mx2 = V[centroid][mx2];

	for(auto i: V[centroid])
		wyn(i, centroid, i);
	
	ans[centroid] = 1;
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}