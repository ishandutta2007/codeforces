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








//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")

//#define __GLIBCXX_DEBUG

#define shandom_ruffle random_shuffle
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define x() real()
#define y() imag()
//#define int ll
#define NAME "binary"

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

using pnt = complex<ld>;

istream &operator >> (istream &in, pnt &p) {
    ld a, b;
    in >> a >> b;
    p = {a, b};
    return in;
}

ld crs(pnt a, pnt b) {
    return a.x()*b.y() - a.y()*b.x();
}

ld dot(pnt a, pnt b) {
    return a.x()*b.x() + a.y()*b.y();
}

//const int M = 998244353;
const int mod = 1e9+7;
const int inf = 1e9+100;
const ll inf64 = 1e18L;
const ld pi = acos(-1.0L);
const ld eps = 1e-9L;
const int di[] = {0, 1,-1, 0};
const int dj[] = {1, 0, 0,-1};
const int SQ = 1000;
const int LG = 21;
const int nax = 1e6+100;

const pii neu = mp(inf, -inf);

pii comb(pii a, pii b) {
    return mp(min(a.fi, b.fi), max(a.se, b.se));
}

struct segTree {
    int n;
    vector<pii> t;
    segTree(int n) : n(n), t(2 * n, neu) {}
    void upd(int v, pii x) {
        t[v += n] = x;
        for(v >>= 1; v; v >>= 1) t[v] = comb(t[v * 2], t[v * 2 + 1]);
    }
    pii get(int l, int r) {
        pii ret = neu;
        for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if(l & 1) ret = comb(ret, t[l]);
            if(!(r & 1)) ret = comb(ret, t[r]);
        }
        return ret;
    }
};
struct fenwick {
    int n;
    vi t;
    fenwick(int n) : n(n), t(n, 0) {}
    void upd(int v, int x) {
        for(int i = v; i < n; i |= i + 1) t[i] += x;
    }
    int get(int v) {
        int ret = 0;
        for(int i = v; i >= 0; i = (i & (i + 1)) - 1) ret += t[i];
        return ret;
    }
    int get(int l, int r) {
        //cout << l << ' ' << r << endl;
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};

int n, q;
string s;
int a[nax];
map<char, int> re;

int getAns(vector<segTree>& t, vector<fenwick>& f) {
    int ret = 0;
    pii _all = mp(-inf, inf);
    for(int i = 0; i < 3; i++) {
        pii g = t[i].get(0, n - 1);
        _all.fi = max(_all.fi, g.fi);
        _all.se = min(_all.se, g.se);
    }
    //for(int i = 0; i < n; i++) cout << a[i]; cout << endl;
    for(int who = 0; who < 3; who++) {
        pii g = t[(who + 1) % 3].get(0, n - 1);
        if(g.fi > g.se) ret += f[who].get(0, n - 1);
        else ret += f[who].get(0, min(g.fi - 1, t[(who + 2) % 3].get(0, n - 1).se)) + f[who].get(_all.fi, _all.se) + f[who].get(max(t[(who + 2) % 3].get(0, n - 1).fi, g.se + 1), n - 1);
        //if(a[0] == 2 && a[1] == 0 && a[2] == 2) cout << "! " << t[(who + 2) % 3].get(0, n - 1).fi << ' ' << t[(who + 2) % 3].get(0, n - 1).se << ' ' << ret << endl;
    }
    return ret;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(12); cout << fixed;
#ifdef HOME
    freopen("in.txt", "r", stdin);
#else
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#endif // HOME
    re['R'] = 0; re['P'] = 1; re['S'] = 2; //   
    cin >> n >> q >> s;
    vector<segTree> t(3, segTree(n));
    vector<fenwick> f(3, fenwick(n));
    for(int i = 0; i < n; i++) a[i] = re[s[i]], t[a[i]].upd(i, mp(i, i)), f[a[i]].upd(i, 1);
    cout << getAns(t, f) << '\n';
    while(q--) {
        int pos; char ch; cin >> pos >> ch; pos--;
        t[a[pos]].upd(pos, neu);
        f[a[pos]].upd(pos, -1);
        a[pos] = re[ch];
        t[a[pos]].upd(pos, mp(pos, pos));
        f[a[pos]].upd(pos, 1);
        cout << getAns(t, f) << '\n';
    }
}