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

// #pragma comment(linker,"/STACK:36777216")


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

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

bool f(int a, int b, int c, vector<int> v, int md) {
	int ci = 0;
	while (ci < sz(v) && v[ci] <= c) ci++;
	ci--;
	vector<int> rem;
	int r = md;
	for (int j = sz(v) - 1; j >= 0; j--) {
		if (v[j] <= c && r) {
			r--;
			continue;
		}
		rem.push_back(v[j]);
	}
	reverse(rem.begin(), rem.end());
	v.swap(rem);

	int cnt[3] = {};
	for (int j = sz(v) - 1; j >= 0; j--) {
		if (v[j] > a + b) return false;
		if (v[j] > b) {
			cnt[2]++;
		} else if (v[j] > a) {
			cnt[1]++;
		} else {
			cnt[0]++;
		}
	}
	if (cnt[2] > md) return false;
	md -= cnt[2];
	if (cnt[1] > md) return false;
	if (cnt[0] + cnt[1] > md * 2) return false;
	return true;
}

int main() {
	int n, a, b, c; reader(n, a, b, c);
	static int t[ten(5) * 2];
	FOR(i, n) reader(t[i]);

	FOR(i, n) if (a + b + c < t[i]) {
		puts("-1");
		return 0;
	}

	int ans = 0;
	vector<int> rem;
	{
		int mx = max(a + b, b + c);
		mx = max(mx, c + a);
		FOR(i, n) {
			if (t[i] > mx) ans++;
			else rem.push_back(t[i]);
		}
	}
	vector<int> p = { a, b, c };
	sort(p.begin(), p.end());
	a = p[0], b = p[1], c = p[2];
	sort(rem.begin(), rem.end());

	//b+c
	{
		vector<int> tmp;
		int l = 0, i;
		for (i = sz(rem) - 1; i >= 0; i--) {
			if (rem[i] <= a + c) {
				break;
			} else {
				ans++;
				if (l < i && rem[l] <= a) l++;
			}
		}
		for (int j = l; j <= i; j++) tmp.push_back(rem[j]);
		rem = move(tmp);
	}

	//a+c
	{
		vector<int> tmp;
		int li = 0, i;
		while (li < sz(rem) && rem[li] <= b) li++;
		int l = li - 1;
		int pv = max(a + b, c);
		for (i = sz(rem) - 1; i >= 0; i--) {
			if (rem[i] <= pv) {
				break;
			} else {
				ans++;
				if (l >= 0) l--;
			}
		}
		for (int j = 0; j <= l; j++) tmp.push_back(rem[j]);
		for (int j = li; j <= i; j++) tmp.push_back(rem[j]);
		rem = move(tmp);
	}

	int l = 0, r = sz(rem);
	while (r - l != 1) {
		int md = (r + l) / 2;
		bool bl = f(a, b, c, rem, md);
		if (bl) r = md;
		else l = md;
	}
	writerLn(ans + r);

}