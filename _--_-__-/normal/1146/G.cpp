#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 300007;


struct MF
{
	const static int MAXN = 3000;
	struct edge
	{
		int to, flow, cap, rev;
		edge(int t, int f, int c, int r)
		{
			to = t; flow = f; cap = c; rev = r;
		}
	};
	vector<edge> E;
	vector<int> G[MAXN + 5];
	int dist[MAXN + 5];
	void add_edge(int u, int v, int fl)
	{
		int cur = E.size();
		G[u].push_back(cur);
		E.push_back(edge(v, 0, fl, cur + 1));
		G[v].push_back(cur + 1);
		E.push_back(edge(u, fl, fl, cur));
	}
	bool bfs(int s, int t)
	{
		memset(dist, -1, sizeof(dist));
		queue<int> Q;
		Q.push(s);
		dist[s] = 0;
		while(!Q.empty()) {
			int out = Q.front(); Q.pop();
			rep(i, G[out].size()) {
				edge cur = E[G[out][i]];
				if(cur.cap == cur.flow) continue;
				if(dist[cur.to] == -1) {
					dist[cur.to] = dist[out] + 1;
					Q.push(cur.to);
				}
			}
		}
		return dist[t] != -1;
	}
	int dfs(int v, int t, int maxf = INF)
	{
		if(maxf == 0) return 0;
		if(v == t) return maxf;
		int cf = 0;
		rep(i, G[v].size()) {
			edge& cur = E[G[v][i]];
			if(dist[cur.to] > dist[v]) {
				int cr = dfs(cur.to, t, min(maxf, cur.cap - cur.flow));
				cur.flow += cr;
				E[cur.rev].flow -= cr;
				cf += cr;
				maxf -= cr;
			}
		}
		return cf;
	}
	int maxflow(int s, int t)
	{
		int ans = 0;
		while(bfs(s, t)) ans += dfs(s, t);
		return ans;
	}
}fl;

int n, h, m;
int ver[55][55];

int main()
{
	scanf("%d%d%d", &n, &h, &m);
	
	int s = 0, t = 1, cv = 2;
	rep1(i, n) rep(j, h)
	ver[i][j] = cv ++;
	rep1(i, n) ver[i][h] = t;
	
	rep1(i, n) fl.add_edge(s, ver[i][0], INF);
	rep1(i, n) rep(j, h) fl.add_edge(ver[i][j], ver[i][j + 1], INF);
	
	rep1(i, n) rep(j, h) fl.add_edge(s, ver[i][j], 2 * j + 1);
	
	rep(i, m) {
		int l, r, x, c;
		scanf("%d%d%d%d", &l, &r, &x, &c);
		for(int i = l; i <= r; i ++) fl.add_edge(ver[i][x], cv, INF);
		fl.add_edge(cv, t, c);
		cv ++;
	}
	
	int ret = fl.maxflow(s, t);
	ret -= n * INF;
	ret = n * h * h - ret;
	printf("%d\n", ret);
	return 0;
}