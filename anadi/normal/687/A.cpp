#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define PLL pair <LL, LL>
#define PLD pair <LD, LD>
#define pb push_back
#define LOGN 20

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7;
const int N = 1e5 + 9;

int n, m;
vector <int> V[N];
int war[N];
bool ans = true;

void dfs(int u){
	int t = war[u] ^ 3;
	for(int i = 0; i < V[u].size(); ++i){
		if(war[V[u][i]] == 0){
			war[V[u][i]] = t;
			dfs(V[u][i]);
		}

		else if(war[V[u][i]] != t)
			ans = false;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		V[a].pb(b);
		V[b].pb(a);
	}
	
	for(int i = 1; i <= n; ++i)
		if(war[i] == 0){
			war[i] = 1;
			dfs(i);
		}
	
	if(!ans){
		puts("-1");
		return 0;
	}
	
	int res = 0;
	for(int i = 1; i <= n; ++i)
		if(war[i] == 1)
			res ++;

	printf("%d\n", res);
	for(int i = 1; i <= n; ++i)
		if(war[i] == 1)
			printf("%d ", i);

	puts("");
	printf("%d\n", n - res);
	for(int i = 1; i <= n; ++i)
		if(war[i] != 1)
			printf("%d ", i);
	return 0;
}