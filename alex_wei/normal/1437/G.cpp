#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
char obuf[1 << 24], *O = obuf;
#define pc(x) (*O++ = (x))
inline int read() {
	int x = 0;
	char s = getchar();
	while(!isdigit(s)) s = getchar();
	while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
	return x;
}
inline void print(int x) {
	if(x < 0) return pc('-'), print(-x);
	if(x >= 10) print(x / 10);
	pc(x % 10 + '0');
}
const int N = 3e5 + 5, S = 26;
string t;
int node, son[N][S], fa[N];
int n, m, val[N << 2], ans[N];
vector <pair <int, int>> mo[N];
vector <int> e[N], qu[N], rep[N];
void ins(string s, int id) {
	int p = 0;
	for(char it : s) {
		if(!son[p][it - 'a']) son[p][it - 'a'] = ++node;
		p = son[p][it - 'a'];
	}
	rep[p].push_back(id);
}
void build() {
	queue <int> q;
	for(int i = 0; i < S; i++) if(son[0][i]) q.push(son[0][i]);
	while(!q.empty()) {
		int t = q.front();
		q.pop(), e[fa[t]].push_back(t);
		for(int i = 0; i < S; i++)
			if(son[t][i]) fa[son[t][i]] = son[fa[t]][i], q.push(son[t][i]);
			else son[t][i] = son[fa[t]][i];
	}
}
void modify(int l, int r, int ql, int qr, int x, int v, auto &op) {
	if(ql > qr) return;
	if(ql <= l && r <= qr) return op.push_back({x, val[x]}), val[x] = max(v, val[x]), void();
	int m = l + r >> 1;
	if(ql <= m) modify(l, m, ql, qr, x << 1, v, op);
	if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v, op);
}
int query(int p) {
	int l = 1, r = m, x = 1, ans = val[x];
	while(l < r) {
		int m = l + r >> 1;
		if(p <= m) r = m, x <<= 1;
		else l = m + 1, x = x << 1 | 1;
		ans = max(ans, val[x]);
	}
	return ans;
}
void dfs(int id) {
	vector <pair <int, int>> op;
	for(int it : rep[id]) {
		mo[it].push_back({m + 1, 0});
		modify(1, m, 1, mo[it].front().first - 1, 1, 0, op);
		for(int i = 0; i + 1 < mo[it].size(); i++) modify(1, m, mo[it][i].first, mo[it][i + 1].first - 1, 1, mo[it][i].second, op);
	}
	for(int p : qu[id]) ans[p] = max(ans[p], query(p));
	for(int it : e[id]) dfs(it);
	reverse(op.begin(), op.end());
	for(auto it : op) val[it.first] = it.second;
}
int main() {
	cin >> n >> m;
	memset(ans, 0x8f, sizeof(ans));
	memset(val, -1, sizeof(val));
	for(int i = 1; i <= n; i++) cin >> t, ins(t, i);
	build();
	for(int i = 1, op, id, x, p = 0; i <= m; i++, p = 0) {
		op = read();
		if(op == 1) id = read(), x = read(), mo[id].push_back({i, x});
		else {
			cin >> t, ans[i] = -1;
			for(char it : t) qu[p = son[p][it - 'a']].push_back(i);
		}
	}
	dfs(0);
	for(int i = 1; i <= m; i++) if(ans[i] >= -1) print(ans[i]), pc('\n');
	return fwrite(obuf, 1, O - obuf, stdout), 0;
}