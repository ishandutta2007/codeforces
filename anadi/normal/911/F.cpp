#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n;
int best;
int curB, cur;
vector <int> G[N];

int d[N][2];
bool marked[N];

void dfs(int u, int p, int curD){
	if(curD > cur){
		curB = u;
		cur = curD;
	}
	
	for(int v: G[u])
		if(v != p)
			dfs(v, u, curD + 1);
}

void odl(int u, int p, int c, int t){
	d[u][t] = c;
	for(int v: G[u])
		if(v != p)
			odl(v, u, c + 1, t);
}

void write(int u, int p){
	for(int v: G[u])
		if(v != p)
			write(v, u);
	
	if(!marked[u]){
		if(d[u][0] < d[u][1])
			printf("%d ", curB);
		else
			printf("%d ", best);
		printf("%d %d\n", u, u);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	
	dfs(1, 1, 0);
	best = curB;
	
	curB = cur = 0;
	dfs(best, best, 0);
	
	odl(best, best, 0, 0);
	odl(curB, curB, 0, 1);
	
	LL res = 0LL;
	for(int i = 1; i <= n; ++i){
		if(d[i][0] + d[i][1] == d[best][1])
			marked[i] = true;
		else
			res += max(d[i][0], d[i][1]);
	}
	
	res += 1LL * d[best][1] * (d[best][1] + 1) / 2;
	printf("%lld\n", res);

	write(best, best);
	int cur = best, p = best;
	while(cur != curB){
		printf("%d %d %d\n", curB, cur, cur);
		for(int v: G[cur])
			if(v != p && marked[v]){
				p = cur;
				cur = v;
				break;
			}
	}

	return 0;
}