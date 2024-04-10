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
 
const int N = 1e5 + 5, B = 1e3;
int n, m, cnt, ind, ans = 2e9 + 7;
int d[N * 5], mp[N];
bitset <N> f[B];
struct node {
	int a[5], w;
	bool operator < (const node &v) const {return w < v.w;}
} a[N];
vector <int> buc[N * 5];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++)
			d[++cnt] = a[i].a[j] = read();
		sort(a[i].a, a[i].a + m), a[i].w = read();
	}
	sort(a + 1, a + n + 1);
	sort(d + 1, d + cnt + 1);
	cnt = unique(d + 1, d + cnt + 1) - d - 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < m; j++)
			a[i].a[j] = lower_bound(d + 1, d + cnt + 1, a[i].a[j]) - d,
			buc[a[i].a[j]].push_back(i);
	for(int i = 1; i <= cnt; i++)
		if(buc[i].size() > B) {
			mp[i] = ++ind;
			for(int it : buc[i]) f[ind][it] = 1;
		}
	for(int i = 1; i <= n; i++) {
		static bitset <N> g; g.reset();
		for(int j = 0; j < m; j++)
			if(buc[a[i].a[j]].size() > B) g |= f[mp[a[i].a[j]]];
			else for(int it : buc[a[i].a[j]]) g[it] = 1;
		g.flip();
		int pos = g._Find_next(0);
		if(pos <= n) ans = min(ans, a[i].w + a[pos].w);
	}
	cout << (ans > 2e9 ? -1 : ans) << endl;
	return 0;
}