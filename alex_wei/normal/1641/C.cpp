#pragma GCC optimize(3)

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

const int N = 2e5 + 5;
int n, q, l[N], r[N], num[N << 2];
map <int, bool> ill;
set <int> s;
vector <int> val[N << 2];
bool check(int p) {
	auto pre = s.lower_bound(l[p]);
	auto suf = --s.upper_bound(r[p]);
	if(pre == suf) return ill[*pre] = 1;
	return 0;
}
void modify(int l, int r, int ql, int qr, int x, int v) {
	if(ql <= l && r <= qr) return val[x].push_back(v), void();
	int m = l + r >> 1;
	if(ql <= m) modify(l, m, ql, qr, x << 1, v);
	if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
}
void erase(int l, int r, int p, int x) {
	num[x]++;
	if(num[x] + 1 >= r - l + 1) for(auto it : val[x]) check(it);
	if(l == r) return;
	int m = l + r >> 1;
	if(p <= m) erase(l, m, p, x << 1);
	else erase(m + 1, r, p, x << 1 | 1);
}
int main() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) s.insert(i);
	for(int i = 1; i <= q; i++) {
		int t = read();
		if(t == 0) {
			int _l = read(), _r = read(), x = read();
			if(x == 0) {
				while(1) {
					auto it = s.lower_bound(_l);
					if(it == s.end() || *it > _r) break;
					int p = *it;
					s.erase(it), erase(1, n, p, 1);
				}
			} else {
				l[i] = _l, r[i] = _r;
				if(!check(i)) modify(1, n, _l, _r, 1, i);
			}
		} else {
			int p = read();
			if(s.find(p) == s.end()) puts("NO");
			else if(ill.find(p) != ill.end()) puts("YES");
			else puts("N/A");
		}
	}
	return 0;
}