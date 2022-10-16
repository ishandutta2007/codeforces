#include <bits/stdc++.h>
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
bool Mbe;

const int N = 4e5 + 5;
const int mod = 1e9 + 7;
void add(int &x, int y) {x += y; if(x >= mod) x -= mod;}

int n, ans, t, f[N], buc[N];
struct Interval {
	int l, r, id;
	bool operator < (const Interval &v) const {
		return l < v.l;
	}
} s[N];

struct Fenwick {
	int c[N];
	void Inc(int x, int v) {while(x <= n << 1) add(c[x], v), x += x & -x;}
	int Que(int x) {int s = 0; while(x) add(s, c[x]), x -= x & -x; return s;}
} fen, ap;

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i].l >> s[i].r, s[i].id = i;
	sort(s + 1, s + n + 1), cin >> t;
	for(int i = 1, id; i <= t; i++) cin >> id, buc[id] = 1;
	for(int i = n; i; i--) {
		fen.Inc(s[i].r, f[i] = (1 + fen.Que(s[i].r)) % mod);
		if(buc[s[i].id]) ap.Inc(s[i].r, 1);
		if(ap.Que(n << 1) - ap.Que(s[i].r - 1)) add(ans, f[i]);
	} cout << ans << endl;
    return cerr << "Time : " << clock() << endl, flush(), 0;
}