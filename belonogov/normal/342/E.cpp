#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const int LOG = 17;
const int inf = 1e9;


int jump[LOG][maxn];
int depth[maxn];
bool red[maxn];
int tin[maxn];
int tout[maxn];
int tmr = 0;
int dist[maxn];
int nearest[maxn];
queue < int > q;
vector < int > e[maxn];
vector < int > New;
int n;

void dfs(int v, int id, int p, int h){
	if (id == 0)
		jump[id][v] = p;
	else
		jump[id][v] = jump[id - 1][jump[id - 1][v]];
	depth[v] = h;
	for (int i = 0; i < (int)e[v].size(); i++)
		if (e[v][i] != p)
			dfs(e[v][i], id, v, h + 1);	
}

void dfsT(int v, int p){
	tin[v] = tmr++;
	for (int i = 0; i < (int)e[v].size(); i++)
		if (e[v][i] != p)
			dfsT(e[v][i], v);
	tout[v] = tmr++;
}

inline bool pred(int v, int u){
	return tin[v] <= tin[u] && tout[u] <= tout[v];	
}

inline int lca(int v, int u){
	if (pred(v, u)) return v;
	if (pred(u, v)) return u;
	for (int i = LOG - 1; i >= 0; i--)
		if (!pred(jump[i][v], u))
			v = jump[i][v];
	return jump[0][v];	
}

inline int len(int v, int u){
	int z = lca(v, u);
	return (depth[v] - depth[z]) + (depth[u] - depth[z]);
}

void re_build(){
	int v;
	for (int i = 0; i < (int)New.size(); i++)
		red[New[i]] = 1;
	New.clear();
	memset(dist, 63, sizeof(dist));
	for (int i = 0; i < n; i++)
		if (red[i]){
			dist[i] = 0;
			q.push(i);			
		}
		
	while (!q.empty()){
		v = q.front();
		q.pop();
		for (int i = 0; i < (int)e[v].size(); i++)
			if (dist[e[v][i]] > dist[v] + 1){
				dist[e[v][i]] = dist[v] + 1;
				q.push(e[v][i]);				
			}
	}
	
}

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
	int m, m_sqrt, v, u, ans, t;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++){
		scanf("%d%d", &v, &u); v--; u--;
		e[v].pb(u);
		e[u].pb(v);		
	}
	for (int i = 0; i < LOG; i++)
		dfs(0, i, 0, 0);


	dfsT(0, -1);

//	m_sqrt = sqrt(m * log(n));
	m_sqrt = sqrt(m);

	if (m_sqrt == 0) m_sqrt++;
	red[0] = 1;
	re_build();

	
	for (int i = 0; i < m; i++){
		scanf("%d%d", &t, &v); v--;		
		if (i % m_sqrt == 0)
			re_build();
		
		if (t == 1){
			New.pb(v);
// 			if ((int)New.size() == m_sqrt)
// 				re_build();			
		}
		if (t == 2){
			ans = dist[v];

			for (int j = 0; j < (int)New.size(); j++)
				ans = min(ans, len(v, New[j]));
			printf("%d\n", ans);
		}
			
	}
 
    return 0;
}