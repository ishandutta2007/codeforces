#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int res;
int n, m;
int d[N];
bool vis[N];
bool ans[N];
vector <PII> G[N];

int dfs(int u){
	int cur = 0;
	vis[u] = true;
	for(PII v: G[u])
		if(!vis[v.st]){
			int x = dfs(v.st);
			if(x & 1){
				ans[v.nd] = true;
				++res;
				++cur;
			}
		}
	
	if(d[u] == 1)
		++cur;
	return cur;
}

int main(){
	int s = 0, d1 = 0;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &d[i]);
		if(d[i] == 1)
			++s;
		if(d[i] == -1)
			d1 = i;
	}
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	
	if((s & 1) && d1 == 0){
		puts("-1");
		return 0;
	}
	
	if(d1 == 0)
		d1 = 1;
	dfs(d1);
	
	printf("%d\n", res);
	for(int i = 1; i <= m; ++i)
		if(ans[i])
			printf("%d\n", i);
	return 0;
}