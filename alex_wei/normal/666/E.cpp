#include <bits/stdc++.h>
using namespace std;

const int N = 1.1e6 + 5, S = 26;

int node, ls[N << 4], rs[N << 4], R[N];
struct dat {
	int ap, id;
	dat operator + (dat x) {
		if(ap != x.ap) return ap > x.ap ? *this : x;
		return id < x.id ? *this : x;
	}
} val[N << 4];
void modify(int l, int r, int p, int &x) {
	if(!x) x = ++node;
	if(l == r) return val[x] = {1, l}, void();
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, ls[x]);
	else modify(m + 1, r, p, rs[x]);
	val[x] = val[ls[x]] + val[rs[x]];
}
int merge(int l, int r, int x, int y) {
	if(!x || !y) return x | y;
	int z = ++node;
	if(l == r) {
		val[z] = val[x], val[z].ap += val[y].ap;
		return z;
	}
	int m = l + r >> 1;
	ls[z] = merge(l, m, ls[x], ls[y]);
	rs[z] = merge(m + 1, r, rs[x], rs[y]);
	return val[z] = val[ls[z]] + val[rs[z]], z;
}
dat query(int l, int r, int ql, int qr, int x) {
	if(!x) return {0, ql};
	if(ql <= l && r <= qr) return val[x];
	int m = l + r >> 1;
	dat ans = {0, N};
	if(ql <= m) ans = query(l, m, ql, qr, ls[x]);
	if(m < qr) ans = ans + query(m + 1, r, ql, qr, rs[x]);
	return ans;
}

string s;
int n, m, q, lg;
int las = 1, cnt = 1;
int son[N][S], len[N], fa[N];
int buc[N], id[N], anc[S][N], ed[N];
int ins(int p, int it) {
	int cur = ++cnt;
	len[cur] = len[p] + 1;
	while(!son[p][it]) son[p][it] = cur, p = fa[p];
	if(!p) return fa[cur] = 1, cur;
	int q = son[p][it];
	if(len[p] + 1 == len[q]) return fa[cur] = q, cur;
	int cl = ++cnt;
	memcpy(son[cl], son[q], S << 2);
	len[cl] = len[p] + 1, fa[cl] = fa[q], fa[q] = fa[cur] = cl;
	while(son[p][it] == q) son[p][it] = cl, p = fa[p];
	return cur;
}

int nd, tr[N][S], pos[N];
vector <int> e[N];
void insert(string s, int id) {
	int p = 0;
	for(char it : s) {
		if(!tr[p][it - 'a']) tr[p][it - 'a'] = ++nd;
		p = tr[p][it - 'a'];
		if(id) e[p].push_back(id);
	}
}
void build() {
	queue <int> q;
	q.push(0), pos[0] = 1;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = 0; i < S; i++) {
			int p = tr[t][i];
			if(!p) continue;
			pos[p] = ins(pos[t], i), q.push(p);
		}
	}
}
void init() {
	for(int i = 1; i <= nd; i++)
		for(int it : e[i])
			modify(1, m, it, R[pos[i]]);
	for(int i = 1; i <= cnt; i++) anc[0][i] = fa[i];
	for(int i = 1; i <= lg; i++)
		for(int j = 1; j <= cnt; j++)
			anc[i][j] = anc[i - 1][anc[i - 1][j]];
	for(int i = 0, p = 1; i < s.size(); i++)
		ed[i + 1] = p = son[p][s[i] - 'a'];
}
void Segmerge() {
	for(int i = 1; i <= cnt; i++) buc[len[i]]++;
	for(int i = 1; i <= cnt; i++) buc[i] += buc[i - 1];
	for(int i = cnt; i; i--) id[buc[len[i]]--] = i;
	for(int i = cnt; i; i--) R[fa[id[i]]] = merge(1, m, R[fa[id[i]]], R[id[i]]);
}
int main() {
	cin >> s >> m, insert(s, 0);
	n = s.size(), lg = log2(n);
	for(int i = 1; i <= m; i++) {
		string t;
		cin >> t, insert(t, i);
	}
	build(), init(), Segmerge();
	cin >> q;
	for(int i = 1; i <= q; i++) {
		int l, r, pl, pr;
		scanf("%d %d %d %d", &l, &r, &pl, &pr);
		int p = ed[pr];
		for(int j = lg; ~j; j--)
			if(len[anc[j][p]] >= pr - pl + 1)
				p = anc[j][p];
		dat ans = query(1, m, l, r, R[p]);
		printf("%d %d\n", ans.id, ans.ap);
	}
	return 0;
}