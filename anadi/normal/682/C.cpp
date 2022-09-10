#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PLL pair <LL, LL>
#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLD pair <LD, LD>
#define pb push_back

const LL MX = 1e9 + 7LL;
const LL INF = 1e9 + 9LL;
const int N = 1e5 + 9;

int n;
vector <PII> V[N];
int result = 0;
int nr[N];
bool visited[N];

void dfs(int u, LL max_v, bool sad){
	visited[u] = true;
	if(max_v < 0)
		max_v = 0;
	if(max_v > nr[u])
		sad = true;
	if(sad)
		++result;
	
	for(int i = 0; i < V[u].size(); ++i)
		if(!visited[V[u][i].st])
			dfs(V[u][i].st, max_v + V[u][i].nd, sad);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &nr[i]);
	for(int i = 2; i <= n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		V[a].pb(mp(i, b));
		V[i].pb(mp(a, b));
	}
	
	dfs(1, 0LL, false);
	printf("%d\n", result);
	return 0;
}