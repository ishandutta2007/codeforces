
//#pragma GCC optimize(3)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

#define pii pair <int, int>
#define pll pair <ll, ll>
#define fi first
#define se second
#define pb emplace_back
#define all(x) begin(x), end(x)
#define rev(x) reverse(all(x))
#define sor(x) sort(all(x))
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))
#define FileI(x) freopen(x, "r", stdin)
#define FileO(x) freopen(x, "w", stdout)
#define y1 y_chenxiaoyan_1

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
 	#define gc getchar()
//	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
		ll x = 0; bool sgn = 0; char s = gc;
		while(!isdigit(s)) sgn |= s == '-', s = gc;
		while(isdigit(s)) x = x * 10 + s - '0', s = gc;
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

int n;
multiset <int> s;
vpii solve(int n) {
	if(n <= 2) return vpii();
	if((n & -n) == n) return solve(n - 1);
	int lg = log2(n), p = 1 << lg;
	vpii ret, x, y;
	for(int i = n; i > p; i--) ret.pb(i, p * 2 - i);
	x = solve(p * 2 - n - 1), y = solve(n - p);
	for(pii it : x) ret.pb(it);
	for(pii it : y) ret.pb(it.fi << 1, it.se << 1);
	return ret;
}
bool Med;
int main() {
	int T = read();
	while(T--) {
		cin >> n, s.clear();
		if(n == 2) {puts("-1"); continue;}
		for(int i = 1; i <= n; i++) s.insert(i);
		vpii op = solve(n);
		for(pii it : op) {
			s.erase(s.find(it.fi)), s.erase(s.find(it.se));
			s.insert(it.fi + it.se), s.insert(it.fi - it.se);
		}
		for(int it : s)
			if(s.count(it) > 1) {
				s.erase(s.find(it)), s.erase(s.find(it));
				s.insert(it << 1), op.pb(it, it);
				break;
			}
		while(1) {
			int it = *s.begin();
			if(it == *--s.end()) break;
			op.pb(it, 0), op.pb(it, it), s.erase(s.find(it)), s.insert(it << 1);
		} op.pb(*--s.end(), 0), cout << op.size() << endl;
		for(pii it : op) cout << it.fi << " " << it.se << "\n";
	}
	return flush(), 0;
}