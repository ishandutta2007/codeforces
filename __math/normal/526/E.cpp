#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
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
#define tenll(x) ((ll)1e##x)

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<class T> ll mod_pow(T a, T n, T mod){
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}

int n;
int a[ten(6) * 3];

typedef pair<int, ll> P;

int solve(ll b){

	static int fst[ten(6)],end[ten(6)];
	static ll sm[ten(6)];

	int ret = 0;
	int u = 0;
	while (u < n) {
		fst[ret] = u;
		ll s = 0;
		while (u < n && s + a[u] <= b) s += a[u++];
		end[ret] = u;
		sm[ret] = s;
		ret++;
	}

	int x = end[0];
	int ret2 = 0;
	u = x;
	while (u < n + x) {
		ll s = 0;
		while (u < n + x && s + a[u] <= b) s += a[u++];
		ret2++;
	}
	if (ret2 < ret) return ret2;

	for (int f = 1; f < end[0]; f++) {
		bool all_checked = false;
		int pv = f - 1;
		fst[0]++;
		sm[0] -= a[pv];
		FOR(i, ret - 1) {
			pv = fst[i+1];
			while (sm[i] + a[pv] <= b) {
				sm[i] += a[pv];
				fst[i + 1]++;
				sm[i + 1]-= a[pv];
				pv++;
			}
		}
		if (fst[ret-1] >= f + n) return ret - 1;
		sm[ret-1] += a[f-1];
		if (sm[ret - 1] > b) return ret;

		FOR(i, ret-1){
			if (fst[i] >= end[i]) return ret;
		}
	}

	return ret;
}

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

void reader(int *x){ int k, m = 0; *x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { *x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; *x = (*x) * 10 + k - '0'; }if (m)(*x) = -(*x); }
void reader(ll *x){ int k, m = 0; *x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { *x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; *x = (*x) * 10 + k - '0'; }if (m)(*x) = -(*x); }
int reader(char c[]){ int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T *x, S *y){ reader(x); reader(y); }
template <class T, class S, class U> void reader(T *x, S *y, U *z){ reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T *x, S *y, U *z, V *w){ reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c){ int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c){ int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]){ int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c){ int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x){ writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y){ writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z){ writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n){ if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }


ll b[50];
int main(){
	int q; reader(&n, &q);
	FOR(i, n) reader(a + i);
	ll all = 0;
	FOR(i, n) a[i + 2 * n] = a[i + n] = a[i], all += a[i];
	FOR(i, q) reader(b + i);
	FOR(i, q){
		if (b[i] >= all) {
			puts("1");
			continue;
		}
		int ans = solve(b[i]);
		writerLn(ans);
	}
}