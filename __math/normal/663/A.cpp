#include <bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i = 0 ;i < (n); i++) 
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;

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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ax+by=gcd(a,b)x,y(|x| <= b , |y| <= a)
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
// aygcd(a,m)(mod m) ---> return y; //mod_pow
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

int main() {
	vector<string> vs;
	string s;
	while (cin >> s) {
		vs.push_back(s);
	}
	vector<int> op;
	FOR(i, sz(vs) / 2) {
		if (vs[i * 2 + 1] == "-") op.push_back(-1);
		else if (vs[i * 2 + 1] == "+") op.push_back(1);
		else break;
	}

	int last = stoi(vs.back());
	if (sz(op) == 0) {
		printf("Possible\n%d = %d\n", last, last);
	} else {
		int pl = 0;
		for (auto x : op) if (x == 1) pl++;
		int mns = sz(op) - pl;
		pl++;

		int plmx = last * pl, plmn = pl;
		int mnmx = last * mns + last, mnmn = mns + last;
		if (mnmx < plmn || plmx < mnmn) {
			puts("Impossible");
		} else {
			vector<int> a1, a2;
			int use = 0;
			if (plmn <= mnmn && mnmn <= plmx) use = mnmn;
			if (plmn <= mnmx && mnmx <= plmx) use = mnmx;
			if (mnmn <= plmn && plmn <= mnmx) use = plmn;
			if (mnmn <= plmx && plmx <= mnmx) use = plmx;

			FOR(i, pl) a1.push_back(1);
			int plu = use - pl;
			FOR(i, pl) {
				int add = min(plu, last - 1);
				plu -= add;
				a1[i] += add;
			}
			FOR(i, mns) a2.push_back(1);
			int mnu = use - mns - last;
			FOR(i, mns) {
				int add = min(mnu, last - 1);
				mnu -= add;
				a2[i] += add;
			}

			puts("Possible");
			printf("%d ", a1.back()); a1.pop_back();
			FOR(i, sz(op)) {
				printf("%c ", op[i] == 1 ? '+' : '-');
				int us = (op[i] == 1) ? a1.back() : a2.back();
				if (op[i] == 1) a1.pop_back();
				else a2.pop_back();
				printf("%d ",us);
			}
			printf("= %d\n",last);
		}
	}

	return 0;
}