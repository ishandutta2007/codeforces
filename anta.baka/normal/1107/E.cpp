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


///** Begin fast allocation */
//const int MAX_MEM = 2e8;
//int mpos = 0;
//char mem[MAX_MEM];
//inline void * operator new ( size_t n ) {
//	mpos += n;
//	return (void *)(mem + mpos - n);
//}
//inline void operator delete ( void * ) noexcept { } // must have!
///** End fast allocation */







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
#define int ll
//#define NAME "improvements"

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
const ll inf64 = 1e16L;
const ld pi = acos(-1.0L);
const ld eps = 1e-9L;
const int di[] = {0, 1,-1, 0};
const int dj[] = {1, 0, 0,-1};
const int SQ = 1000;
const int LG = 19;
const int nax = 3e5+1; // 

int n;
string s;
int a[100];
ll dp[100][100];
ll dpp[100][101];

main() {
  //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(12); cout << fixed;
#ifdef HOME
  freopen("in.txt", "r", stdin);
#else
  //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#endif // HOME
  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    dp[i][i] = a[0];
  }

  for(int l = n - 2; l >= 0; l--) {
    // take s[l]
    memset(dpp, -1, sizeof(dpp));
    dpp[l][1] = 0; // lel
    for(int r = l + 1; r < n; r++) {
      for(int c = 1; c <= r - l + 1; c++) {
        if(s[r] == s[l]) {
          dpp[r][c] = dpp[r - 1][c - 1];
        }
        for(int q = r; q - l >= c; q--) {
          if(dpp[q - 1][c] != -1) {
            dpp[r][c] = max(dpp[r][c], dpp[q - 1][c] + dp[q][r]);
          }
        }
        if(dpp[r][c] != -1) {
          dp[l][r] = max(dp[l][r], dpp[r][c] + a[c - 1]);
        }
      }

      for(int m = l; m < r; m++) {
        dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r]);
      }
    }
  }
  cout << dp[0][n - 1];
}