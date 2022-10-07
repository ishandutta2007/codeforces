#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1000005
const int B1 = 233, P1 = 382538579, B2 = 331, P2 = 952959323;
int pw1[N], pw2[N];
struct node{
	int H1, H2;
	node(int _H1 = 0, int _H2 = 0){ H1 = _H1, H2 = _H2; }
	bool operator == (const node &rhs) const {
		return H1 == rhs.H1 && H2 == rhs.H2;
	}
	node operator + (const char ch) const {
		return node((1ll * H1 * B1 + ch) % P1, (1ll * H2 * B2 + ch) % P2);
	}
	node operator - (const node &rhs) const {
		return node((H1 - rhs.H1 + P1) % P1, (H2 - rhs.H2 + P2) % P2);
	}
	node operator * (const int x) const {
		return node(1ll * H1 * pw1[x] % P1, 1ll * H2 * pw2[x] % P2);
	}
}ha[N], hb[N];
int k, n, m;
char a[N], b[N];
node hash(node *a, int l, int r){
	return a[r] - a[l - 1] * (r - l + 1);
}
void build(char *a, int l, int r, node *h){
	for (register int i = l; i <= r; ++i) h[i] = h[i - 1] + a[i];
}
int get_pos(){
	for (register int i = std :: min(n, m); ~i; --i)
		if (hash(ha, n - i + 1, n) == hash(hb, 1, i)) return i;
}
int main(){
	pw1[0] = pw2[0] = 1;
	for (register int i = 1; i <= 1000000; ++i)
		pw1[i] = 1ll * pw1[i - 1] * B1 % P1, pw2[i] = 1ll * pw2[i - 1] * B2 % P2;
	k = read(), n = 0;
	ha[0] = hb[0] = node();
	for (register int i = 1; i <= k; ++i){
		scanf("%s", b + 1), m = strlen(b + 1), build(b, 1, m, hb);
		int _n = n;
		for (register int j = get_pos() + 1; j <= m; ++j) a[++n] = b[j], putchar(b[j]);
		build(a, _n + 1, n, ha);
	}
}