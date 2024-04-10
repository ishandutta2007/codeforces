#include <bits/stdc++.h>
using namespace std;
const int N = 200 + 5;
const int M = 1e3 + 5;
struct Graph {
	int cnt = 1, hd[N], nxt[M << 1], to[M << 1], lim[M << 1];
	void add(int u, int v, int w) {
		nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v, lim[cnt] = w;
		nxt[++cnt] = hd[v], hd[v] = cnt, to[cnt] = u, lim[cnt] = w;
	}
	int T, cur[N], dis[N];
	int dfs(int id, int res) {
		if(id == T) return res;
		int flow = 0;
		for(int i = cur[id]; i && res; i = nxt[i]) {
			int it = to[i], c = min(res, lim[i]);
			cur[id] = i;
			if(c && dis[id] + 1 == dis[it]) {
				int k = dfs(it, c);
				res -= k, flow += k, lim[i] -= k, lim[i ^ 1] += k;
			}
		}
		if(!flow) dis[id] = -1;
		return flow;
	}
	int maxflow(int s, int t) {
		T = t;
		int flow = 0;
		while(1) {
			queue <int> q;
			memset(dis, -1, sizeof(dis));
			memcpy(cur, hd, sizeof(cur));
			dis[s] = 0, q.push(s);
			while(!q.empty()) {
				int t = q.front();
				q.pop();
				for(int i = hd[t]; i; i = nxt[i])
					if(dis[to[i]] == -1 && lim[i])
						dis[to[i]] = dis[t] + 1, q.push(to[i]);
			}
			if(dis[t] == -1) return flow;
			flow += dfs(s, 1e5);
		}
	}
} I, G;
int n, m, tot;
vector <pair <int, int>> e[N];
void build(vector <int> node) {
	if(node.size() == 1) return;
	int u = node[0], v = node[1], w;
	G = I, tot += w = G.maxflow(u, v);
	e[u].push_back(make_pair(v, w));
	e[v].push_back(make_pair(u, w));
	vector <int> x, y;
	for(int it : node)
		if(G.dis[it] == -1) y.push_back(it);
		else x.push_back(it);
	build(x), build(y);
}

bool tag[N];
int minv, u, v;
void findmin(int id, int fa) {
	for(auto it : e[id]) {
		if(!tag[it.first]) continue;
		if(it.second < minv) minv = it.second, u = id, v = it.first;
		if(it.first != fa) findmin(it.first, id);
	}
}
void dfs(int id, int fa, vector <int> &node) {
	node.push_back(id);
	for(auto it : e[id]) if(it.first != fa && tag[it.first]) dfs(it.first, id, node);
}
void solve(vector <int> node) {
	if(node.size() == 1) return cout << node[0] << " ", void();
	memset(tag, 0, sizeof(tag));
	for(int it : node) tag[it] = 1;
	minv = 1e9, findmin(node[0], 0);
	vector <int> x, y;
	dfs(u, v, x), dfs(v, u, y), solve(x), solve(y);
}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n >> m;
	for(int i = 1, u, v, w; i <= m; i++) cin >> u >> v >> w, I.add(u, v, w);
	vector <int> U;
	for(int i = 1; i <= n; i++) U.push_back(i);
	build(U), cout << tot << endl, solve(U);
	return 0;
}

/*
2022/5/1
start thinking at 13:19

?
.

start coding at 13:20
finish debugging at 13:50
*/