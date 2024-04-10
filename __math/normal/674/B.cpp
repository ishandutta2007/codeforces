#define _CRT_SECURE_NO_DEPRECATE
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }

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

void print(vector<int>& a, vector<int>& b) {
	for (auto& x : a) x++;
	for (auto& x : b) x++;
	writerArr(&a[0], sz(a));
	writerArr(&b[0], sz(b));
}

int main() {
	int n, k; reader(n, k);
	int a, b, c, d; reader(a, b, c, d);
	a--; b--; c--; d--;
	if ((a == c && b == d) || (a == d && b == c)) {
		vector<int> p1;
		p1.push_back(a);
		FOR(i, n) if (i != a && i != b) p1.push_back(i);
		p1.push_back(b);
		vector<int> p2 = p1;

		if (a != c) reverse(p2.begin(), p2.end());
		print(p1, p2);
		return 0;
	} else if (a == c || a == d || b == c || b == d) {
		if (k == n - 1) {
			puts("-1");
			return 0;
		}
		bool rev = b == c || b == d;
		if (rev) {
			swap(a, b); swap(c, d);
		}
		int op = c;
		if (a == c) op = d;

		vector<int> p1;
		p1.push_back(a);
		FOR(i, n) if (i != a && i != b && i != op) p1.push_back(i);
		p1.push_back(op);
		p1.push_back(b);

		vector<int> p2;
		p2.push_back(a);
		FOR(i, n) if (i != a && i != b && i != op) p2.push_back(i);
		p2.push_back(b);
		p2.push_back(op);

		if (a != c) reverse(p2.begin(), p2.end());
		if (rev) {
			swap(a, b);
			swap(c, d);
			reverse(p1.begin(), p1.end());
			reverse(p2.begin(), p2.end());
		}

		print(p1, p2);
		return 0;
	} else {
		if (n == 4 || k < n + 1) {
			puts("-1");
			return 0;
		}
		vector<int> p1;
		p1.push_back(a);
		p1.push_back(c);
		FOR(i, n) if (i != a && i != b && i != c && i != d) p1.push_back(i);
		p1.push_back(d);
		p1.push_back(b);

		vector<int> p2;
		p2.push_back(c);
		p2.push_back(a);
		FOR(i, n) if (i != a && i != b && i != c && i != d) p2.push_back(i);
		p2.push_back(b);
		p2.push_back(d);

		print(p1, p2);
		return 0;
	}
}