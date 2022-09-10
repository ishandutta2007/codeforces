#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const int inf  = 1e9 + 9;

int n, m;
int res[N];
int val[N];
int curCheck;
vector <int> G[N];

int nwd(int u, int v){
	if(v == 0)
		return u;
	return nwd(v, u%v);
}

void dfs(int u, int p, int cur){
	res[u] = cur;
	for(int v: G[u])
		if(v != p)
			dfs(v, u, nwd(cur, val[v]));
}

void dfs2(int u, int p, bool flag){
	if(val[u]%curCheck != 0){
		if(flag)	return;
		flag = true;
	}

	res[u] = max(res[u], curCheck);	
	for(int v: G[u])
		if(v != p)
			dfs2(v, u, flag);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &val[i]);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	dfs(1, 0, 0);
	for(int i = 1; i <= val[1]; ++i){
		if(val[1]%i != 0)
			continue;
		curCheck = i;
		dfs2(1, 0, 0);
		curCheck = val[1] / i;
		dfs2(1, 0, 0);
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	return 0;
}