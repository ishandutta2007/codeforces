#include <bits/stdc++.h> //
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
	    ll x = 0, sgn = 0; char s = gc;
	    while(!isdigit(s)) sgn |= s == '-', s = gc;
	    while(isdigit(s)) x = x * 10 + s - '0', s = gc;
	    return sgn ? -x : x;
	}
	inline void rec_print(ll x) {if(x >= 10) rec_print(x / 10); pc(x % 10 + '0');}
	inline void print(ll x) {if(x < 0) pc('-'), x = -x; rec_print(x);}
} using namespace IO;

template <class T> void cmin(T &a, T b){a = a < b ? a : b;}
template <class T> void cmax(T &a, T b){a = a > b ? a : b;}

const int N = 1e6 + 5;

int n, q, stc[N], *top = stc, a[N], l[N], r[N];
ll ans[N];
vpii qu[N];
struct BIT {
	ll c[N], ic[N];
	void clear() {mem(c, 0, N), mem(ic, 0, N);}
	void add(int x, ll v) {
		ll vv = x * v;
		while(x <= n) c[x] += v, ic[x] += vv, x += x & -x;
	}
	ll query(int x) {
		ll s = 0, sv = 0, xx = x;
		while(x) s += c[x], sv += ic[x], x -= x & -x;
		return s * (xx + 1) - sv;
	}
	void add(int l, int r, int v) {add(l, v), add(r + 1, -v);}
	ll query(int l, int r) {return query(r) - query(l - 1);}
} tr;
int main(){
//	FileI("1.in");
	cin >> n >> q;
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= q; i++) l[i] = read();
	for(int i = 1; i <= q; i++) r[i] = read(), qu[r[i]].pb(l[i], i);
	for(int i = 1; i <= n; i++) {
		while(*top && a[*top] < a[i]) top--;
		if(*top) tr.add(i, i, tr.query(*top, *top));
		tr.add(*top + 1, i, 1), *++top = i;
		for(auto it : qu[i]) {
			int l = 1, r = top - stc, lp = it.fi;
			while(l < r) {
				int m = l + r >> 1;
				stc[m] < lp ? l = m + 1 : r = m;
			}
			int p = stc[l], d = tr.query(p, p) - 1;
			ans[it.se] = tr.query(p, i) - 1ll * (i - p + 1) * d;
		}
	}
	tr.clear(), top = stc;
	for(int i = 1; i <= n; i++) qu[i].clear();
	for(int i = 1; i <= q; i++) qu[l[i]].pb(r[i], i);
	for(int i = n; i; i--) {
		while(*top && a[*top] < a[i]) top--;
		if(*top) tr.add(i, i, tr.query(*top, *top));
		tr.add(i, *top ? *top - 1 : n, 1), *++top = i;
		for(auto it : qu[i]) {
			int l = 1, r = top - stc, rp = it.fi;
			while(l < r) {
				int m = l + r >> 1;
				stc[m] > rp ? l = m + 1 : r = m;
			}
			int p = stc[l], d = tr.query(p, p) - 1;
			ans[it.se] += tr.query(i, p - 1) - 1ll * (p - i) * d;
		}
	}
	for(int i = 1; i <= q; i++) print(ans[i]), pc(' ');
    return flush(), 0;
}