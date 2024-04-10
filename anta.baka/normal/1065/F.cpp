/*

















*/

#include <cstdio>

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






#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
//#define int ll
#define NAME ""

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

const int maxn = 1e6;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 3e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;
const int di[] = {1, 1,-1,-1, 2, 2,-2,-2};
const int dj[] = {2,-2, 2,-2, 1,-1, 1,-1};
const int dii[] = {0, 1,-1, 0};
const int djj[] = {1, 0, 0,-1};
const int dx[] = {1, 1,-1,-1};
const int dy[] = {1,-1, 1,-1};
const int SQ = 1000;

int n, k;
vi g[maxn];
int p[maxn];
int up[maxn][21];
int add[maxn][1];

void dfs(int v) {
    up[v][0] = p[v];
    for(int i = 1; i < 21; i++) up[v][i] = up[up[v][i - 1]][i - 1];
    for(int to : g[v]) {
        dfs(to);
        add[v][0] += add[to][0];
        //add[v][1] += add[to][1];
    }
    if(g[v].empty()) {
        int u = v, d = k - 1;
        for(int i = 20; i >= 0; i--)
            if(d - (1 << i) >= 0) {
                d -= (1 << i);
                u = up[u][i];
            }
        add[v][0]++;
        if(u != 0) add[p[u]][0]--;
        //add[v][1]++;
        //if(u != 0 && p[u] != 0) add[p[p[u]]][1]--;
    }
}

int dp1[maxn], dp2[maxn];

void go(int v) {
    if(g[v].empty()) {
        dp1[v] = dp2[v] = 1;
    } else {
        for(int to : g[v]) go(to);
        if(!add[v][0]) {
            dp1[v] = 0;
        } else {
            for(int to : g[v]) dp1[v] += dp1[to];
        }
        for(int to : g[v]) dp2[v] += dp1[to];
        int res = 0;
        for(int to : g[v]) {
            res = max(res, dp2[to] - dp1[to]);
        }
        dp2[v] += res;
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    //assert(n != 1);
    //n = readInt(), k = readInt();
    for(int i = 1; i < n; i++) {
        int v; cin >> v; v--;
        //int v = readInt() - 1;
        p[i] = v; g[v].pb(i);
    }
    p[0] = 0;
    dfs(0);
    go(0);
    //writeInt
    cout << max(dp1[0], dp2[0]);
}