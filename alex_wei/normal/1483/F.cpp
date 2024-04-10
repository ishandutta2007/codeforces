#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int S = 26;
string s[N];
int n, ans, buc[N];
int dn, dfn[N], sz[N];
vector <int> e[N], cov;
int node, fa[N], ed[N], ep[N], son[N][S];
void ins(int id) {
	int p = 0;
	for(char it : s[id]) {
		if(!son[p][it - 'a']) son[p][it - 'a'] = ++node;
		p = son[p][it - 'a'];
	}
	ed[p] = id, ep[id] = p;
}
void build() {
	queue <int> q;
	for(int i = 0; i < S; i++) if(son[0][i]) q.push(son[0][i]);
	while(!q.empty()) {
		int t = q.front();
		q.pop(), e[fa[t]].push_back(t), ed[t] = ed[t] ? ed[t] : ed[fa[t]];
		for(int i = 0; i < S; i++)
			if(son[t][i]) fa[son[t][i]] = son[fa[t]][i], q.push(son[t][i]);
			else son[t][i] = son[fa[t]][i];
	}
}
void dfs(int id) {
	dfn[id] = ++dn, sz[id] = 1;
	for(int it : e[id]) dfs(it), sz[id] += sz[it];
}
struct BIT {
	int c[N];
	void add(int x, int v) {while(x <= dn) c[x] += v, x += x & -x;}
	int query(int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;}
	int query(int l, int r) {return query(r) - query(l - 1);}
} tr;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i], ins(i);
	build(), dfs(0);
	for(int i = 1; i <= n; i++) {
		static int pa[N], p;
		p = 0, cov.clear();
		for(int j = 0; j < s[i].size(); j++) pa[j] = p = son[p][s[i][j] - 'a'], tr.add(dfn[pa[j]], 1);
		for(int j = s[i].size() - 1, lbound = N; ~j; j--) {
			int id = ed[j == s[i].size() - 1 ? fa[pa[j]] : pa[j]];
			if(id && j - (int)s[id].size() < lbound) lbound = j - s[id].size(), buc[id]++, cov.push_back(id);
		}
		for(int it : cov) if(buc[it]) ans += tr.query(dfn[ep[it]], dfn[ep[it]] + sz[ep[it]] - 1) == buc[it], buc[it] = 0;
		for(int j = 0; j < s[i].size(); j++) tr.add(dfn[pa[j]], -1); // ADD THIS LINE
	}
	cout << ans << endl;
	return 0;
}