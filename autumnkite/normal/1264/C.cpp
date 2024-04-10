#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <set>
char buf[1 << 23], *ps = buf, *pt = buf, pbuf[1 << 23], *pp = pbuf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
#define putchar(x) (pp == pbuf + (1 << 23) ? fwrite(pbuf, 1, 1 << 23, stdout), pp = pbuf : 0, *pp++ = x)
struct __IO_flusher{ ~__IO_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } IO_flusher;
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
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
const int N = 200005, P = 998244353;
int n, q, p[N], ip[N], ans;
void inc(int &a, int b){ (a += b) >= P ? a -= P : 0; }
void dec(int &a, int b){ (a -= b) < 0 ? a += P : 0; }
int plus(int a, int b){ return (a += b) >= P ? a - P : a; }
int minus(int a, int b){ return (a -= b) < 0 ? a + P : a; }
int qpow(int a, int b = P - 2){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
std :: set<int> S;
struct Segment_Tree{
	int val[N << 2], lz[N << 2];
	void build(int u, int l, int r){
		lz[u] = 1;
		if (l == r) return val[u] = p[l], void(0);
		int md = (l + r) >> 1;
		build(u << 1, l, md), build(u << 1 | 1, md + 1, r);
		val[u] = plus(val[u << 1], val[u << 1 | 1]);
	}
	void mul(int u, int v){ val[u] = 1ll * val[u] * v % P, lz[u] = 1ll * lz[u] * v % P; }
	void down(int u){
		if (lz[u] != 1) mul(u << 1, lz[u]), mul(u << 1 | 1, lz[u]), lz[u] = 1;
	}
	void modify(int u, int l, int r, int L, int R, int v){
		if (L <= l && r <= R) return mul(u, v), void(0);
		int md = (l + r) >> 1;
		down(u);
		if (L <= md) modify(u << 1, l, md, L, R, v);
		if (R > md) modify(u << 1 | 1, md + 1, r, L, R, v);
		val[u] = plus(val[u << 1], val[u << 1 | 1]);
	}
	int query(int u, int l, int r, int L, int R){
		if (L <= l && r <= R) return val[u];
		int md = (l + r) >> 1;
		down(u);
		if (R <= md) return query(u << 1, l, md, L, R);
		if (L > md) return query(u << 1 | 1, md + 1, r, L, R);
		return plus(query(u << 1, l, md, L, R), query(u << 1 | 1, md + 1, r, L, R));
	}
}T;
int main(){
	n = read(), q = read();
	for (register int i = 1; i <= n; ++i)
		p[i] = 1ll * read() * qpow(100) % P, ip[i] = qpow(p[i]);
	p[0] = ip[0] = 1;
	for (register int i = 1; i <= n; ++i)
		p[i] = 1ll * p[i - 1] * p[i] % P, ip[i] = 1ll * ip[i - 1] * ip[i] % P;
	S.insert(1), S.insert(n + 1);
	T.build(1, 1, n);
	ans = 1ll * (T.query(1, 1, n, 1, n) + 1) * ip[n] % P;
	while (q--){
		int u = read();
		if (S.count(u)){
			S.erase(u);
			int pr = *(--S.lower_bound(u)), nx = *S.upper_bound(u);
			dec(ans, 1ll * (T.query(1, 1, n, pr, u - 1) + 1) * ip[u - 1] % P * p[pr - 1] % P);
			dec(ans, 1ll * (T.query(1, 1, n, u, nx - 1) + 1) * ip[nx - 1] % P * p[u - 1] % P);
			T.modify(1, 1, n, u, nx - 1, 1ll * p[u - 1] * ip[pr - 1] % P);
			inc(ans, 1ll * (T.query(1, 1, n, pr, nx - 1) + 1) * ip[nx - 1] % P * p[pr - 1] % P);
		}
		else{
			S.insert(u);
			int pr = *(--S.lower_bound(u)), nx = *S.upper_bound(u);
			dec(ans, 1ll * (T.query(1, 1, n, pr, nx - 1) + 1) * ip[nx - 1] % P * p[pr - 1] % P);
			T.modify(1, 1, n, u, nx - 1, 1ll * ip[u - 1] * p[pr - 1] % P);
			inc(ans, 1ll * (T.query(1, 1, n, pr, u - 1) + 1) * ip[u - 1] % P * p[pr - 1] % P);
			inc(ans, 1ll * (T.query(1, 1, n, u, nx - 1) + 1) * ip[nx - 1] % P * p[u - 1] % P);
		}
		print(minus(ans, S.size() - 1));
	}
}