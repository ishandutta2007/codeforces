#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
LL val[N];
bool vis[N];
vector <int> G[N];

LL dfs(int u){
	vis[u] = true;
	LL ret = val[u];

	for(int v: G[u])
		if(!vis[v])
			ret += dfs(v);
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i)
		for(int j = i + i; j <= n; j += i){
			val[i] += j / i;
			val[j] += j / i;

			G[i].push_back(j);
			G[j].push_back(i);
		}
	
	LL res = 0LL;
	for(int i = 2; i <= n; ++i)
		if(!vis[i])
			res = max(res, dfs(i));
	
	printf("%lld\n", 2LL * res);
	return 0;
}