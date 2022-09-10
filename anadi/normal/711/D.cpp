#include <bits/stdc++.h>

using namespace std;

typedef double d;
typedef long long int LL;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define PDD pair <d, d>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const LL MX = 1e9 + 7LL;

int n;
int V[N];
LL pot[N];
int vis[N];
int h[N];
int licz = 0;

void dfs(int u){
	vis[u] = 1;
	
	if(vis[V[u]] == 0){
		h[V[u]] = h[u] + 1;
		dfs(V[u]);
	}
	else if(vis[V[u]] == 1)
		licz = abs(h[u] - h[V[u]]) + 1;
	vis[u] = 2;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &V[i]);
	
	pot[0] = 1LL;
	for(int i = 1; i <= n; ++i)
		pot[i] = (pot[i - 1] * 2LL)%MX;
	
	LL res = 1LL;
	int ile = 0;
	for(int i = 1; i <= n; ++i){
		if(vis[i] == 0){
			licz = 0;
			dfs(i);
			ile += licz;
			if(licz != 0)
				res *= pot[licz] - 2;
			res %= MX;
		}
	}
	
	res *= pot[n - ile];
	res %= MX;

	printf("%I64d\n", res);
	return 0;
}