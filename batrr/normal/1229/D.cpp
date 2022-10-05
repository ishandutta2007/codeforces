#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

vector< pii > g[150];
pair< int, pii > edges[N];

int n, k, a[N], pr[150], cnte;
vector< pii > E[150];
vector< int > P[150];
bool bad[N];
map< vector< int >, int> id;
ll ans;
int pp(int v){
	if(pr[v] == v)
		return v;
	return pr[v] = pp(pr[v]);
}
void dfs(int v, int pr, int l, int r){
	ans += l;
	for(auto to : g[v])
		if(to.f != pr)
			dfs(to.f, v, min(l, to.s), r); 
}
int main()
{
	scanf("%d%d", &n, &k);
	int m = 0;
	vector< int > p(k);
	for(int i = 0; i < k; i++)
		p[i] = i;
	
	do{
		P[m] = p;
		id[p] = m++;
	}while(next_permutation(p.begin(), p.end()));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			for(int q = 0; q < k; q++)
				for(int qq = 0; qq < k; qq++)
					if(P[i][q] == P[j][qq])
						p[q] = qq;				
			E[id[p]].pb({i, j});
		}
	}
	for(int i = 1; i <= n; i++){
		int x;
		for(int j = 0; j < k; j++){
			scanf("%d", &p[j]);
			p[j]--;
		}   
		x = id[p];
		
		for(int v = 0; v < m; v++)
			g[v].clear();

		for(auto it : E[x]){
			int v = it.f, u = it.s;
			edges[cnte++] = {i, {v, u}};	
		}
		sort(edges, edges + cnte);
	
		for(int v = 0; v < 120; v++)
			pr[v] = v;

		for(int j = cnte - 1; j >= 0; j--){
			int v = pp(edges[j].s.f);
			int u = pp(edges[j].s.s);
			int w = edges[j].f;
			if(v == u){
				bad[j] = 1;
				continue;
			}
			bad[j] = 0;	
			pr[v] = u;                                     
			g[edges[j].s.f].pb({edges[j].s.s, edges[j].f});
			g[edges[j].s.s].pb({edges[j].s.f, edges[j].f});
		}
		int nn = 0;
		for(int j = 0; j < cnte; j++)
			if(!bad[j])
				edges[nn++] = edges[j];
		cnte = nn;		
		dfs(0, 0, i, i);
	}
	printf("%lld", ans);
	return 0;
}