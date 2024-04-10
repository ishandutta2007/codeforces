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
const int nax = 1e6+100;

struct num {
    static const int MA = 1e9+7, MB = 1e9+9;
    int a, b;
    num() {}
    num(int a) : a((a%MA+MA)%MA), b((a%MB+MB)%MB) {}
    num(int a, int b) : a((a%MA+MA)%MA), b((b%MB+MB)%MB) {}
    num operator + (const num &he) const { return num(a+he.a, b+he.b); }
    num operator - (const num &he) const { return num(a-he.a, b-he.b); }
    num operator * (const num &he) const { return num((ll)a*he.a%MA, (ll)b*he.b%MB); }
    bool operator == (const num &he) const { return a==he.a && b==he.b; }
    bool operator != (const num &he) const { return a!=he.a || b!=he.b; }
};
mt19937 rnd(322);
const int P = max(239, int(rnd()));
num pw[nax], h[nax];

inline num get(int l, int r) {
    return h[r + 1] - h[l] * pw[r - l + 1];
}

int n, m;
char s[nax], t[nax];
int ans;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(2); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    readWord(s);
    readWord(t);
    n = strlen(s);
    m = strlen(t);
    pw[0] = 1;
    h[0] = 0;
    for(int i = 0; i < m; i++) {
        h[i + 1] = h[i] * P + t[i];
        pw[i + 1] = pw[i] * P;
    }
    int c0 = 0, c1 = 0;
    if(s[0] == '1') {
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') c0++;
        else c1++;
    }
    for(int l = 1; ; l++) {
        if(l * c0 >= m) break;
        if((m - l * c0) % c1) continue;
        int k = (m - l * c0) / c1;

        num h0 = get(0, l - 1);
        int j = 1;
        int pt = l;
        bool ok = true;
        while(s[j] == '0') {
            if(get(pt, pt + l - 1) != h0) {
                ok = false; break;
            }
            pt += l;
            j++;
        }
        if(!ok) continue;
        num h1 = get(pt, pt + k - 1);
        if(h0 == h1) continue;
        pt += k;
        j++;
        while(j < n) {
            if(s[j] == '0') {
                if(h0 != get(pt, pt + l - 1)) {
                    ok = false; break;
                }
                j++;
                pt += l;
            } else {
                if(h1 != get(pt, pt + k - 1)) {
                    ok = false; break;
                }
                j++;
                pt += k;
            }
        }
        ans += ok;
    }
    cout << ans;
}