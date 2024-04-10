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
//#define int ll
#define NAME "binary"

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

//const int M = 998244353;
const int mod = 1e9+7;
const int inf = 1e9+100;
const ll inf64 = 1e18L;
const ld pi = acos(-1.0L);
const ld eps = 1e-9L;
const int di[] = {0, 1,-1, 0};
const int dj[] = {1, 0, 0,-1};
const int SQ = 1000;
const int LG = 21;
const int nax = 1e6+100;

int t;
int n, k;
char a[nax], b[nax], s[nax];
bool busy[26], busy1[26];
int where[26], where1[26];

inline void add() {
    //memset(busy, false, sizeof(busy));
    //for(int i = 0; i < k; i++) if(where[i] != -1) busy[where[i]] = true;
    int pos = 0;
    for(int i = 0; i < k; i++) if(where[i] == -1) {
        while(busy[pos]) pos++;
        where[i] = pos;
        busy[pos++] = true;
    }
}

bool canup, candown, canbetw;
int ibetw;

inline void check(int l, int r) {
    canup = !busy[r];
    candown = !busy[l];
    canbetw = false;
    for(int i = l + 1; i < r; i++) if(!busy[i]) { canbetw = true; ibetw = i; break; }
}

inline bool trya(int pos) {
    if(pos == n) {
        add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); return true;
    }
    int ch = s[pos] - 'a';
    int l = a[pos] - 'a';
    int to = where[ch];
    if(to == -1) {
        check(l, k - 1);
        if(l < k - 1 && !busy[k - 1]) canbetw = true, ibetw = k - 1;
        if(canbetw) {
            where[ch] = ibetw;
            busy[ibetw] = true;
            add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); return true;
        }
        if(!candown) return false;
        where[ch] = l;
        busy[l] = true;
        return trya(pos + 1);
    } else {
        if(to < l) return false;
        if(l < to) {
            add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); return true;
        }
        if(l == to) return trya(pos + 1);
        else throw 1;
    }
}

inline bool tryb(int pos) {
    if(pos == n) {
        add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); return true;
    }
    int ch = s[pos] - 'a';
    int r = b[pos] - 'a';
    int to = where[ch];
    if(to == -1) {
        check(0, r);
        if(0 < r && !busy[0]) canbetw = true, ibetw = 0;
        if(canbetw) {
            where[ch] = ibetw;
            busy[ibetw] = true;
            add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); return true;
        }
        if(!canup) return false;
        where[ch] = r;
        busy[r] = true;
        return tryb(pos + 1);
    } else {
        if(to > r) return false;
        if(r > to) {
            add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); return true;
        }
        if(r == to) return tryb(pos + 1);
        else throw 1;
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout.precision(12); cout << fixed;
#ifdef HOME
    freopen("in.txt", "r", stdin);
#else
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#endif // HOME
    t = readInt();
    while(t--) {
        k = readInt();
        readWord(s);
        readWord(a);
        readWord(b);
        n = strlen(s);
        int idif = 0;
        memset(where, -1, sizeof(where));
        memset(busy, false, sizeof(busy));
        bool ok = true;
        while(idif != n && a[idif] == b[idif]) {
            int ch = s[idif] - 'a';
            if(where[ch] == -1) {
                if(busy[a[idif] - 'a']) {
                    ok = false;
                    break;
                }
                where[ch] = a[idif] - 'a';
                busy[where[ch]] = true;
            } else if(where[ch] != a[idif] - 'a') {
                ok = false;
                break;
            }
            idif++;
        }
        if(!ok) { writeWord("NO\n"); continue; }
        if(idif == n) { add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); continue; }
        bool cana = true, canb = true;
        {
            int ch = s[idif] - 'a';
            int l = a[idif] - 'a';
            int r = b[idif] - 'a';
            int to = where[ch];
            if(to == -1) {
                check(l, r);
                if(canbetw) {
                    where[ch] = ibetw;
                    busy[ibetw] = true;
                    add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); continue;
                }
                cana &= candown;
                canb &= canup;
            } else {
                if(to < l || r < to) { writeWord("NO\n"); continue; }
                if(l < to && to < r) {
                    add(); writeWord("YES\n"); for(int i = 0; i < k; i++) writeChar(char('a' + where[i])); writeChar('\n'); continue;
                }
                if(l == to) canb = false;
                else if(r == to) cana = false;
                else throw 1;
            }
        }

        for(int i = 0; i < k; i++) {
            where1[i] = where[i];
            busy1[i] = busy[i];
        }
        where[s[idif] - 'a'] = a[idif] - 'a';
        busy[a[idif] - 'a'] = true;
        if(cana && trya(idif + 1)) continue;
        for(int i = 0; i < k; i++) {
            where[i] = where1[i];
            busy[i] = busy1[i];
        }
        where[s[idif] - 'a'] = b[idif] - 'a';
        busy[b[idif] - 'a'] = true;
        if(canb && tryb(idif + 1)) continue;
        writeWord("NO\n");
    }
}