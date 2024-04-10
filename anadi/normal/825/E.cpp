#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PII pair <int, int>

const int N = 1e5 + 7;

int n, m;
int deg[N];
int ans[N];
vector <int> G[N];
priority_queue <int> Q;

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[v].pb(u);
		deg[u]++;
	}
	
	for(int i = 1; i <= n; ++i)
		if(deg[i] == 0)
			Q.push(i);
	
	int cnt = n;
	while(!Q.empty()){
		int k = Q.top();
		Q.pop();
		
		ans[k] = cnt--;
		for(int v: G[k]){
			deg[v]--;
			if(deg[v] == 0)
				Q.push(v);
		}
	}
	
	for(int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	return 0;
}