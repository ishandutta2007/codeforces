#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, S = 26;
int node, R[N], ls[N << 5], rs[N << 5];
bool val[N << 5];
void modify(int l, int r, int p, int &x) {
	if(!x) x = ++node;
	val[x] |= 1;
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
	return val[z] = val[x] | val[y], z;
}
bool query(int l, int r, int ql, int qr, int x) {
//	cerr << l << " " << r << " " << ql << " " << qr << " " << x << " " << val[x] << endl;
	if(ql <= l && r <= qr) return val[x];
	int m = l + r >> 1;
	if(ql <= m && query(l, m, ql, qr, ls[x])) return 1;
	if(m < qr && query(m + 1, r, ql, qr, rs[x])) return 1;
	return 0;
}

char s[N], t[N], ans[N];
int n, q, m, l, r, cnt = 1, las = 1;
int son[N][S], fa[N], len[N];
int buc[N], id[N];
bool exist(int mt, int p) {return query(1, n, l + mt - 1, r, R[p]);}
bool find(int mt, int p) {
	for(int i = max(0, t[mt] - 'a'); i < S; i++) {
		int nxt = son[p][i];
		if(nxt && exist(mt, nxt)) {
			if(i + 'a' > t[mt]) return t[mt] = i + 'a', t[mt + 1] = 0, 1;
			if(find(mt + 1, nxt)) return t[mt] = i + 'a', 1;
		}
	}
	return 0;
}
void ins(int it) {
	int cur = ++cnt, p = las;
	len[cur] = len[p] + 1, las = cur;
	modify(1, n, len[cur], R[cur]);
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
	cin >> s + 1 >> q, n = strlen(s + 1);
	for(int i = 1; i <= n; i++) ins(s[i] - 'a');
	for(int i = 1; i <= cnt; i++) buc[len[i]]++;
	for(int i = 1; i <= n; i++) buc[i] += buc[i - 1];
	for(int i = cnt; i; i--) id[buc[len[i]]--] = i;
	for(int i = cnt; i; i--) R[fa[id[i]]] = merge(R[fa[id[i]]], R[id[i]]);
	for(int i = 1; i <= q; i++) {
		cin >> l >> r >> t + 1;
		if(!find(1, 1)) puts("-1");
		else cout << t + 1 << "\n";
	}
	return 0;
}

/*
forget to consider the case len(ans) > len(t)
 t 
*/