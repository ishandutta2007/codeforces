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
#define x first
#define y second
//#define x real
//#define y imag
//#define int ll
//#define NAME ""

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

//using pnt = complex<ld>;
//
//istream &operator >> (istream &in, pnt &p) {
//    ld a, b;
//    in >> a >> b;
//    p = {a, b};
//    return in;
//}
//
//ld crs(pnt a, pnt b) {
//    return a.x()*b.y() - a.y()*b.x();
//}

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
const int L = 8;
const int nax = 32e6;

int T;
vll nn, kk, alk, fz[50];
bitset<nax> isp;
vi alp;
vector<vector<pll>> g[50];
vll d[50];

void dio(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return;
    }
    dio(b, a % b, x, y);
    ll x1 = y;
    y = x - y * (a / b);
    x = x1;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(10); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    isp.set();
    for(int i = 2; i * i < nax; i++) {
        if(isp[i]) {
            for(int j = i * i; j < nax; j += i) {
                isp[j] = 0;
            }
        }
    }
    alp.reserve(isp.count() - 2);
    for(int i = 2; i < nax; i++) {
        if(isp[i]) {
            alp.pb(i);
        }
    }
    cin >> T;
    nn.resize(T);
    kk.resize(T);
    alk.resize(T);
    for(int i = 0; i < T; i++) {
        cin >> nn[i] >> kk[i];
        alk[i] = kk[i];
    }
    sort(all(alk));
    alk.erase(unique(all(alk)), alk.end());
    for(int i = 0; i < sz(alk); i++) {
        ll k = alk[i];
        for(int x : alp) {
            if(k % x == 0) {
                fz[i].pb(x);
                while(k % x == 0) {
                    k /= x;
                }
            }
        }
        if(k != 1) {
            fz[i].pb(k);
        }
    }
    for(int i = 0; i < sz(alk); i++) {
        if(sz(fz[i]) < 3) {
            continue;
        }
        int N = fz[i][0];
        g[i].resize(N);
        for(int u = 0; u < N; u++) {
            for(ll x : fz[i]) {
                g[i][u].pb({(u + x) % N, x});
            }
        }
        d[i].resize(N, inf64);
        d[i][0] = 0;
        set<pll> q;
        q.insert({0, 0});
        while(!q.empty()) {
            int v = q.begin()->y;
            q.erase(q.begin());
            for(pll e : g[i][v]) {
                if(d[i][v] + e.y < d[i][e.x]) {
                    q.erase({d[i][e.x], e.x});
                    d[i][e.x] = d[i][v] + e.y;
                    q.insert({d[i][e.x], e.x});
                }
            }
        }
    }
    for(int i = 0; i < T; i++) {
        if(kk[i] == 1) {
            cout << "NO\n";
            continue;
        }
        int id;
        for(int j = 0; j < sz(alk); j++) {
            if(alk[j] == kk[i]) {
                id = j;
            }
        }
        if(sz(fz[id]) == 1) {
            cout << (nn[i] % fz[id][0] == 0 ? "YES\n" : "NO\n");
        } else if(sz(fz[id]) == 2) {
            ll a = fz[id][0], b = fz[id][1];
            ll x, y;
            dio(a, b, x, y);
            y %= fz[id][0];
            if(y < 0) {
                y += fz[id][0];
            }
            ll z = (y * (nn[i] % fz[id][0]) % fz[id][0]) * fz[id][1];
            cout << (z <= nn[i] ? "YES\n" : "NO\n");
        } else {
            cout << (d[id][nn[i] % fz[id][0]] <= nn[i] ? "YES\n" : "NO\n");
        }
    }
}