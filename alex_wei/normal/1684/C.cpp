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
}
using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}

const int N = 2e5 + 5;
vector<int> a[N];
int n, m;
bool check(int p, int q) {
	for(int j = 1; j <= n; j++) swap(a[j][p], a[j][q]);
	bool ok = 1;
	for(int j = 1; j <= n; j++)
		for(int k = 2; k <= m; k++)
			if(a[j][k] < a[j][k - 1])
				ok = 0;
	for(int j = 1; j <= n; j++) swap(a[j][p], a[j][q]);
	return ok;
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) a[i].clear(), a[i].resize(m + 1);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
	for(int i = 1; i <= n; i++) {
		int u = -1, v = -1, w = -1;
		for(int j = 2; j <= m; j++) {
			if(a[i][j] < a[i][j - 1]) {
				u = j;
				break;
			}
		}
		if(u == -1) continue;
		for(int j = 1; j <= m; j++)
			if(a[i][j] == a[i][u - 1]) {
				v = j;
				break;
			}
		if(check(u, v)) return cout << u << " " << v << endl, void();
		for(int j = u + 1; j <= m; j++)
			if(a[i][j] < a[i][j - 1]) {
				w = j;
				break;
			}
		if(w == -1) {
			for(int j = m; j > u; j--)
				if(a[i][j] == a[i][u]) {
					w = j;
					break;
				}
			if(w != -1 && check(u - 1, w)) cout << u - 1 << " " << w << endl;
			else puts("-1");
			return;
		}
		if(check(u, w)) return cout << u << " " << w << endl, void();
		if(check(u, w - 1)) return cout << u << " " << w - 1 << endl, void();
		if(check(u - 1, w)) return cout << u - 1 << " " << w << endl, void();
		if(check(u - 1, w - 1)) return cout << u - 1 << " " << w - 1 << endl, void();
		puts("-1");
		return;
	}
	puts("1 1");
}

int main() {
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}