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

const int maxn = 2e5;
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

pii operator + (const pii &a, const pii &b) {
    return pii(a.x + b.x, a.y + b.y);
}

int n;
bool ok(int ii, int jj) {
    return 0 <= ii && ii < n && 0 <= jj && jj < n;
}
pii dp[10][10][3];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    vector<vi> a(n, vi(n));
    vector<pii> pos(n * n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j], pos[a[i][j] - 1] = {i, j};
    int V = 3 * n * n;
    int AD = n * n;
    vector<vector<pii>> g(V, vector<pii>(V, {inf, inf}));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            int v = i * n + j;
            for(int w = 0; w < 3; w++)
                for(int o = 0; o < 3; o++) {
                    g[v + w * AD][v + o * AD] = {1, 1};
                }
            { // 
                for(int w = 0; w < 8; w++) {
                    int ii = i + di[w], jj = j + dj[w];
                    if(ok(ii, jj)) {
                        int vv = ii * n + jj;
                        g[v][vv] = {1, 0};
                    }
                }
            }
            { // 
                for(int w = 0; w < n; w++) {
                    for(int o = 0; o < 4; o++) {
                        int ii = i + dii[o] * w, jj = j + djj[o] * w;
                        if(ok(ii, jj)) {
                            int vv = ii * n + jj;
                            g[v + AD][vv + AD] = {1, 0};
                        }
                    }
                }
            }
            {
                for(int w = 0; w < n; w++) {
                    for(int o = 0; o < 4; o++) {
                        int ii = i + dx[o] * w, jj = j + dy[o] * w;
                        if(ok(ii, jj)) {
                            int vv = ii * n + jj;
                            g[v + 2 * AD][vv + 2 * AD] = {1, 0};
                        }
                    }
                }
            }
        }
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = 0; k < 3; k++) dp[i][j][k] = {inf, inf};
    for(int i = 0; i < 3; i++) dp[pos[0].x][pos[0].y][i] = {0, 0};
    for(int k = 1; k < AD; k++) {
        int i = pos[k - 1].x, j = pos[k - 1].y;
        int ii = pos[k].x, jj = pos[k].y;
        int v = i * n + j, vv = ii * n + jj;
        for(int w = 0; w < 3; w++) {
            for(int o = 0; o < 3; o++) {
                dp[ii][jj][o] = min(dp[ii][jj][o], dp[i][j][w] + g[v + w * AD][vv + o * AD]);
            }
        }
    }
    pii ans = {inf, inf};
    for(int w = 0; w < 3; w++) ans = min(ans, dp[pos[AD - 1].x][pos[AD - 1].y][w]);
    cout << ans.x << ' ' << ans.y;
}