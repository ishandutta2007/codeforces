#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <numeric>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

const ll MOD = ten(9) + 9;
const ll M = ten(8) + 7;

struct X {
	ll hash;
	int len;
	X() : hash(0), len(0) {}
	X(ll hash, int len) : hash(hash), len(len) {
		this->hash %= MOD;
		if (this->hash < 0) this->hash += MOD;
	}
	bool operator==(const X& r){
		return hash == r.hash && len == r.len;
	}
};

ll Mtbl[2 * ten(5) + 10];

class H {
	ll h[2 * ten(5) + 10], rh[2 * ten(5) * 10];
	string s;
public:
	 void init (string& _s) {
		s = _s;
		const int n = sz(s);
		h[0] = rh[0] = 0;
		FOR(i, n) h[i + 1] = (h[i] * M + s[i]) % MOD;
		reverse(s.begin(), s.end());
		FOR(i, n) rh[i + 1] = (rh[i] * M + s[i]) % MOD;
		reverse(s.begin(), s.end());

		Mtbl[0] = 1;
		FOR(i, n) Mtbl[i + 1] = (Mtbl[i] * M) % MOD;
	}

	//[l,r)
	X substr(int l, int r){
		return X(h[r] - h[l] * Mtbl[r - l], r - l);
	}
};

X make(H& hash,int l, int r){
	X x = hash.substr(l, r);
	if (x.len % 2 == 1) return x;
	else {
		X a = make(hash,l, (l + r) / 2);
		X b = make(hash,(l + r) / 2, r);
		if (a.hash < b.hash) swap(a, b);
		return X(a.hash + b.hash * Mtbl[a.len] % MOD, r - l);
	}
}

H hs, ht;

int main(){
	string s, t; cin >> s >> t;
	hs.init(s);
	ht.init(t);

	auto a = make(hs, 0, sz(s));
	auto b = make(ht, 0, sz(s));

	if (a == b) {
		puts("YES");
	} else {
		puts("NO");
	}

	return 0;
}