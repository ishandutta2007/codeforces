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
const int di[] = {1, 1,-1,-1, 2, 2,-2,-2};
const int dj[] = {2,-2, 2,-2, 1,-1, 1,-1};
const int dii[] = {0, 1,-1, 0};
const int djj[] = {1, 0, 0,-1};
const int dx[] = {1, 1,-1,-1};
const int dy[] = {1,-1, 1,-1};
const int SQ = 1000;
const int LG = 19;
const int nax = 5e5;

int n, m;
int s[nax];
set<pii> setik;
int tot;
vi fromi, toi, kindi;
vi cb[nax];
bitset<nax> tok;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(8); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i]; tot += s[i];
        for(int j = 0; j < s[i]; j++) { int c; cin >> c; c--; cb[c].pb(i); }
        setik.insert(mp(s[i], i));
    }
    int lo = tot / n, hi = (tot + n - 1) / n;
    for(int i = 0; i < m; i++) {
        if(cb[i].empty()) continue;
        sort(all(cb[i]), [&](int i1, int i2){ return s[i1] < s[i2]; });
        int S = sz(cb[i]);
        if(s[cb[i][S - 1]] <= hi) continue;
        for(int id : cb[i]) tok[id] = 1;
        int pt = S - 1;
        while(pt != 0 && s[cb[i][pt - 1]] > hi) pt--;
        auto it = setik.begin();
        vi cl;
        while(it != setik.end() && it->fi <= lo - 1 && sz(cl) != S - pt) {
            if(!tok[it->se]) cl.pb(it->se);
            it++;
        }
        if(cl.empty()) {
            for(int id : cb[i]) tok[id] = 0;
            continue;
        }
        while(S - pt > sz(cl)) pt++;
        for(int j = 0; j < sz(cl); j++) {
            int f = cb[i][pt + j];
            fromi.pb(f);
            int t = cl[j];
            toi.pb(t);
            kindi.pb(i);
            setik.erase(mp(s[f], f));
            s[f]--;
            setik.insert(mp(s[f], f));
            setik.erase(mp(s[t], t));
            s[t]++;
            setik.insert(mp(s[t], t));
            cb[i][pt + j] = t;
        }
        for(int id : cb[i]) tok[id] = 0;
    }
    for(int i = 0; i < m && (setik.rbegin()->fi != hi); i++) {
        if(cb[i].empty()) continue;
        sort(all(cb[i]), [&](int i1, int i2){ return s[i1] < s[i2]; });
        int S = sz(cb[i]);
        if(s[cb[i][S - 1]] <= hi) continue;
        for(int id : cb[i]) tok[id] = 1;
        int pt = S - 1;
        while(pt != 0 && s[cb[i][pt - 1]] > hi) pt--;
        auto it = setik.begin();
        vi cl;
        while(it != setik.end() && it->fi <= lo && sz(cl) != S - pt) {
            if(!tok[it->se]) cl.pb(it->se);
            it++;
        }
        if(cl.empty()) {
            for(int id : cb[i]) tok[id] = 0;
            continue;
        }
        while(S - pt > sz(cl)) pt++;
        for(int j = 0; j < sz(cl); j++) {
            int f = cb[i][pt + j];
            fromi.pb(f);
            int t = cl[j];
            toi.pb(t);
            kindi.pb(i);
            setik.erase(mp(s[f], f));
            s[f]--;
            setik.insert(mp(s[f], f));
            setik.erase(mp(s[t], t));
            s[t]++;
            setik.insert(mp(s[t], t));
            cb[i][pt + j] = t;
        }
        for(int id : cb[i]) tok[id] = 0;
    }
    for(int i = 0; i < m && (setik.begin()->fi != lo); i++) {
        if(cb[i].empty()) continue;
        sort(all(cb[i]), [&](int i1, int i2){ return s[i1] < s[i2]; });
        int S = sz(cb[i]);
        if(s[cb[i][S - 1]] < hi) continue;
        for(int id : cb[i]) tok[id] = 1;
        int pt = S - 1;
        while(pt != 0 && s[cb[i][pt - 1]] >= hi) pt--;
        auto it = setik.begin();
        vi cl;
        while(it != setik.end() && it->fi <= lo - 1 && sz(cl) != S - pt) {
            if(!tok[it->se]) cl.pb(it->se);
            it++;
        }
        if(cl.empty()) {
            for(int id : cb[i]) tok[id] = 0;
            continue;
        }
        while(S - pt > sz(cl)) pt++;
        for(int j = 0; j < sz(cl); j++) {
            int f = cb[i][pt + j];
            fromi.pb(f);
            int t = cl[j];
            toi.pb(t);
            kindi.pb(i);
            setik.erase(mp(s[f], f));
            s[f]--;
            setik.insert(mp(s[f], f));
            setik.erase(mp(s[t], t));
            s[t]++;
            setik.insert(mp(s[t], t));
            cb[i][pt + j] = t;
        }
        for(int id : cb[i]) tok[id] = 0;
    }
    set<pii> was;
    cout << sz(fromi) << '\n';
    for(int i = 0; i < sz(fromi); i++) {
        if(was.count(mp(fromi[i], kindi[i]))) assert(false);
        was.insert(mp(fromi[i], kindi[i]));
        if(was.count(mp(toi[i], kindi[i]))) assert(false);
        was.insert(mp(toi[i], kindi[i]));
        cout << fromi[i] + 1 << ' ' << toi[i] + 1 << ' ' << kindi[i] + 1 << '\n';
    }
}