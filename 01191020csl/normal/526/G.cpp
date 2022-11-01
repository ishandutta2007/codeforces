#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int head[100001], ver[200001], edge[200001], nxt[200001], sz;
void addedge(int u, int v, int w) {
	ver[++sz] = v, edge[sz] = w, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, edge[sz] = w, nxt[sz] = head[v], head[v] = sz;
}
int dis[100001], vis[100001];
void dfs1(int x, int &p) {
	vis[x] = 1;
	if (!p || dis[x] > dis[p]) p = x;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) {
			dis[ver[i]] = dis[x] + edge[i];
			dfs1(ver[i], p);
		}
	vis[x] = 0;
}
struct leaf {
	int len, id;
};
bool operator<(const leaf &a, const leaf &b) {
	return a.len > b.len;
}
struct {
	int w[100001];
	int fa[100001], dep[100001], len[100001], son[100001];
	int f[100001][20], g[100001][20];
	void dfs1(int x) {
		for (int i = head[x]; i; i = nxt[i])
			if (fa[x] != ver[i]) {
				fa[ver[i]] = x;
				dep[ver[i]] = dep[x] + edge[i];
				w[ver[i]] = edge[i];
				dfs1(ver[i]);
				if (len[ver[i]] > len[x]) {
					len[x] = len[ver[i]];
					son[x] = ver[i];
				}
			}
		len[x] += w[x];
	}
	leaf l[100001];
	int cnt;
	int id[100001], place[100001];
	vector<int> vec[100001];
	void dfs2(int x, int t, int p) {
		if (t) ++cnt, l[cnt].len = len[x], p = cnt;
		if (son[x]) dfs2(son[x], 0, p);
		else l[p].id = x;
		for (int i = head[x]; i; i = nxt[i])
			if (fa[x] != ver[i] && son[x] != ver[i]) dfs2(ver[i], 1, 0);
	}
	void dfs3(int x) {
		if (son[x]) dfs3(son[x]), place[x] = place[son[x]];
		else place[x] = id[x];
		vec[x].push_back(place[x]);
		for (int i = head[x]; i; i = nxt[i])
			if (fa[x] != ver[i] && son[x] != ver[i])
				dfs3(ver[i]), vec[x].push_back(place[ver[i]]);
		sort(vec[x].begin(), vec[x].end());
	}
	void init_up(int n) {
		for (int i = 1; i <= n; i++) f[i][0] = fa[i], g[i][0] = place[i];
		for (int j = 1; j < 19; j++)
			for (int i = 1; i <= n; i++)
				f[i][j] = f[f[i][j-1]][j-1], g[i][j] = min(g[i][j-1], g[f[i][j-1]][j-1]);
	}
	int ans[100001];
	void init(int n, int rt) {
		dfs1(rt), dfs2(rt, 1, 0);
		sort(l + 1, l + cnt + 1);
		for (int i = 1; i <= cnt; i++) id[l[i].id] = i, ans[i] = ans[i-1] + l[i].len;
		dfs3(rt);
		init_up(n);
	}
	int getans(int m, int x) {
		if (m >= cnt) return ans[cnt];
		if (place[x] <= m) return ans[m];
		int len = dep[l[place[x]].id];
		for (int i = 19; i >= 0; i--)
			if (f[x][i] && g[x][i] > m) x = f[x][i];
		int p = upper_bound(vec[x].begin(), vec[x].end(), m) - vec[x].begin() - 1;
		return max(ans[m-1] + len - dep[x], ans[m] + len - dep[l[vec[x][p]].id]);
	}
}s1, s2;
int main() {
	int n = read(), q = read();
	for (int i = 1; i < n; i++) {
		int u, v, w;
		u = read(), v = read(), w = read();
		addedge(u, v, w);
	}
	int u = 0, v = 0;
	dfs1(1, u), dis[u] = 0, dfs1(u, v);
	s1.init(n, u), s2.init(n, v);
	int lastans = 0;
	for (int i = 1; i <= q; i++) {
		int x = read(), y = read();
		x = (x+lastans-1)%n+1, y = (y+lastans-1)%n+1;
		write(lastans = max(s1.getans(2*y-1, x), s2.getans(2*y-1, x))), putchar('\n');
	}
}