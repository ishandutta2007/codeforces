#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

const LL MX = 1e9 + 7LL;
const LD eps = 1e-9;
const int mxn = 2e5 + 7;

int n, k;
int ile[mxn];
LL suma[mxn];
vector <int> V[mxn];
bool uwr[mxn];
LL result = 0LL;

void dfs(int u, int prev){
	if(uwr[u])
		++ile[u];
		
	for(int i = 0; i < V[u].size(); ++i)
		if(V[u][i] != prev){
			dfs(V[u][i], u);
			suma[u] += suma[V[u][i]] + ile[V[u][i]];
			ile[u] += ile[V[u][i]];
		}
}

void check(int u, int prev, int less){
	int skad = -1;
	int less2 = 0;
	for(int i = 0; i < V[u].size(); ++i)
		if(V[u][i] != prev)
			if(ile[V[u][i]] * 2 - less > ile[u]){
				skad = V[u][i];
				less2 = ile[V[u][i]] * 2 - less - ile[u];
				result -= less2;
				less2 = ile[V[u][i]] - less - less2;
			}
	
	if(skad != -1)
		check(skad, u, less + less2);
}

int main(){
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= 2 * k; ++i){
		int a;
		scanf("%d", &a);
		uwr[a] = true;
	}

	for(int i = 0; i < n - 1; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		V[a].pb(b);
		V[b].pb(a);
	}	
	
	dfs(1, 1);	
	result = suma[1];
	check(1, 1, 0);
	
	printf("%I64d\n", result);
	return 0;
}