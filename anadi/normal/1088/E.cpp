#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 3e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int in[N];
vector <int> G[N];

LL ret = -MX;
LL dfs(int u, int p){
	LL cur = in[u];
	for(auto v: G[u]){
		if(v == p)
			continue;
		
		LL tmp = dfs(v, u);
		if(tmp > 0)
			cur += tmp;
	}
	
	ret = max(ret, cur);
	return cur;
}

int k = 0;
LL dfs2(int u, int p){
	LL cur = in[u];
	for(auto v: G[u])
		if(v != p){
			LL tmp = dfs2(v, u);
			if(tmp > 0)
				cur += tmp;
		}
	
	if(cur == ret)
		++k, cur = -MX;
	return cur;	
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	dfs2(1, 0);
	printf("%lld %d\n", ret * k, k);
	return 0;
}