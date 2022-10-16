#include <bits/stdc++.h> //////////////////////
using namespace std;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>
#define pll pair <ll, ll>
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
#define forcd(x) for(int it : e[id]) if(it != f && !vis[it])

bool Mbe;
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
	inline void recprint(T x) {if(x >= 10) recprint(x / 10); pc(x % 10 + '0');}
	template <typename T>
	inline void print(T x) {if(x < 0) pc('-'), x = -x; recprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 1e5 + 5;
ll ans, n, W, L;
vpii e[N];

int R, sz[N], mx[N], vis[N];
void findr(int id, int f, int tot) {
	sz[id] = 1, mx[id] = 0;
	for(pii it : e[id]) if(!vis[it.fi] && it.fi != f)
		findr(it.fi, id, tot), sz[id] += sz[it.fi], cmax(mx[id], sz[it.fi]);
	cmax(mx[id], tot - sz[id]);
	if(mx[id] < mx[R]) R = id;
}

int c[N];
void add(int x, int v) {while(x <= n) c[x] += v, x += x & -x;}
int query(int x) {int s = 0; while(x) s += c[x], x -= x & -x; return s;}

vector <pii> buc;
pii pt[N];
void findd(int id, int f, int w, int l) {
	buc.pb(w, l);
	for(pii it : e[id]) if(!vis[it.fi] && it.fi != f)
		findd(it.fi, id, w + it.se, l + 1);
}
void divide(int id) {
	int cnt = 0; vis[id] = 1;
	for(pii it : e[id]) if(!vis[it.fi]) {
		buc.clear(), findd(it.fi, id, it.se, 1), sor(buc);
		for(pii p : buc) {if(p.fi <= W && p.se <= L) ans += 2; add(p.se, 1);}
		for(int i = 0, c = buc.size() - 1; i < buc.size(); i++) {
			while(c >= 0 && buc[c].fi + buc[i].fi > W) add(buc[c].se, -1), c--;
			if(buc[i].fi << 1 <= W && buc[i].se << 1 <= L) ans++;
			if(buc[i].se < L) ans -= query(L - buc[i].se);
			pt[++cnt] = buc[i];
			if(i + 1 == buc.size()) while(c >= 0) add(buc[c].se, -1), c--;
		}
	}
	sort(pt + 1, pt + cnt + 1);
	for(int i = 1; i <= cnt; i++) add(pt[i].se, 1);
	for(int i = 1, p = cnt; i <= cnt; i++) {
		while(p && pt[i].fi + pt[p].fi > W) add(pt[p].se, -1), p--;
		if(pt[i].fi << 1 <= W && pt[i].se << 1 <= L) ans--;
		if(pt[i].se < L) ans += query(L - pt[i].se);
		if(i == cnt) while(p) add(pt[p].se, -1), p--;
	}
	for(pii it : e[id]) if(!vis[it.fi])
		R = 0, findr(it.fi, id, sz[it.fi]), divide(R);
}


bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> L >> W, mx[0] = N;
	for(int i = 1; i < n; i++) {
		int v, w; cin >> v >> w;
		e[i + 1].pb(v, w), e[v].pb(i + 1, w);
	} findr(1, 0, n), divide(R);
	cout << ans / 2 << endl;
	return cerr << "Time : " << clock() << endl, flush(), 0;
}