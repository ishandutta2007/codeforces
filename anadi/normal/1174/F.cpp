#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
int sz[N];
vector <int> G[N];

int p[N];
int depth[N];

void answer(int u){
	printf("! %d\n", u);
	exit(0);
}

int ask(char t, int u){
	static int Queries = 0;
	++Queries;
	
	if(Queries > 36)
		answer(u);
	
	printf("%c %d\n", t, u);
	fflush(stdout);
	
	int ret;
	scanf("%d", &ret);
	
	if(ret == -1)	exit(0);
	return ret;
}

int dfs(int u){
	sz[u] = 1;	
	for(int v: G[u]){
		if(v == p[u])
			continue;
		
		p[v] = u;
		depth[v] = depth[u] + 1;
		sz[u] += dfs(v);
	}
	
	return sz[u];
}

int goUp(int u, int x){
	while(x--)
		u = p[u];
	return u;
}

int getHeavy(int u){
	while(true){
		int nxt = -1;
		for(int v: G[u])
			if(sz[v] < sz[u] && (nxt == -1 || sz[v] > sz[nxt]))
				nxt = v;
		
		if(nxt == -1)
			break;
		u = nxt;
	}
	
	return u;
}

void go(int u, int d){
	if(d == 0)
		answer(u);
	
	int v = getHeavy(u);
	int dist = ask('d', v);
	int diff = dist + depth[v] - depth[u] - d;
	
	assert(diff%2 == 0);
	v = goUp(v, diff / 2);
	
	int nd = d + depth[u] - depth[v];
	if(nd == 0)
		answer(v);
	
	go(ask('s', v), nd - 1);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	p[1] = 1;
	dfs(1);
	
	go(1, ask('d', 1));
	return 0;
}