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

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
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

ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

const int M_SIZE = 101;
typedef int Mat[M_SIZE][M_SIZE];

void mul(Mat& c, const Mat& a, const Mat& b) {
	memset(c, 0, sizeof(Mat));

	FOR(i, M_SIZE) for (int k = i; k < M_SIZE; k++) for (int  j = k; j < M_SIZE; j++)
		c[i][j] = max(c[i][j],a[i][k] + b[k][j]);
}

Mat tbl[24];
void pow(int n, Mat& res) {
	memset(res, 0, sizeof(res));
	for (int i = 0; i < 24; i++) {
		if (n & (1LL << i)) {
			Mat buf; memcpy(buf, res, sizeof(Mat));
			mul(res, buf, tbl[i]);
		}
	}
}

void init_matTable(Mat& a) {
	Mat& mat = tbl[0];
	memcpy(mat, a, sizeof(Mat));

	FOR(i, 23) mul(tbl[i + 1], tbl[i], tbl[i]);
}

int a[100];

int dp[101];

void f(int from, int n) {
	memset(dp, 0, sizeof(dp));
	FOR(i, n) {
		if (a[i] < from) continue;
		int mx = 0;
		FOR(j, a[i] + 1) mx = max(mx, dp[j]);
		dp[a[i]] = mx + 1;
	}
	FOR(i,100) dp[i+1] = max(dp[i], dp[i + 1]);
}

int main() {
	int n, t; reader(n, t);
	FOR(i, n) reader(a[i]);
	vector<int> c;
	FOR(i, n) c.push_back(a[i]);
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	FOR(i, n) a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();

	Mat A; memset(A, 0, sizeof(A));
	FOR(i, sz(c)) {
		f(i, n);
		FOR(j, 101) A[i][j] = dp[j];
	}

	init_matTable(A);

	Mat ans;
	pow(t, ans);
	int out = ans[0][100];
	writerLn(out);
}