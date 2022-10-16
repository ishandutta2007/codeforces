//#pragma GCC optimize(3)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define pll pair <ll, ll>
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
#define y1 y_chenxiaoyan_1

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 26], *O = Obuf;
// 	#define gc getchar()
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}
const int N = 2e5 + 5;
int n, q, p[N], rev[N], l[N], r[N], stc[N], top;
long long ans[N << 3];
struct line {
	long long k, b;
	line operator + (const line &r) {return {k + r.k, b + r.b};}
	line operator - (const line &r) {return {k - r.k, b - r.b};}
	void operator += (const line &r) {*this = *this + r;}
	line operator * (const int &v) {return {v * k, v * b};}
} c[N], c2[N];
void add(int x, line v) {line z = v * (x - 1); while(x <= n) c[x] += v, c2[x] += z, x += x & -x;}
void add(int l, int r, line v) {add(l, v), add(r + 1, (line) {0, 0} - v);}
line query(int x) {int p = x; line s = {0, 0}, s2 = {0, 0}; while(x) s += c[x], s2 += c2[x], x -= x & -x; return s * p - s2;}
line query(int l, int r) {return query(r) - query(l - 1);}
int cnt, hd[N], nxt[N << 5];
pair <int, int> val[N << 5];
void add(int u, auto it) {nxt[++cnt] = hd[u], hd[u] = cnt, val[cnt] = it;}
int cnt2, hd2[N], nxt2[N << 4];
pair <int, pair <int, int>> val2[N << 4];
void add2(int u, auto it) {nxt2[++cnt2] = hd2[u], hd2[u] = cnt2, val2[cnt2] = it;}
int main() {
	cin >> n >> q;
	p[0] = p[n + 1] = n + 1;
	for(int i = 1; i <= n; i++) p[i] = read(), rev[p[i]] = i;
	for(int i = 1; i <= n; i++) {
		while(p[i] > p[stc[top]]) top--;
		l[i] = stc[top] + 1, stc[++top] = i;
	}
	stc[top = 0] = n + 1;
	for(int i = n; i; i--) {
		while(p[i] > p[stc[top]]) top--;
		r[i] = stc[top] - 1, stc[++top] = i;
	}
	for(int i = 1; i <= n; i++) {
		static pair <int, int> pt[N];
		int cnt = 0, pos = rev[i];
		for(int j = 1; j * j < i; j++) {
			if(i % j) continue;
			int lb = min(pos, min(rev[j], rev[i / j])), rb = max(pos, max(rev[j], rev[i / j]));
			if(l[pos] <= lb && rb <= r[pos]) pt[++cnt] = {lb, rb};
		}
		sort(pt + 1, pt + cnt + 1);
		for(int j = cnt, up = r[pos] + 1; j; j--) {
			if(pt[j].second < up) {
				add(pt[j].first + 1, make_pair(-pt[j].second, up - 1));
				up = pt[j].second;
			}
			if(j == 1) add(l[pos], make_pair(up, r[pos]));
		}
	}
//	if(q == 1e6) exit(0);
	for(int i = 1; i <= q; i++) {
		int l = read(), r = read();
		add2(l - 1, make_pair(-i, make_pair(l, r)));
		add2(r, make_pair(i, make_pair(l, r)));
	}
	for(int i = 1; i <= n; i++) {
		for(int _ = hd[i]; _; _ = nxt[_]) {
			auto it = val[_];
			int l = abs(it.first), r = it.second, sgn = it.first / l;
//			cerr << "add " << i << " " << l << " " << r << " " << sgn << endl;
			add(l, r, (line) {sgn, sgn == -1 ? (i - 1) : -(i - 1)});
		}
		for(int _ = hd2[i]; _; _ = nxt2[_]) {
			auto it = val2[_];
			int id = abs(it.first), l = it.second.first, r = it.second.second;
//			cerr << l << " " << r << endl;
			line res = query(l, r);
//			cerr << i << " " << res.k << " " << res.b << endl;
			ans[id] += (res.k * i + res.b) * (it.first / id);
		}
	}
	for(int i = 1; i <= q; i++) print(ans[i]), pc('\n');
	return flush(), 0;
}

/*
9 1
6 7 2 8 1 4 9 3 5
2 5
*/