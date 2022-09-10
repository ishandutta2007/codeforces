#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int LOGN = 17;
const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
vector <int> G[N];

int lvl[N];
int color[N];
int jump[LOGN][N];
int pre[N], post[N];

void dfs(int u, int p){
	static int Time = 0;
	pre[u] = ++Time;
	jump[0][u] = p;
	
	for(auto v: G[u])
		if(v != p){
			color[v] = color[u] ^ 1;
			lvl[v] = lvl[u] + 1;
			dfs(v, u);
		}
	
	post[u] = Time;
}

bool dad(int u, int v){
	return pre[u] <= pre[v] && post[v] <= post[u];
}

int lca(int u, int v){
	for(int i = LOGN - 1; i >= 0; --i)
		if(!dad(jump[i][u], v))
			u = jump[i][u];
	
	if(!dad(u, v))
		u = jump[0][u];
	return u;
}

int getDist(int u, int v){
	return lvl[u] + lvl[v] - 2 * lvl[lca(u, v)];
}

bool check(int u, int v, int k){
	if((k & 1) != (color[u] ^ color[v]))
		return false;
	return getDist(u, v) <= k;
}

bool check2(int u, int x, int y, int v, int k){
	int d = getDist(u, x) + 1 + getDist(y, v);
	return ((d & 1) == (k & 1)) && d <= k;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 1);
	for(int i = 1; i < LOGN; ++i)
		for(int j = 1; j <= n; ++j)
			jump[i][j] = jump[i - 1][jump[i - 1][j]];
	
	int q;
	scanf("%d", &q);
	
	while(q--){
		int x, y, a, b, k;
		scanf("%d %d %d %d %d", &x, &y, &a, &b, &k);
		
		bool ans = check(a, b, k) || check2(a, x, y, b, k) || check2(a, y, x, b, k);
		if(ans)	puts("YES");
		else	puts("NO");
	}

	return 0;
}