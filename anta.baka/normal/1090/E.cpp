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
const int nax = 3e5;

mt19937 rnd(322);

const int dx[] = {1, 1,-1,-1, 2, 2,-2,-2};
const int dy[] = {2,-2, 2,-2, 1,-1, 1,-1};

int was[8][8];
vector<pii> cpa, pa;

bool in(int i, int j) {
    return (0 <= i && i < 8 && 0 <= j && j < 8);
}

int cfr(int i, int j) {
    int ret = 0;
    for(int w = 0; w < 8; w++) {
        int ii = i + dx[w];
        int jj = j + dy[w];
        if(in(ii, jj) && !was[ii][jj]) ret++;
    }
    return ret;
}

int n;
vi st, en;
vector<pii> fr, to;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(8); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    while(true) {
        int i = 0, j = 0;
        memset(was, 0, sizeof(was));
        was[0][0] = 1;
        cpa.assign(1, mp(i, j));
        while(true) {
            int oi, oj, opt = 10;
            for(int w = 0; w < 8; w++) {
                int ii = i + dx[w];
                int jj = j + dy[w];
                if(in(ii, jj) && !was[ii][jj]) {
                    int c = cfr(ii, jj);
                    if(c < opt || c == opt && (rnd() & 1)) {
                        oi = ii; oj = jj; opt = c;
                    }
                }
            }
            if(opt == 10) break;
            was[oi][oj] = 1;
            cpa.pb(mp(oi, oj));
            i = oi; j = oj;
        }
        if(sz(cpa) == 64) {
            pa = cpa;
            break;
        }
    }
    for(int i = 0; i < 64; i++) {
        was[pa[i].fi][pa[i].se] = i;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        char a, b; cin >> a >> b;
        st.pb(was[b - '1'][a - 'a']);
    }
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(8 * i + j < n) {
                en.pb(was[i][j]);
            }
        }
    }
    sort(all(st));
    sort(all(en));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(st[j] < en[j]) {
                int pt = st[j];
                bool ok = true;
                while(pt <= en[j]) { if(j != n - 1 && st[j + 1] == pt) { ok = false; break; } pt++; }
                if(ok) {
                    pii cur = pa[st[j]];
                    pt = st[j];
                    do {
                        pt++;
                        fr.pb(cur);
                        to.pb(pa[pt]);
                        cur = pa[pt];
                    } while(pt < en[j]);
                    st[j] = en[j];
                }
            } else if(en[j] < st[j]) {
                int pt = st[j];
                bool ok = true;
                while(pt >= en[j]) { if(j != 0 && st[j - 1] == pt) { ok = false; break; } pt--; }
                if(ok) {
                    pii cur = pa[st[j]];
                    pt = st[j];
                    do {
                        pt--;
                        fr.pb(cur);
                        to.pb(pa[pt]);
                        cur = pa[pt];
                    } while(pt > en[j]);
                    st[j] = en[j];
                }
            }
        }
    }
    cout << sz(fr) << '\n';
    for(int i = 0; i < sz(fr); i++) {
        cout << char(fr[i].se + 'a') << fr[i].fi + 1 << '-' << char(to[i].se + 'a') << to[i].fi + 1 << '\n';
    }
}