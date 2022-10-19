#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 400015, M = N * 19, ALL = 400000;
namespace seg {
int rt[N << 1], ls[M], rs[M], sum[M], tot;
void pushup(int p) {sum[p] = sum[ls[p]] + sum[rs[p]];}
void add(int &p, int l, int r, int pos) {
	if (!p) p = ++tot;
	if (l == r) return sum[p] = 1, void();
	int mid = (l + r) >> 1;
	if (pos <= mid) add(ls[p], l, mid, pos);
	else add(rs[p], mid + 1, r, pos);
	pushup(p);
}
int merge(int u, int v, int l, int r) {
	if (!u || !v) return u | v;
	int p = ++tot;
	if (l == r) {
		sum[p] = sum[u] + sum[v];
		return p;
	}
	int mid = (l + r) >> 1;
	ls[p] = merge(ls[u], ls[v], l, mid);
	rs[p] = merge(rs[u], rs[v], mid + 1, r);
	pushup(p);
	return p;
}
int query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return sum[p];
	if (!p) return 0;
	int mid = (l + r) >> 1, res = 0;
	if (x <= mid) res += query(ls[p], l, mid, x, y);
	if (y > mid) res += query(rs[p], mid + 1, r, x, y);
	return res;
}
}
using namespace seg;
namespace SAM {
int link[N << 1], ch[N << 1][27], len[N << 1], sz, las, fa[N << 1][20];
void init() {link[0] = -1;}
int insert(int c) {
	int cur = ++sz, p = las;
	len[cur] = len[p] + 1;
	while (!ch[p][c] && ~p) ch[p][c] = cur, p = link[p];
	if (p == -1) link[cur] = 0;
	else {
		int q = ch[p][c];
		if (len[p] + 1 == len[q]) link[cur] = q;
		else {
			int clone = ++sz;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			link[q] = link[cur] = clone;
			rep(i, 0, 26) ch[clone][i] = ch[q][i];
			while (~p && ch[p][c] == q) ch[p][c] = clone, p = link[p];
		}
	}
	return las = cur;
}
int p[N << 1];
void build() {
	rep(i, 0, sz) p[i] = i;
	sort(p, p + sz + 1, [&](int u, int v) {
		return len[u] > len[v];
	});
	rep(i, 0, sz) {
		int u = p[i], pa = link[u];
		fa[u][0] = pa;
		if (link[u] == -1) continue;
		rt[pa] = merge(rt[pa], rt[u], 1, ALL);
	}
	rep(j, 1, 19) rep(u, 0, sz) {
		if (~fa[u][j - 1]) fa[u][j] = fa[fa[u][j - 1]][j - 1];
		else fa[u][j] = -1;
	}
}
int jump(int x, int L) {
	per(j, 0, 19) if (~fa[x][j] && len[fa[x][j]] >= L) x = fa[x][j];
	return x;
}
}
using namespace SAM;
int n, q, pos[N], Len[N], End;
char s[N];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &q);
	init();
	rep(i, 1, n) {
		scanf("%s", s + 1);
		Len[i] = strlen(s + 1);
		rep(j, 1, Len[i]) {
			pos[i] = insert(s[j] - 'a');
			add(rt[pos[i]], 1, ALL, ++End);
		}
		insert(26); ++End;
	}
	build();
	rep(i, 1, n) pos[i] = jump(pos[i], Len[i]);
	rep(i, 1, n) Len[i] += Len[i - 1] + 1;
	while (q--) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", query(rt[pos[k]], 1, ALL, Len[l - 1] + 1, Len[r]));
	}
	return 0;
}