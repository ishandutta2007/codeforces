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





//
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
#define x() real()
#define y() imag()
#define int ll
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
const int nax = 3000;

int n;
string a[nax], b[nax];
bitset<nax> same;
string mida, midb;
int L[nax], R[nax];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(10); cout << fixed;
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int I = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            same[i] = 1;
        } else {
            if(I == -1) I = i;
            int l = 0;
            while(a[i][l] == b[i][l]) l++;
            int r = sz(a[i]) - 1;
            while(a[i][r] == b[i][r]) r--;
            string cura = a[i].substr(l, r-l+1);
            string curb = b[i].substr(l, r-l+1);
            if(mida.empty()) mida = cura;
            else if(cura != mida) return cout << "NO", 0;
            if(midb.empty()) midb = curb;
            else if(curb != midb) return cout << "NO", 0;
            L[i] = l, R[i] = r;
        }
    }
    while(true) {
        bool ok = true;
        char ch = '1';
        for(int i = 0; i < n; i++) if(!same[i]) {
            if(L[i] == 0) ok = false;
            else if(ch == '1') ch = a[i][L[i]-1];
            else if(ch != a[i][L[i]-1]) ok = false;
        }
        if(!ok) break;
        for(int i = 0; i < n; i++) if(!same[i]) L[i]--;
    }
    while(true) {
        bool ok = true;
        char ch = '1';
        for(int i = 0; i < n; i++) if(!same[i]) {
            if(R[i] == sz(a[i])-1) ok = false;
            else if(ch == '1') ch = a[i][R[i]+1];
            else if(ch != a[i][R[i]+1]) ok = false;
        }
        if(!ok) break;
        for(int i = 0; i < n; i++) if(!same[i]) R[i]++;
    }
    string s = a[I].substr(L[I], R[I]-L[I]+1);
    int SZ = sz(s);
    s.push_back('#');
    string t;
    vi p;
    for(int i = 0; i < n; i++) {
        if(same[i]) continue;
        t = s + a[i];
        p.assign(sz(t), 0);
        for(int j = 1; j < sz(t); j++) {
            int k = p[j-1];
            while(k && t[k] != t[j]) k = p[k-1];
            k += (t[k] == t[j]);
            p[j] = k;
            if(p[j] >= SZ && j-sz(s) < R[i]) return cout << "NO", 0;
        }
    }
    for(int i = 0; i < n; i++) if(same[i]) s += a[i] + '#';
    p.assign(sz(s), 0);
    for(int i = 1; i < sz(s); i++) {
        int k = p[i-1];
        while(k && s[k] != s[i]) k = p[k-1];
        k += (s[k] == s[i]);
        p[i] = k;
        if(p[i] >= SZ) return cout << "NO", 0;
    }
    cout << "YES\n";
    cout << a[I].substr(L[I], R[I]-L[I]+1) << '\n';
    cout << b[I].substr(L[I], R[I]-L[I]+1) << '\n';
}