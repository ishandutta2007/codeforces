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
int w[N];
vector <PII> G[N];

LL res = 0LL;
LL dfs(int u, int p){
	LL mx = 0LL, mx2 = 0LL;

	for(auto v: G[u]){
		if(v.st == p)
			continue;
		
		LL t = dfs(v.st, u) + v.nd;
		if(t > mx){
			mx2 = mx;
			mx = t;
		}
		else if(t > mx2)
			mx2 = t;
	}
	
	res = max(res, mx + mx2 + w[u]);
	return mx + w[u];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &w[i]);

	for(int i = 1; i < n; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		
		c *= -1;
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	dfs(1, 0);
	printf("%lld\n", res);
	return 0;
}