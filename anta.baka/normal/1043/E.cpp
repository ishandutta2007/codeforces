/*

















*/

#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

/** Interface */

inline int readChar();
template <class T = int> inline T readInt();
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x );
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;

inline void readWord( char *s ) {
	int c = readChar();
	while (c > 32)
		*s++ = c, c = getChar();
	*s = 0;
}

inline void writeDouble( double x, int output_len ) {
	if (x < 0)
		writeChar('-'), x = -x;
	int t = (int)x;
	writeInt(t), x -= t;
	writeChar('.');
	for (int i = output_len - 1; i > 0; i--) {
		x *= 10;
		t = min(9, (int)x);
		writeChar('0' + t), x -= t;
	}
	x *= 10;
	t = min(9, (int)(x + 0.5));
	writeChar('0' + t);
}

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#define shandom_ruffle random_shuffle
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define x first
#define y second
//#define x real
//#define y imag
//#define int ll
//#define NAME ""

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

//using pnt = complex<ld>;
//
//istream &operator >> (istream &in, pnt &p) {
//    ld a, b;
//    in >> a >> b;
//    p = {a, b};
//    return in;
//}
//
//ld crs(pnt a, pnt b) {
//    return a.x()*b.y() - a.y()*b.x();
//}

const int M = 998244353;
const int mod = 1e9+7;
const int inf = 1e9+100;
const ll inf64 = 1e18L;
const ld pi = acos(-1.0L);
const ld eps = 1e-6L;
const int di[] = {1, 1,-1,-1, 2, 2,-2,-2};
const int dj[] = {2,-2, 2,-2, 1,-1, 1,-1};
const int dii[] = {0, 1,-1, 0};
const int djj[] = {1, 0, 0,-1};
const int dx[] = {1, 1,-1,-1};
const int dy[] = {1,-1, 1,-1};
const int SQ = 1000;
const int L = 19;
const int nax = 3e5;

struct fen {
    int n; vll t;
    fen(int n) : n(n), t(n, 0) {}
    void upd(int v, ll x) {
        for(int i = v; i < n; i |= i + 1) t[i] += x;
    }
    ll get(int v) {
        ll ret = 0;
        for(int i = v; i >= 0; i = (i & (i + 1)) - 1) ret += t[i];
        return ret;
    }
};

int n, m;
int x[nax], y[nax];
ll ans[nax];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(10);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    map<int, int> re;
    ll sumx = 0, sumy = 0;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        re[x[i] - y[i]];
        sumx += x[i];
        sumy += y[i];
    }
    int dif = 0;
    for(auto it = re.begin(); it != re.end(); it++) it->y = dif++;
    fen t(dif), tx(dif), ty(dif);
    vi pos(n);
    for(int i = 0; i < n; i++) {
        pos[i] = re[x[i] - y[i]];
        t.upd(pos[i], 1);
        tx.upd(pos[i], x[i]);
        ty.upd(pos[i], y[i]);
    }
    for(int i = 0; i < n; i++) {
        t.upd(pos[i], -1);
        tx.upd(pos[i], -x[i]);
        ty.upd(pos[i], -y[i]);
        ll cnt = t.get(pos[i]);
        ll sx = tx.get(pos[i]);
        ll sy = ty.get(pos[i]);
        ans[i] = (cnt * y[i] + sx) + ((n - 1 - cnt) * x[i] + (sumy - y[i] - sy));
        t.upd(pos[i], 1);
        tx.upd(pos[i], x[i]);
        ty.upd(pos[i], y[i]);
    }
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        int cost = min(x[u] + y[v], y[u] + x[v]);
        ans[u] -= cost;
        ans[v] -= cost;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
}