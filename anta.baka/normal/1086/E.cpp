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
#define NAME "improvements"

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

const int M = 998244353;
const int mod = 1e9+7;
const int inf = 1e9+100;
const ll inf64 = 1e18L;
const ld pi = acos(-1.0L);
const ld eps = 1e-9L;
const int di[] = {0, 1,-1, 0};
const int dj[] = {1, 0, 0,-1};
const int SQ = 1000;
const int LG = 21;
const int nax = 2e3+100;

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
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};

int fac[nax];

int pw(int a, int b) {
    if(!b) return 1;
    if(b & 1) return (ll)a * pw(a, b - 1) % M;
    a = pw(a, b >> 1);
    return (ll)a * a % M;
}

int cnk(int n, int k) {
    if(n < k) return 0;
    return (ll)fac[n] * pw((ll)fac[k] * fac[n - k] % M, M - 2) % M;
}

int n, a[nax][nax], kek[nax][nax];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(12); cout << fixed;
#ifdef HOME
    freopen("in.txt", "r", stdin);
#else
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#endif // HOME

    // kek[n][k] = cnk(k, 1) * (n - 1)! - cnk(k, 2) * (n - 2)! + cnk(k, 3) * (n - 3)! - ... How to calc in O(n^2) ???


    fac[0] = 1;
    for(int i = 1; i < nax; i++) fac[i] = (ll)fac[i - 1] * i % M;

    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j], --a[i][j];

//    for(int a = 1; a <= n; a++) for(int b = 1; b <= a; b++) {
//        for(int k = 1; k <= b; k++) kek[a][b] = ((ll)kek[a][b] + M + ((k & 1) ? 1 : -1) * ((ll)fac[a - k] * cnk(b, k) % M)) % M;
//    }

    kek[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= i; k++) kek[i][i] = ((ll)kek[i][i] + M + ((k & 1) ? 1 : -1) * ((ll)fac[i - k] * cnk(i, k) % M)) % M;
        kek[i][i] = (fac[i] - kek[i][i] + M) % M;
        for(int j = i - 1; j >= 0; j--) kek[i][j] = (kek[i][j + 1] + kek[i - 1][j]) % M;
    }

    //for(int a = 0; a <= n; a++) for(int b = 0; b <= a; b++) kek[a][b] = (fac[a] - kek[a][b] + M) % M;

    //for(int i = 1; i <= n; i++, cout << endl) for(int j = 0; j <= n; j++) cout << kek[i][j] << ' '; return 0;

    int tot = kek[n][n];
    int ans = 0;
    int pw = 1;

    for(int i = n - 1; i > 0; i--) {
        fenwick t(n), ti(n);
        for(int j = 0; j < n; j++) t.upd(j, 1), ti.upd(j, 1);
        int cl = 0;

        // p[j] < a[i][j] p[j] != a[i - 1][j]
        for(int j = 0; j < n; j++) {
            int com = t.get(n - 1) - t.get(a[i - 1][j], a[i - 1][j]);

            int tot1 = ti.get(a[i][j] - 1) - (a[i - 1][j] < a[i][j] ? ti.get(a[i - 1][j], a[i - 1][j]) : 0);
            int com1 = t.get(a[i][j] - 1) - (a[i - 1][j] < a[i][j] ? t.get(a[i - 1][j], a[i - 1][j]) : 0);

            { // p[j] - com
                int cnt = com1;
                if(com) cl = (cl + (ll)cnt * kek[n - 1 - j][com - 1] % M) % M;
            }
            { // p[j] - other
                int cnt = tot1 - com1;
                cl = (cl + (ll)cnt * kek[n - 1 - j][com] % M) % M;
            }

            if(t.get(a[i][j], a[i][j])) t.upd(a[i][j], -1);
            if(t.get(a[i - 1][j], a[i - 1][j])) t.upd(a[i - 1][j], -1);
            ti.upd(a[i][j], -1);
        }

        ans = (ans + (ll)cl * pw % M) % M;
        pw = (ll)pw * tot % M;
    }

    { // i == 0
        fenwick t(n);
        for(int j = 0; j < n; j++) t.upd(j, 1);
        int cl = 0;

        for(int j = 0; j < n; j++) {
            int cnt = t.get(a[0][j] - 1);
            cl = (cl + (ll)cnt * kek[n - 1 - j][0] % M) % M;
            t.upd(a[0][j], -1);
        }

        ans = (ans + (ll)cl * pw % M) % M;
    }

    cout << ans;
}