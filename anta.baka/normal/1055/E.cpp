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





//
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
#define x() real()
#define y() imag()
#define int ll
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

const int M = 998244353;
const int mod = 1e9+7;
const int inf = 1e9+100;
const ll inf64 = 1e18L;
const ld pi = acos(-1.0L);
const ld eps = 1e-5L;
const int di[] = {1, 1,-1,-1, 2, 2,-2,-2};
const int dj[] = {2,-2, 2,-2, 1,-1, 1,-1};
const int dii[] = {0, 1,-1, 0};
const int djj[] = {1, 0, 0,-1};
const int dx[] = {1, 1,-1,-1};
const int dy[] = {1,-1, 1,-1};
const int SQ = 1000;
const int nax = 1500;

int n, s, m, k, a[nax], l[nax], r[nax], ins[nax];

bool ok(int R) {
    vi aa;
    for(int i = 0; i < n; i++) if(a[i] <= R) aa.pb(i);
    if(sz(aa) < k) return false;
    vector<pii> re;
    for(int i = 0; i < s; i++) {
        int l1 = lower_bound(all(aa), l[i]) - aa.begin();
        int r1 = int(upper_bound(all(aa), r[i]) - aa.begin()) - 1;
        if(l1 <= r1) re.pb({l1, r1});
    }
    int nn = sz(aa);
    int ss = sz(re);
    vi best(nn, inf);
    for(int i = 0; i < nn; i++) {
        for(int j = 0; j < ss; j++) {
            if(re[j].fi <= i && i <= re[j].se) {
                best[i] = min(best[i], re[j].fi);
            }
        }
    }
    vector<vi> dp(ss+1, vi(nn, 0));
    for(int i = 1; i <= ss; i++) {
        for(int j = 0; j < nn; j++) {
            dp[i][j] = (j ? dp[i][j - 1] : 0);
            if(best[j] != inf) {
                int lb = best[j];
                dp[i][j] = max(dp[i][j], (lb ? dp[i-1][lb - 1] : 0) + (j-lb+1));
            }
        }
    }
    return (dp[min(m,ss)][nn-1] >= k);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(10); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    cin >> n >> s >> m >> k;
    for(int i = 0; i < n; i++) cin >> a[i], ins[i] = a[i];
    sort(ins, ins + n);
    for(int i = 0; i < s; i++) cin >> l[i] >> r[i], l[i]--, r[i]--;
    if(!ok(ins[n - 1])) return cout << -1, 0;
    int lf = 0, rg = n - 1;
    while(lf < rg) {
        int md = (lf + rg) >> 1;
        if(ok(ins[md])) rg = md;
        else lf = md + 1;
    }
    cout << ins[lf];
}