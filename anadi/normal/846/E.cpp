#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int inf = 1e9 + 9;
const LL bigInf = 1e18 + 9LL;

int n, m;
LL a[N], b[N];
LL multi[N];
vector <int> G[N];

inline LL add(LL x, LL y){
	if(x + y > bigInf)
		return bigInf;
	return x + y;
}

LL RS(LL a, LL b){
	if(b == 0)	return 0LL;
	LL x = 2LL * RS(a, b / 2LL);
	if(b & 1)	x += a;
	return min(x, bigInf);
}

LL dfs(int u){
	LL need = a[u] - b[u];
	for(int v: G[u])
		need = add(need, dfs(v));

	if(need > 0)
		need = RS(need, multi[u]);
	return need;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &b[i]);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", &a[i]);
	
	multi[1] = 1LL;
	for(int i = 2; i <= n; ++i){
		int x;
		scanf("%d %lld", &x, &multi[i]);
		G[x].pb(i);
	}
	
	LL ret = dfs(1);
	printf(ret <= 0 ? "YES" : "NO");
	return 0;
}