#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PII pair <int, int>

namespace Dinic{
	typedef LL T;
	const int N = 100005;
	const T INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
	
	struct edge{
		int a, b;
		T cap, flow;
	};
	
	int n, s, t, d[N], ptr[N], q[N];
	vector <edge> e;
	vector <int> g[N];
	
	int add_edge(int a, int b, T cap){
		edge e1 = {a, b, cap, 0};
		edge e2 = {b, a, cap, cap};
		
		g[a].push_back(e.size());
		e.push_back(e1);
		g[b].push_back(e.size());
		e.push_back(e2);
		return e.size() - 2;
	}
	
	bool bfs(){
		int qh = 0, qt = 0;
		q[qt++] = s;
		memset(d + 1, -1, n * sizeof d[0]);
		d[s] = 0;
		
		while(qh < qt && d[t] == -1){
			int v = q[qh++];
			for(int i = 0; i < (int)g[v].size(); ++i){
				int id = g[v][i], to = e[id].b;
				if(d[to] == -1 && e[id].flow < e[id].cap){
					q[qt++] = to;
					d[to] = d[v] + 1;
				}
			}
		}
		
		return d[t] != -1;
	}
	
	T dfs(int v, T flow){
		if(!flow)	return 0;
		if(v == t)	return flow;
		T res = 0;
		for(; ptr[v] < (int)g[v].size(); ++ptr[v]){
			int id = g[v][ptr[v]], to = e[id].b;
			if(d[to] != d[v] + 1)	continue;
			T pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
			e[id].flow += pushed;
			e[id ^ 1].flow -= pushed;
			res += pushed;
			flow -= pushed;
			if(flow == 0)	break;
		}
		
		return res;
	}
	
	T dinic(int _n, int _s, int _t){
		n = _n; s = _s; t = _t;
		T flow = 0;
		for(;;){
			if(!bfs())	break;
			memset(ptr, 0, n * sizeof ptr[0]);
			flow += dfs(s, INF);
		}
		return flow;
	}
}

const int N = 107;
const int NN = 100007;

const int MAXI = 1e6;
const int INF = 1e9 + 7;

int n, m;
int dist[N][N];

int s, b, k;
int pl2[NN], def[NN], gold[NN];
int pl1[NN], att[NN], fuel[NN], price[NN], profit[NN];

vector <int> A[N], B[N];

bool cmp(int a, int b){
	if(att[a] == att[b])	return a < b;
	return att[a] < att[b];
}

bool cmp2(int a, int b){
	if(def[a] == def[b])	return a < b;
	return def[a] < def[b];
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dist[i][j] = i == j ? 0 : INF;
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		if(u == v)	continue;
		dist[u][v] = dist[v][u] = 1;
	}
	
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	scanf("%d %d %d", &s, &b, &k);
	for(int i = 1; i <= s; ++i){
		scanf("%d %d %d %d", &pl1[i], &att[i], &fuel[i], &price[i]);
		A[pl1[i]].push_back(i);
	}

	for(int i = 1; i <= b; ++i){
		scanf("%d %d %d", &pl2[i], &def[i], &gold[i]);
		B[pl2[i]].push_back(i);
	}
	
	for(int i = 1; i <= n; ++i){
		sort(A[i].begin(), A[i].end(), cmp);
		sort(B[i].begin(), B[i].end(), cmp2);
	}
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < (int)B[i].size(); ++j)
			gold[B[i][j]] = max(gold[B[i][j]], gold[B[i][j - 1]]);
	
	for(int i = 1; i <= n; ++i){
		if(A[i].size() == 0)	continue;
		for(auto t: A[i])
			profit[t] = -INF;

		for(int j = 1; j <= n; ++j){
			if(B[j].size() == 0)	continue;
			int wsk = -1;

			for(int t: A[i]){
				while(wsk + 1 < (int)B[j].size() && def[B[j][wsk + 1]] <= att[t])
					++wsk;
				
				if(wsk > -1 && fuel[t] >= dist[i][j])
					profit[t] = max(profit[t], gold[B[j][wsk]] - price[t]);
			}
		}
	}
	
	for(int i = 1; i <= s; ++i){
		LL weight = 1LL * MAXI * profit[i];
		if(profit[i] == -INF)	weight = -Dinic::INF;
		if(weight == 0)	weight = 1;
		
		if(weight > 0)
			Dinic::add_edge(1, i + 1, weight);
		else
			Dinic::add_edge(i + 1, s + 2, -weight);
	}
	
	for(int i = 1; i <= k; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		Dinic::add_edge(u + 1, v + 1, Dinic::INF);
	}

	LL ans = 0LL;
	for(int i = 1; i <= s; ++i)
		if(profit[i] > 0)
			ans += profit[i];

	ans -= Dinic::dinic(s + 2, 1, s + 2) / MAXI;
	printf("%lld\n", ans);
	return 0;
}