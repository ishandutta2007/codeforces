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

#define shandom_ruffle random_shuffle
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
const int inf = 1e9 + 1;
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

char a[2000][2000];
int re[2000][2000];
int siz[4000000];
vi g[4000000];
vector<pii> ed[4000000];
vector<pii> d(4000000, make_pair(inf, inf));

pii operator + (const pii &a, const pii &b) {
    return pii(a.x + b.x, a.y + b.y);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    int r, c; cin >> r >> c; r--; c--;
    int x, y; cin >> x >> y;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int V = 0;
    memset(re, -1, sizeof(re));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '.' && re[i][j] == -1) {
                for(int ii = i; ii < n && a[ii][j] == '.'; ii++) re[ii][j] = V, siz[V]++;
                V++;
            }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) if(a[i][j] == '.') {
            if(j > 0 && a[i][j - 1] == '.') {
                g[re[i][j]].pb(re[i][j - 1]);
                ed[re[i][j]].pb({1, 0});
            }
            if(j < m - 1 && a[i][j + 1] == '.') {
                g[re[i][j]].pb(re[i][j + 1]);
                ed[re[i][j]].pb({0, 1});
            }
        }
    queue<int> q;
    q.push(re[r][c]);
    d[re[r][c]] = {0, 0};
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int i = 0; i < sz(g[v]); i++) {
            int to = g[v][i];
            if(d[to].x == inf) {
                d[to] = d[v] + ed[v][i];
                q.push(to);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < V; i++) if(d[i].x <= x && d[i].y <= y) ans += siz[i];
    cout << ans;
}