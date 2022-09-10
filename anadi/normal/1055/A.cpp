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

int n, s;
bool vis[N];
int a[N], b[N];
vector <int> G[N];

void dfs(int u){
	vis[u] = true;
	for(int v: G[u])
		if(!vis[v])
			dfs(v);
}

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j){
			if(a[i] == 1 && a[j] == 1)
				G[i].push_back(j);
			if(b[i] == 1 && b[j] == 1)
				G[j].push_back(i);
		}
	
	dfs(1);
	puts(vis[s] ? "YES" : "NO");
	return 0;
}