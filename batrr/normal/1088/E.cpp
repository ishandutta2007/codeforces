#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)3e5 + 123, inf = 1e9;
const ll INF = 1e18;

vector< int > g[N];
int n, a[N];
ll fs, fk, x, b[N];

void DFS(int v, int p){
	b[v] = a[v];
	for(auto to : g[v]){
		if(to == p)
			continue;
		DFS(to, v);
		if(b[to] > 0)
			b[v] += b[to];	
	}	
	x = max(x, b[v]);
}

void dfs(int v, int p){
	b[v] = a[v];
	for(auto to : g[v]){
		if(to == p)
			continue;
		dfs(to, v);
		if(b[to] > 0)
			b[v] += b[to];	
	}	
	if(b[v] >= x){
		fs += b[v];
		fk++;
		b[v] = 0;
	}
}

bool check(bool flag){
	fs = fk = 0;
	dfs(1, 1);
	if(flag){
		printf("%lld %lld", fs, fk);
		exit(0);
	}
	return fk != 0;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]); 
	}
	for(int i = 1; i < n; i++){
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].pb(u);
		g[u].pb(v);
	}
	x = -1e18;
	DFS(1, 1);
	check(1);
	return 0;
}