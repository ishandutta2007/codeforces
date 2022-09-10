#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int d[N];
int pod[N];

int res;
int val[N];
int color[2];
vector <int> G[N];

void dfs(int u, int p, int c){
	color[c]++;
	for(int v: G[u])
		if(v != p)
			dfs(v, u, c ^ 1);
}

void dodaj(int v, int a, int b){
	res = (res + (((1LL * v * a)%MX) * b)%MX)%MX;
}

void find(int u, int p, int c){
	pod[u] = 1;
	for(int v: G[u]){
		if(v == p)
			continue;

		find(v, u, c ^ 1);
		pod[u] += pod[v];
		d[u] += pod[v] - d[v];
	}
	
	for(int v: G[u])
		if(v != p){
			dodaj(val[u], d[v], pod[u] - pod[v]);
			dodaj(MX - val[u], pod[v] - d[v], pod[u] - pod[v]);
		}
	
	dodaj(val[u], 1, pod[u]);
	dodaj(val[u], pod[u] - d[u], n - pod[u]);
	dodaj(val[u], color[c] - pod[u] + d[u], pod[u]);
	
	dodaj(MX - val[u], d[u], n - pod[u]);
	dodaj(MX - val[u], color[c ^ 1] - d[u], pod[u]);
//	printf("%d %d %d %d %d\n", u, d[u], pod[u], c, res);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &val[i]);
		val[i] = (val[i] + MX)%MX;
	}
	
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	dfs(1, 1, 0); //printf("%d %d\n", color[0], color[1]);
	find(1, 1, 0);
	printf("%d\n", (res + MX)%MX);
	return 0;
}