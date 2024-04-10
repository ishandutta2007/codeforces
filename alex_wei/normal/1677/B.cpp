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

const int mod = 998244353;
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	} return s;
}
const int N = 1e6 + 5;
char s[N];
int n, m, ans[N];
void solve() {
	cin >> n >> m;
	for(int i = 0; i < n * m; i++) ans[i] = 0;
	vector <vector <int>> buc(n + 1, vector <int> (m + 1, 0));
	scanf("%s", s);
	for(int i = 0, p = 0, sm = 0; i < n * m; i++) {
		sm += s[i] == '1';
		if(p == i - m) sm -= s[p++] == '1';
		if(sm) {
			int x = i / m, y = i % m;
			buc[x][y]++, buc[x][y + 1]--;
		}
	}
	for(int j = 0; j < m; j++)
		for(int i = 0, sm = 0; i < n; i++) {
			sm |= s[i * m + j] == '1';
			if(sm) ans[i * m + j]++, ans[min(n * m, i * m + j + m)]--;
		}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			if(i) buc[i][j] += buc[i - 1][j];
			if(j) buc[i][j] += buc[i][j - 1];
			if(i && j) buc[i][j] -= buc[i - 1][j - 1];
		}
	for(int i = 0; i < n * m; i++) {
		if(i) ans[i] += ans[i - 1];
		print(ans[i] + buc[i / m][i % m]), pc(' ');
	}
	pc('\n');
}
int main() {
	int T = 1;
	cin >> T;
	while(T--) solve();
	return flush(), 0;
}