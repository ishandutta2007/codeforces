#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double D;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define PLL pair <LL, LL>
#define PDD pair <D, D>

const int N = 1e5 + 7;
const LL INF = 10000000000000000LL;

int n, m, k;
vector <PII> V[N];
priority_queue <PLL> Q;
bool vis[N];
bool starts[N];
LL d[N];

void Dijkstra(){
	while(!Q.empty()){
		int K = Q.top().second;
		Q.pop();
		
		if(vis[K])
			continue;
		vis[K] = true;
		
		for(int i = 0; i < V[K].size(); ++i)
			if(d[K] + V[K][i].nd < d[V[K][i].st]){
				d[V[K][i].st] = d[K] + V[K][i].nd;
				Q.push(mp(-d[V[K][i].st], V[K][i].st));
			}
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	
	if(k == 0){
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= m; ++i){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		V[a].pb(mp(b, c));
		V[b].pb(mp(a, c));
	}
	
	for(int i = 1; i <= n; ++i)
		d[i] = INF;
	for(int i = 1; i <= k; ++i){
		int a;
		scanf("%d", &a);
		d[a] = 0;
		starts[a] = true;
		Q.push(mp(0, a));
	}
	
	Dijkstra();
	LL res = INF;
	
	for(int i = 1; i <= n; ++i)
		if(!starts[i])
			res = min(res, d[i]);
	
	printf("%I64d\n", res == INF ? -1 : res);
	return 0;
}