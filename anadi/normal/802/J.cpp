#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n, res = 0;
vector <pair <int, int> > G[N];

void dfs(int u, int p, int sum){
	res = max(res, sum);
	for(auto v: G[u])
		if(v.first != p)
			dfs(v.first, u, sum + v.second);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	
	dfs(0, 0, 0);
	printf("%d\n", res);
	return 0;
}