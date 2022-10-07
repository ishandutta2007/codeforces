#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <vector>
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
const int N = 100005;
int n, q, m, a[N], cnt, ans[N];
std::vector<int> p[N];
struct node{
	int x, y, v;
	bool operator < (const node &rhs){ return x < rhs.x; }
}b[N * 8];
struct query{
	int l, r, id;
	bool operator < (const query &rhs){ return l < rhs.l; }
}Q[N];
void ins(int x1, int x2, int y1, int y2, int v){
	if (x1 > x2 || y1 > y2) return;
	// printf("%d %d %d %d %d\n", x1, x2, y1, y2, v);
	++x2, ++y2;
	b[++cnt] = (node){x1, y1, v}, b[++cnt] = (node){x2, y2, v};
	b[++cnt] = (node){x1, y2, -v}, b[++cnt] = (node){x2, y1, -v};
}
int c[N];
void add(int x, int v){
	for (; x <= n; x += x & -x) c[x] += v;
}
int query(int x){
	int s = 0;
	for (; x; x ^= x & -x) s += c[x];
	return s;
}
int main(){
	n = read(), m = 0;
	for (register int i = 1; i <= n; ++i)
		a[i] = read(), m = std::max(m, a[i]), p[a[i]].push_back(i);
	q = read();
	for (register int i = 1; i <= q; ++i) Q[i].l = read(), Q[i].r = read(), Q[i].id = i;
	std::sort(Q + 1, Q + 1 + q);
	for (register int i = 1; i <= m; ++i){
		int k = p[i].size();
		if (!k) continue;
		if (k == 1){
			ins(1, p[i][0], p[i][0], n, 1);
			continue;
		}
		for (register int j = 1, lst = 0; j < k; ++j)
			if (j == k - 1 || p[i][j + 1] - p[i][j] != p[i][j] - p[i][j - 1]){
				ins(lst ? p[i][lst - 1] + 1 : 1, p[i][j], p[i][lst], j < k - 1 ? p[i][j + 1] - 1 : n, 1);
				lst = j;
			}
		for (register int j = 1; j < k - 1; ++j)
			ins(p[i][j - 1] + 1, p[i][j] - 1, p[i][j - 1] + 1, p[i][j] - 1, -1);
	}
	std::sort(b + 1, b + 1 + cnt);
	for (register int i = 1, j = 1, k = 1; k <= n; ++k){
		while (i <= cnt && b[i].x == k) add(b[i].y, b[i].v), ++i;
		while (j <= q && Q[j].l == k) ans[Q[j].id] = query(Q[j].r) == 0, ++j;
	}
	cnt = 0;
	for (register int i = 1; i <= m; ++i){
		int k = p[i].size();
		for (register int j = 0; j <= k; ++j){
			int l = j ? p[i][j - 1] + 1 : 1, r = j < k ? p[i][j] - 1 : n;
			ins(l, r, l, r, 1);
		}
	}
	std::sort(b + 1, b + 1 + cnt);
	for (register int i = 1; i <= n; ++i) c[i] = 0;
	for (register int i = 1, j = 1, k = 1; k <= n; ++k){
		while (i <= cnt && b[i].x == k) add(b[i].y, b[i].v), ++i;
		while (j <= q && Q[j].l == k) ans[Q[j].id] += m - query(Q[j].r), ++j;
	}
	for (register int i = 1; i <= q; ++i) print(ans[i]);
}