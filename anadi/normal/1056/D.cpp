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
int val[N];
vector <int> G[N];

int dfs(int u){
	val[u] = G[u].size() == 0;
	for(int v: G[u])
		val[u] += dfs(v);
	return val[u];
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		int a;
		scanf("%d", &a);
		G[a].push_back(i);
	}
	
	dfs(1);
	sort(val + 1, val + n + 1);

	for(int i = 1; i <= n; ++i)
		printf("%d ", val[i]);
	return 0;
}