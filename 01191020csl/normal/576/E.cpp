#include<bits/stdc++.h>
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
int fa[51][500001], size[51][500001], cl[51][500001];
pair<int, int> getfa(int k, int x) {
	if (!fa[k][x]) return make_pair(x, 0);
	pair<int, int> ans = getfa(k, fa[k][x]);
	ans.second ^= cl[k][x];
	return ans;
}
int u[500001], v[500001], col[500001];
struct modify {
	int *p, last, dep;
};
vector<modify> m0;
void link(int c, int u, int v, int dep) {
	pair<int, int> l1 = getfa(c, u), l2 = getfa(c, v);
	u = l1.first, v = l2.first;
	if (u == v) return;
	if (size[u] > size[v]) swap(u, v);
	m0.push_back(modify{&fa[c][u], fa[c][u], dep});
	m0.push_back(modify{&size[c][v], size[c][v], dep});
	fa[c][u] = v, size[c][v] += size[c][u], cl[c][u] = l1.second^l2.second^1;
}
void popup(int p) {
	while (m0.size() && (m0.end()-1)->dep >= p) *((m0.end()-1)->p) = (m0.end()-1)->last, m0.pop_back();
}
struct paint {
	int l, r;
	int m, c;
};
int e[500001], c[500001], ed[500001];
int dis[500001];
vector<int> tmp[500001];
vector<int> edge[500001];
vector<paint> solve(int l, int r, int dep, vector<paint> vd) {
	if (l == r) {
		vector<paint> ans;
		pair<int, int> l1 = getfa(c[l], u[e[l]]), l2 = getfa(c[l], v[e[l]]);
		if (l1 == l2) {
			puts("NO");
			if (col[e[l]] && l<ed[l]) ans.push_back(paint{l+1,ed[l],e[l],col[e[l]]});
			return ans;
		}
		col[e[l]] = c[l];
		if (l<ed[l]) ans.push_back(paint{l+1, ed[l], e[l], c[l]});
		puts("YES");
		return ans;
	}
	int mid = (l + r) / 2;
	vector<paint> v0;
	for (paint i : vd)
		if (i.l <= mid) {
			if (i.r < mid || i.l > l) v0.push_back(i);
			else link(i.c, u[i.m], v[i.m], dep);
		}
	vector<paint> v1 = solve(l, mid, dep + 1, v0);
	popup(dep), v0.clear();
	for (paint i : vd)
		if (i.r > mid) {
			if (i.l > mid + 1 || i.r < r) v0.push_back(i);
			else link(i.c, u[i.m], v[i.m], dep);
		}
	for (paint i : v1)
		if (i.r < r) v0.push_back(i);
		else link(i.c, u[i.m], v[i.m], dep);
	vector<paint> v2 = solve(mid + 1, r, dep + 1, v0);
	popup(dep), v0.clear();
	for (paint i : v1) 
		if (i.r > r) v0.push_back(i);
	for (paint i : v2)
		if (i.r > r) v0.push_back(i);
	return v0;
}
int main() {
	int n, m, k, q;
	n = read(), m = read(), k = read(), q = read();
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= m; j++) size[i][j] = 1;
	for (int i = 1; i <= m; i++) u[i] = read(), v[i] = read();
	for (int i = 1; i <= q; i++) {
		e[i] = read(), c[i] = read();
		if (tmp[e[i]].size()) ed[*(tmp[e[i]].end()-1)] = i;
		tmp[e[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++)
		if (tmp[i].size()) ed[*(tmp[i].end()-1)] = q;
	solve(1, q, 1, vector<paint>());
}