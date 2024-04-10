#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

#pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r){ l = max(l, r); }
template<class T> void chmin(T& l, const T r){ l = min(l, r); }

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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T extgcd(T a, T b, T& x, T& y){ for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m){ T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
template<class T> T CRT(T r1, T m1, T r2, T m2) { T a1, a2; extgcd(m1, m2, a1, a2); T ret = (m1*a1*r2 + m2*a2*r1) % (m1*m2); return ret < 0 ? ret + m1 * m2 : ret; }

vector<string> split(string str, string delim){
	vector<string> res;
	size_t current = 0, found, delimlen = delim.size();
	while ((found = str.find(delim, current)) != string::npos) {
		res.push_back(string(str, current, found - current));
		current = found + delimlen;
	}
	res.push_back(string(str, current, str.size() - current));
	res.erase(remove(res.begin(), res.end(), ""), res.end());

	return res;
}

ll expr(char *& s);

ll val(char *& s){
	if (*s == '(') {
		s++;
		ll ret = expr(s);
		s++;
		return ret;
	}

	ll v = 0;
	while (*s >= '0' && *s <= '9') {
		v *= 10;
		v += *s - '0';
		s++;
	}
	return v;
}

ll pri(char *& s){
	ll l = val(s);
	while (true) {
		char ope = *s;
		if (ope != '*' && ope != '/')
			return l;
		s++;
		ll r = val(s);
		if (ope == '*')
			l *= r;
		else
			l /= r;
	}
}

ll expr(char *& s){
	ll l = pri(s);
	while (true) {
		char ope = *s;
		if (ope != '+' && ope != '-')
			return l;
		s++;
		ll r = pri(s);
		if (ope == '+')
			l += r;
		else
			l -= r;
	}
}

int main(){
	string s; cin >> s;
	auto sp =split(s, "*");

	vector<int> vals;
	vector<int> ops;
	FOR(a,sz(sp)) {
		if (a != 0) ops.push_back(1);
		auto& x = sp[a];
		if (sz(x) == 1) {
			vals.push_back(x[0] - '0');
		} else if (sz(x) == 3) {
			vals.push_back(x[0] - '0');
			ops.push_back(0); // +
			vals.push_back(x[2] - '0');
		} else {
			vals.push_back(x[0] - '0');
			ops.push_back(0); // +
			int y = 0;
			for (int i = 2; i < sz(x) - 1; i += 2) {
				y += x[i] - '0';
			}
			vals.push_back(y);
			ops.push_back(0); // +
			vals.push_back(x.back() - '0');
		}
	}

	char* _s = (char*)s.c_str();
	ll ans = expr(_s);
	FOR(i, sz(vals)){
		for (int j = i + 1; j <= sz(vals); j++) {
			string nw;
			FOR(k, sz(vals) + 1){
				if (j == k) nw.push_back(')');
				if (k != 0 && k < sz(vals)) {
					nw.push_back("+*"[ops[k-1]]);
				}
				if (i == k) nw.push_back('(');
				if (k < sz(vals)) {
					char buf[100];
					sprintf(buf,"%d",vals[k]);
					nw.append(buf);
				}
			}
			char* p = (char*)nw.c_str();
			ll tmp = expr(p);
			// cout << nw << " : " << tmp << endl;
			ans = max(ans, tmp);
		}
	}


	cout << ans << endl;

}