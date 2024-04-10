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
#define int ll
#define NAME "kbest"

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

const int maxn = 1e5;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 3e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;
const int di[] = {0, 0, 1,-1, 1,-1, 1,-1};
const int dj[] = {1,-1, 0, 0, 1,-1,-1, 1};
const int SQ = 1000;

int t[4 * maxn], add[4 * maxn];

void push(int v) {
    if(add[v]) {
        t[v * 2 + 1] += add[v];
        add[v * 2 + 1] += add[v];
        t[v * 2 + 2] += add[v];
        add[v * 2 + 2] += add[v];
        add[v] = 0;
    }
}

void build(int v, int l, int r) {
    if(l == r) {
        t[v] = inf;
    } else {
        int m = (l + r) >> 1;
        build(v * 2 + 1, l, m);
        build(v * 2 + 2, m + 1, r);
        t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
    }
}

int qt;

void upd(int v, int l, int r, int l1, int r1, int x) {
    if(r < l1 || r1 < l) return;
    if(l1 <= l && r <= r1) {
        if(qt == 1) {
            add[v] += x;
            t[v] += x;
        } else {
            t[v] = x;
        }
        return;
    }
    push(v);
    int m = (l + r) >> 1;
    upd(v * 2 + 1, l, m, l1, r1, x);
    upd(v * 2 + 2, m + 1, r, l1, r1, x);
    t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
}

int get(int v, int l, int r, int l1, int r1) {
    if(r < l1 || r1 < l) return inf;
    if(l1 <= l && r <= r1) return t[v];
    push(v);
    int m = (l + r) >> 1;
    return min(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m + 1, r, l1, r1));
}

int n, L, w[maxn], up[maxn][18], tin[maxn], tout[maxn], tik_tak;
ll S, ps[maxn];
vi g[maxn], out[maxn];

inline ll fp(int v) {
    if(!v) return 0;
    return ps[up[v][0]];
}

void dfs(int v, int p) {
    tin[v] = tik_tak;
    up[v][0] = p;
    for(int i = 1; i < 18; i++) up[v][i] = up[up[v][i - 1]][i - 1];
    ps[v] = ps[p] + w[v];
    for(int to : g[v]) {
        dfs(to, v);
    }
    int u = v, l = L - 1;
    for(int i = 17; i >= 0; i--)
        if(l - (1 << i) >= 0 && ps[v] - fp(up[u][i]) <= S) u = up[u][i], l -= (1 << i);
    out[u].pb(v);
    tout[v] = tik_tak++;
}

int dp[maxn];

void solve(int v) {
    int sum = 0;
    for(int to : g[v]) {
        solve(to);
        sum += dp[to];
    }
    qt = 1;
    for(int to : g[v]) upd(0, 0, n - 1, tin[to], tout[to], sum - dp[to]);
    qt = 0;
    upd(0, 0, n - 1, tout[v], tout[v], sum + 1);
    dp[v] = get(0, 0, n - 1, tin[v], tout[v]);
    for(int u : out[v]) upd(0, 0, n - 1, tout[u], tout[u], inf);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    cin >> n >> L >> S;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        if(w[i] > S) return cout << -1, 0;
    }
    for(int i = 1; i < n; i++) {
        int j; cin >> j; j--; g[j].pb(i);
    }
    dfs(0, 0);
    build(0, 0, n - 1);
    solve(0);
    cout << dp[0];
}