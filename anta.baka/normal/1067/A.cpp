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
const int inf = 1e9+100;
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
const int nax = 2e5;

int n, a[nax];
int dp[nax][201][2];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[0] != -1) dp[0][a[0]][0] = 1;
    else for(int i = 1; i <= 200; i++) dp[0][i][0] = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] != -1) {
            for(int j = 1; j < a[i]; j++) {
                dp[i][a[i]][0] = (dp[i][a[i]][0] + (ll)dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
            }
            dp[i][a[i]][1] = (dp[i - 1][a[i]][0] + dp[i - 1][a[i]][1]) % mod;
            for(int j = a[i] + 1; j <= 200; j++) {
                dp[i][a[i]][1] = (dp[i][a[i]][1] + dp[i - 1][j][1]) % mod;
            }
        } else {
            int s1 = 0, s2 = 0;
            for(int j = 2; j <= 200; j++) s2 = (s2 + dp[i - 1][j][1]) % mod;
            for(int k = 1; k <= 200; k++) {
                dp[i][k][0] = s1;
                dp[i][k][1] = (s2 + dp[i - 1][k][0] + (ll)dp[i - 1][k][1]) % mod;
                if(k != 200) {
                    s1 = (s1 + (ll)dp[i - 1][k][0] + dp[i - 1][k][1]) % mod;
                    s2 = (s2 + mod - dp[i - 1][k + 1][1]) % mod;
                }
            }
        }
    }
    //cout << dp[1][2][0] << endl;
    //for(int i = 1; i <= 5; i++) cout << dp[2][i][0] << ' ' << dp[2][i][1] << endl;
    int ans = 0;
    for(int i = 1; i <= 200; i++) ans = (ans + dp[n - 1][i][1]) % mod;
    cout << ans;
}