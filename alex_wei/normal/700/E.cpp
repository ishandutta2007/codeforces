#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5, S = 26;
void cmax(int &x, int y) {x = x > y ? x : y;}
int node, R[N], ls[N << 5], rs[N << 5];
void modify(int l, int r, int p, int &x) {
	if(!x) x = ++node;
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) modify(l, m, p, ls[x]);
	else modify(m + 1, r, p, rs[x]);
}
int merge(int x, int y) {
	if(!x || !y) return x | y;
	int z = ++node;
	ls[z] = merge(ls[x], ls[y]);
	rs[z] = merge(rs[x], rs[y]);
	return z;
}
bool query(int l, int r, int ql, int qr, int x) {
	if(!x) return 0;
	if(ql <= l && r <= qr) return 1;
	int m = l + r >> 1;
	if(ql <= m && query(l, m, ql, qr, ls[x])) return 1;
	if(m < qr && query(m + 1, r, ql, qr, rs[x])) return 1;
	return 0;
}

char s[N];
int n, cnt = 1, las = 1, ans = 1;
int son[N][S], len[N], fa[N];
int buc[N], mx[N], id[N], f[N], g[N];
void ins(int it) {
	int cur = ++cnt, p = las;
	modify(1, n, mx[cur] = len[cur] = len[p] + 1, R[cur]), las = cur;
	while(!son[p][it]) son[p][it] = cur, p = fa[p];
	if(!p) return fa[cur] = 1, void();
	int q = son[p][it];
	if(len[p] + 1 == len[q]) return fa[cur] = q, void();
	int cl = ++cnt;
	memcpy(son[cl], son[q], S << 2);
	len[cl] = len[p] + 1, fa[cl] = fa[q], fa[q] = fa[cur] = cl;
	while(son[p][it] == q) son[p][it] = cl, p = fa[p];
}

int main() {
	cin >> n >> s + 1;
	for(int i = 1; i <= n; i++) ins(s[i] - 'a');
	for(int i = 1; i <= cnt; i++) buc[len[i]]++;
	for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
	for(int i = cnt; i; i--) id[buc[len[i]]--] = i;
	for(int i = cnt; i > 1; i--) R[fa[id[i]]] = merge(R[fa[id[i]]], R[id[i]]), cmax(mx[fa[id[i]]], mx[id[i]]);
	for(int i = 2; i <= cnt; i++) {
		int p = id[i], q = g[fa[p]];
		if(fa[p] == 1) {f[p] = 1, g[p] = p; continue;}
		if(!query(1, n, mx[p] - len[p] + len[q], mx[p] - 1, R[q])) f[p] = f[fa[p]], g[p] = g[fa[p]];
		else g[p] = p, cmax(ans, f[p] = f[fa[p]] + 1);
	}
	cout << ans << endl;
	return 0;
}