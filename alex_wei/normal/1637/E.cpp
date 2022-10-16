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

const int N = 3e5 + 5;
int n, m, a[N];
vector <int> ap[N], e[N], have;
void solve() {
	cin >> n >> m, have.clear();
	ll ans = 0;
	map <int, int> mp;
	map <pii, bool> ban;
	for(int i = 1; i <= n; i++) a[i] = read(), mp[a[i]]++;
	for(int i = 1; i <= n; i++) e[i].clear(), ap[i].clear();
	for(int i = 1, x, y; i <= m; i++) x = read(), y = read(), ban[{x, y}] = ban[{y, x}] = 1;
	for(int i = 1; i <= n; i++) if(mp[a[i]]) ap[mp[a[i]]].push_back(a[i]), mp[a[i]] = 0;
	for(int i = 1; i <= n; i++) sor(ap[i]), rev(ap[i]);
	for(int i = 1; i <= n; i++) if(!ap[i].empty()) have.pb(i);
	sor(have);
	for(int i : have)
		for(int ei : ap[i])
			for(int j : have)
				if(i >= j)
					for(int ej : ap[j])
						if(ei != ej && ban.find({ei, ej}) == ban.end()) {
							ans = max(ans, 1ll * (i + j) * (ei + ej));
							break;
						}
	cout << ans << "\n";
}

bool Med;
int main() {
	int T = 1;
	cin >> T;
	while(T--) solve();
	return flush(), 0;
}