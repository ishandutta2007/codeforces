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

const int N = 1e5 + 7;

int n, m;
vector <int> V[N];
int result = 0;

int dfs(int u, int prev){
	int mx = 0, mx2 = 0;
	for(int i = 0; i < V[u].size(); ++i)
		if(V[u][i] != prev){
			int a = dfs(V[u][i], u) + 1;
			if(a > mx){
				mx2 = mx;
				mx = a;
			}
			else if(a > mx2)
				mx2 = a;
		}
	
	result = max(result, mx2 + mx);
	return mx;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		V[a].pb(b);
		V[b].pb(a);
	}

	dfs(1, 1);
	printf("%d\n", result);
	return 0;
}