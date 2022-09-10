#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 17LL;

int n;
int color[N];
vector <int> G[N];

LL res, cnt;
int pod[N];

int dfs(int u, int p){
	pod[u] = 1;
	cnt += color[u];

	for(int v: G[u])
		if(v != p){
			color[v] = color[u] ^ 1;
			pod[u] += dfs(v, u);
		}
	
	res += 1LL * pod[u] * (n - pod[u]);
	return pod[u];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	dfs(1, 0);
	res += 1LL * (pod[1] - cnt) * cnt;
	printf("%lld\n", res / 2);
	return 0;
}