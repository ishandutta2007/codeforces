#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
void print(int x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
const int N = 200005, INF = 0x3f3f3f3f;
int n, q, a[N];
struct matrix{
	int a[5][5];
	matrix(){ memset(a, 0x3f, sizeof a); }
	matrix operator * (const matrix &rhs) const {
		matrix res;
		for (register int i = 0; i < 5; ++i)
			for (register int k = 0; k < 5; ++k)
				for (register int j = 0; j < 5; ++j)
					res.a[i][j] = std::min(res.a[i][j], a[i][k] + rhs.a[k][j]);
		return res;
	}
};
matrix get(int v){
	matrix res;
	for (register int i = 0; i < 5; ++i) res.a[i][i] = 0;
	if (v == 2) return res.a[0][0] = 1, res.a[0][1] = 0, res;
	if (v == 0) return res.a[1][1] = 1, res.a[1][2] = 0, res;
	if (v == 1) return res.a[2][2] = 1, res.a[2][3] = 0, res;
	if (v == 7) return res.a[3][3] = 1, res.a[3][4] = 0, res;
	if (v == 6) return res.a[3][3] = 1, res.a[4][4] = 1, res;
	return res;
}
struct Segment_Tree{
	matrix val[N << 2];
	void build(int u, int l, int r){
		if (l == r) return val[u] = get(a[l]), void(0);
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		val[u] = val[u << 1] * val[u << 1 | 1];
	}
	matrix query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return val[u];
		int md = (l + r) >> 1;
		if (R <= md) return query(u << 1, l, md, L, R);
		if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		return query(u << 1, l, md, L, R) * query(u << 1 | 1, md + 1, r, L, R);
	}
}T;
int main(){
	n = read(), q = read();
	for (register int i = 1; i <= n; ++i){
		while (!isdigit(a[i] = getchar())) ;
		a[i] ^= '0';
	}
	T.build(1, 1, n);
	while (q--){
		int l = read(), r = read();
		matrix tmp = T.query(1, 1, n, l, r);
		print(tmp.a[0][4] == INF ? -1 : tmp.a[0][4]);
	}
}