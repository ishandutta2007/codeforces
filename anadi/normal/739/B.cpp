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

int n;
int val[N];
LL dist[N];
vector <PII> G[N];

int add[N];
int cur[N];

void dfs(int u, int d){
	cur[d] = u;
	add[cur[d - 1]]++;
	int p = 1, k = d;
	
	while(p < k){
		int m = (p + k) >> 1;
		if(dist[cur[m]] >= dist[u] - val[u])
			k = m;
		else
			p = m + 1;
	}
	
	add[cur[p - 1]]--;
	for(auto v: G[u]){
		dist[v.st] = dist[u] + v.nd;
		dfs(v.st, d + 1);
		add[u] += add[v.st];
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	
	for(int i = 2; i <= n; ++i){
		int p, w;
		scanf("%d %d", &p, &w);
		G[p].push_back({i, w});
	}
	
	dfs(1, 1);
	for(int i = 1; i <= n; ++i)
		printf("%d ", add[i]);
	return 0;
}