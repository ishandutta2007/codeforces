#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define pb push_back
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second

const int N = 1007;

int n, m, k;
int licz;
int ver[N];
int edge[N];
bool vis[N];
vector <int> gov;
vector <int> G[N];

void dfs(int u){
	vis[u] = true;
	ver[licz]++;
	edge[licz] += G[u].size();
	
	for(auto v: G[u])
		if(!vis[v])
			dfs(v);
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= k; ++i){
		int a;
		scanf("%d", &a);
		gov.pb(a);
	}
	
	for(int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].pb(b);
		G[b].pb(a);
	}
	
	for(auto v: gov){
		++licz;
		dfs(v);
		edge[licz] /= 2;
	}

	int res = 0;
	int max_s = 0;
	int summ = n;
	int edges = m;
	for(int i = 1; i <= k; ++i){
		res += ver[i] * (ver[i] - 1) / 2 - edge[i];
		summ -= ver[i];
		max_s = max(max_s, ver[i]);
		edges -= edge[i];
	}
	
	res += summ * max_s;
	res += summ * (summ - 1) / 2 - edges;
	printf("%d\n", res);
	return 0;
}