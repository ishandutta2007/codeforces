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
//#define int ll
#define NAME ""

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

const int maxn = 5e5;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;
const int di[] = {1, 1,-1,-1, 2, 2,-2,-2};
const int dj[] = {2,-2, 2,-2, 1,-1, 1,-1};
const int dii[] = {0, 1,-1, 0};
const int djj[] = {1, 0, 0,-1};
const int dx[] = {1, 1,-1,-1};
const int dy[] = {1,-1, 1,-1};
const int SQ = 1000;
const int L = 19;
const int HF = 65536;

struct DSU {
    int n;
    vi p, s, he;
    DSU(int n) : p(n+1), s(n+1, 1), he(n+1, n) { iota(all(p), 0); s[n] = 0; }
    int get(int v) { return p[v]==v ? v : p[v]=get(p[v]); }
    bool dif(int u, int v) {
        if((u=get(u)) == (v=get(v))) return false;
        else {
            if(he[u] != v) {
                int A = u, B = he[v];
                int C = v, D = he[u];
                {
                    if(s[A] < s[B]) swap(A, B);
                    s[A] += s[B]; p[B] = A;
                }
                {
                    if(s[C] < s[D]) swap(C, D);
                    s[C] += s[D]; p[D] = C;
                }
                he[A] = C;
                he[C] = A;
            }
            return true;
        }
    }
};

struct edge {
    int u, v, w, id;
    bool operator < (const edge &he) const {
        return w > he.w;
    }
} a[499500];

int n, m, q;

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    n = readInt();
    m = readInt();
    q = readInt();
    for(int i = 0; i < m; i++) {
        a[i] = {readInt() - 1, readInt() - 1, readInt(), i};
    }
    sort(a, a + m);
    while(q--) {
        int l = readInt() - 1, r = readInt() - 1;
        int ans = -1;
        DSU dsu(n);
        for(int i = 0; i < m && ans == -1; i++) {
            if(l <= a[i].id && a[i].id <= r && !dsu.dif(a[i].u, a[i].v)) {
                ans = a[i].w;
            }
        }
        writeInt(ans, '\n');
    }
}