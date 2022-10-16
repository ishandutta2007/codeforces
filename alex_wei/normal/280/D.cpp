#include <bits/stdc++.h> ///////////////////////
using namespace std;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)

namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return x = sgn ? -x : x;
	}
	template <typename T>
	inline void rec_print(T x) {if(x >= 10) rec_print(x / 10); pc(x % 10 + '0');}
	template <typename T>
	inline void print(T x) {if(x < 0) pc('-'), x = -x; rec_print(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}
bool Mbe;

const int N = 1e5 + 5;
struct data {
	int sum, pre, suf, ans, prep, sufp, ansl, ansr;
} I, pos[N << 2], neg[N << 2];
data operator + (data x, data y) {
	data z = I; z.sum = x.sum + y.sum;
	if(x.pre > z.pre) z.pre = x.pre, z.prep = x.prep;
	if(x.sum + y.pre > z.pre) z.pre = x.sum + y.pre, z.prep = y.prep;
	if(y.suf > z.suf) z.suf = y.suf, z.sufp = y.sufp;
	if(y.sum + x.suf > z.suf) z.suf = y.sum + x.suf, z.sufp = x.sufp;
	if(x.ans > z.ans) z.ans = x.ans, z.ansl = x.ansl, z.ansr = x.ansr;
	if(y.ans > z.ans) z.ans = y.ans, z.ansl = y.ansl, z.ansr = y.ansr;
	if(x.suf + y.pre > z.ans) z.ans = x.suf + y.pre, z.ansl = x.sufp, z.ansr = y.prep;
	return z;
}

int n, m, a[N], rev[N << 2];
void init(int x, int p) {
	int pp = max(0, a[p]), po = a[p] < 0 ? -1 : p;
	pos[x] = {a[p], pp, pp, pp, po, po, po, po};
	int np = max(0, -a[p]), no = a[p] > 0 ? -1 : p;
	neg[x] = {-a[p], np, np, np, no, no, no, no};
}
void push(int x) {
	pos[x] = pos[x << 1] + pos[x << 1 | 1];
	neg[x] = neg[x << 1] + neg[x << 1 | 1];
}
void swp(int x) {rev[x] ^= 1, swap(pos[x], neg[x]);}
void down(int x) {if(rev[x]) swp(x << 1), swp(x << 1 | 1), rev[x] = 0;}
void build(int l, int r, int x) {
	if(l == r) return init(x, l);
	int m = l + r >> 1;
	build(l, m, x << 1), build(m + 1, r, x << 1 | 1), push(x);
}
void update(int l, int r, int p, int x) {
	if(l == r) return init(x, p);
	int m = l + r >> 1; down(x);
	if(p <= m) update(l, m, p, x << 1);
	else update(m + 1, r, p, x << 1 | 1); 
	push(x);
}
void modify(int l, int r, int ql, int qr, int x) {
	if(ql <= l && r <= qr) return swp(x);
	int m = l + r >> 1; down(x);
	if(ql <= m) modify(l, m, ql, qr, x << 1);
	if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1);
	push(x);
}
data query(int l, int r, int ql, int qr, int x) {
	if(ql <= l && r <= qr) return pos[x];
	int m = l + r >> 1; data ans = I; down(x);
	if(ql <= m) ans = query(l, m, ql, qr, x << 1);
	if(m < qr) ans = ans + query(m + 1, r, ql, qr, x << 1 | 1);
	return ans;
}

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n, I = {0, 0, 0, 0, -1, -1, -1, -1};
	for(int i = 1; i <= n; i++) a[i] = read();
	build(1, n, 1), m = read();
	for(int i = 1, l, r, k; i <= m; i++) {
		if(!read()) l = read(), a[l] = read(), update(1, n, l, 1);
		else {
			l = read(), r = read(), k = read();
			int ans = 0; vpii oper;
			while(k--) {
				data res = query(1, n, l, r, 1);
				if(res.ansl == -1) break;
				ans += res.ans, oper.pb(res.ansl, res.ansr);
				modify(1, n, res.ansl, res.ansr, 1);
			} print(ans), pc('\n');
			for(pii it : oper) modify(1, n, it.fi, it.se, 1);
		}
	}
	return flush(), 0;
} ///