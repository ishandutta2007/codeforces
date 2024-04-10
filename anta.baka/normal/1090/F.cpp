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

int get(int i, int j, int k) {
    cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
    int x; cin >> x; return x;
}

int n;
vector<vi> ad = {
    {0, 1, 2},
    {0, 1, 3},
    {0, 1, 4},
    {0, 2, 3},
    {0, 2, 4},
    {0, 3, 4},
    {1, 2, 3},
    {1, 2, 4},
    {1, 3, 4},
    {2, 3, 4}
};

int ans[1000];

void rest(int s) {
    vector<pii> qu;
    for(int i = 0; i < 10; i++) qu.pb(mp(get(s + ad[i][0], s + ad[i][1], s + ad[i][2]), i));
    sort(all(qu));
    int a = (qu[0].fi - qu[9].fi + qu[3].fi) / 2;
    int e = qu[3].fi - a;
    int c = qu[0].fi - a;
    int b = qu[8].fi - e;
    int d = qu[1].fi - a;
    vi p = {a, b, c, d, e};
    sort(all(p));
    bool done = false;
    do {
        vector<pii> cur;
        for(int i = 0; i < 10; i++) cur.pb(mp(min({p[ad[i][0]], p[ad[i][1]], p[ad[i][2]]}) + max({p[ad[i][0]], p[ad[i][1]], p[ad[i][2]]}), i));
        sort(all(cur));
        if(cur == qu) {
            for(int t = 0; t < 5; t++) ans[s + t] = p[t];
            done = true;
            break;
        }
    } while(next_permutation(all(p)));
    if(!done) {
        int a = (qu[0].fi - qu[9].fi + qu[5].fi) / 2;
        int e = qu[5].fi - a;
        int c = qu[0].fi - a;
        int b = qu[8].fi - e;
        int d = qu[1].fi - a;
        vi p = {a, b, c, d, e};
        sort(all(p));
        bool done = false;
        do {
            vector<pii> cur;
            for(int i = 0; i < 10; i++) cur.pb(mp(min({p[ad[i][0]], p[ad[i][1]], p[ad[i][2]]}) + max({p[ad[i][0]], p[ad[i][1]], p[ad[i][2]]}), i));
            sort(all(cur));
            if(cur == qu) {
                for(int t = 0; t < 5; t++) ans[s + t] = p[t];
                done = true;
                break;
            }
        } while(next_permutation(all(p)));
        assert(done);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(8); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    cin >> n;
    for(int s = 0; s + 5 - 1 < n; s += 5) rest(s);
    if(n % 5) rest(n - 5);
    cout << "! ";
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}