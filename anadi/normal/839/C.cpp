#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;
const int inf  = 1e9 + 7;

int n, m;
double res = 0.0;
vector <int> G[N];

void dfs(int u, int b, double p){
	if(u != 1 && G[u].size() > 1)
		p /= G[u].size() - 1;
	else
		p /= G[u].size();
	
	for(int v: G[u])
		if(v != b)
			res += p,
			dfs(v, u, p);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	dfs(1, 0, 1.0);
	printf("%.8lf\n", res);
	return 0;
}