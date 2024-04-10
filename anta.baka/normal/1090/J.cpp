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
//#define NAME ""

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
const int LG = 19;
const int nax = 2e5+100;

struct suffixArray {
    struct tup {
        int id, fi, se;
        bool operator < (const tup &he) const {
            return fi < he.fi || fi == he.fi && se < he.se;
        }
    } a[nax], b[nax];

    int n, K;
    int pw[LG];
    int p[LG][nax];
    int sa[nax];

    int cnt[nax];

    int lc[nax];
    int lg[nax];
    int st[LG][nax];

    void init(string& s) {
        pw[0] = 1;
        for(int i = 1; i < LG; i++) pw[i] = 2 * pw[i - 1];
        n = sz(s);
        for(int i = 0; i < n; i++) p[0][i] = s[i] - 'a';
        if(n == 1) p[0][0] = 0;
        K = 1;
        for(int i = 1; pw[i - 1] < n; i++, K++) {
            for(int j = 0; j < n; j++) {
                a[j] = {j, p[i - 1][j], j + pw[i - 1] < n ? p[i - 1][j + pw[i - 1]] : -1};
            }

            memset(cnt, 0, sizeof(cnt));
            for(int j = 0; j < n; j++) cnt[a[j].se + 1]++;
            for(int j = 1; j < nax; j++) cnt[j] += cnt[j - 1];
            for(int j = n - 1; j >= 0; j--) b[--cnt[a[j].se + 1]] = a[j];
            memset(cnt, 0, sizeof(cnt));
            for(int j = 0; j < n; j++) cnt[b[j].fi]++;
            for(int j = 1; j < nax; j++) cnt[j] += cnt[j - 1];
            for(int j = n - 1; j >= 0; j--) a[--cnt[b[j].fi]] = b[j];

            for(int j = 0; j < n; j++) {
                p[i][a[j].id] = (j != 0 && a[j].fi == a[j - 1].fi && a[j].se == a[j - 1].se ? p[i][a[j - 1].id] : j);
            }
        }
        for(int i = 0; i < n; i++) sa[p[K - 1][i]] = i;

        for(int i = n - 2; i >= 0; i--) lc[i] = lcp(sa[i], sa[i + 1]);
        for(int i = 2; i < nax; i++) lg[i] = lg[i >> 1] + 1;
        for(int i = 0; i < n; i++) st[0][i] = lc[i];
        for(int j = 1; j < LG; j++) for(int i = 0; i + pw[j] - 1 < n; i++) st[j][i] = min(st[j - 1][i], st[j - 1][i + pw[j - 1]]);
    }

    int get(int l, int r) {
        if(l > r) swap(l, r);
        r--;
        int u = lg[r - l + 1];
        return min(st[u][l], st[u][r - pw[u] + 1]);
    }

    int flcp(int i, int j) {
        if(i == j) return n - i;
        return get(p[K - 1][i], p[K - 1][j]);
    }

    int lcp(int i, int j) {
        if(i == j) return n - i;
        int ret = 0;
        for(int x = K - 1; x >= 0 && i < n && j < n; x--) {
            if(p[x][i] == p[x][j]) {
                ret += pw[x];
                i += pw[x];
                j += pw[x];
            }
        }
        return ret;
    }
};

suffixArray a, b, ab;

string s, t, tmp;
int n, m;

inline bool cmp1(int i, int j) {
    int cl = ab.flcp(i, j + n);
    if(cl >= min(n - i, m - j)) {
        if(n - i < m - j) return true;
        return false;
    }
    return s[i + cl] < t[j + cl];
}

inline bool cmp2(int i, int j) {
    int cl = ab.flcp(i, j + n);
    if(cl >= min(n - i, m - j)) {
        return true;
    }
    return s[i + cl] > t[j + cl];
}

int pfun[nax];
vi g[nax];

pii lr[nax];

ll ans;

bitset<nax> want;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(8); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    cin >> s >> t;
    swap(s, t);
    n = sz(s), m = sz(t);
    for(int i = 1; i < n; i++) {
        int k = pfun[i - 1];
        while(k != 0 && s[k] != s[i]) k = pfun[k - 1];
        k += (s[k] == s[i]);
        pfun[i] = k;
    }
    for(int v = 1; v < n; v++) {
        int u = pfun[v] - 1;
        if(u != -1) {
            g[n - 1 - u].pb(n - 1 - v);
            want[n - (v - u)] = 1;
        }
    }
    reverse(all(s));
    reverse(all(t));
    a.init(s);
    b.init(t);
    tmp = s + t;
    ab.init(tmp);

    for(int i = 0; i < n; i++) if(want[i]) {
        lr[i] = mp(inf, -inf);
        if(!cmp1(i, b.sa[m - 1]) || !cmp2(i, b.sa[0])) continue;
        int lf = 0, rg = m - 1;
        while(lf < rg) {
            int md = (lf + rg) >> 1;
            if(cmp1(i, b.sa[md])) rg = md;
            else lf = md + 1;
        }
        lr[i].fi = lf;
        lf = 0, rg = m - 1;
        while(lf < rg) {
            int md = (lf + rg + 1) >> 1;
            if(cmp2(i, b.sa[md])) lf = md;
            else rg = md - 1;
        }
        lr[i].se = lf;
        if(lr[i].fi > lr[i].se) lr[i] = mp(inf, -inf);
    }

    ans = (ll)n * m;
    for(int v = 0; v < n; v++) if(!g[v].empty()) {
        vector<pii> seg;
        for(int to : g[v]) {
            pii ca = lr[n - (v - to)];
            if(ca.fi <= ca.se) seg.pb(ca);
        }
        if(seg.empty()) continue;
        sort(all(seg));
        int l = seg[0].fi, r = seg[0].fi;
        for(int i = 0; i < sz(seg); i++) {
            if(r < seg[i].fi) {
                ans -= r - l + 1;
                l = seg[i].fi;
            }
            r = max(r, seg[i].se);
        }
        ans -= r - l + 1;
    }
    cout << ans;
}