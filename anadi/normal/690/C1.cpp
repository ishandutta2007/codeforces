#include <bits/stdc++.h>

using namespace std;

typedef long double LD;
typedef long long int LL;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int N = 1e3 + 7;

int n, m;
int ile = 0;
vector <int> V[N];
bool visited[N];

void dfs(int u){
	visited[u] = true;
	for(int i = 0; i < V[u].size(); ++i)
		if(!visited[V[u][i]])
			dfs(V[u][i]);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		V[a].pb(b);
		V[b].pb(a);
	}
	
	if(m != n - 1){
		puts("no");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i)
		if(!visited[i]){
			dfs(i);
			++ile;
		}
		
	if(ile != 1)
		puts("no");
	else
		puts("yes");
	return 0;
}