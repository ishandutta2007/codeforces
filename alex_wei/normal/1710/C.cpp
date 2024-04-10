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
	}
	return s;
}

constexpr int N = 2e5 + 5;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int n, f[N][8][8];
char s[N];
int main() {
	cin >> s + 1;
	n = strlen(s + 1);
	f[0][7][0] = 1;
	for(int i = 0; i < n; i++)
		for(int up = 0; up < 8; up++)
			for(int exi = 0; exi < 8; exi++)
				for(int msk = 0; msk < 8; msk++) {
					int lim = 0, nexi = exi;
					for(int p = 0; p < 3; p++)
						if(up >> p & 1) {
							if(s[i + 1] == '0' && (msk >> p & 1)) {
								lim = -1;
								break;
							}
							if(s[i + 1] - '0' == (msk >> p & 1)) lim |= 1 << p;
						}
					if(lim == -1) continue;
					if(msk == 1 || msk == 6) nexi |= 1;
					if(msk == 2 || msk == 5) nexi |= 2;
					if(msk == 3 || msk == 4) nexi |= 4;
					add(f[i + 1][lim][nexi], f[i][up][exi]);
				}
	int ans = 0;
	for(int i = 0; i < 8; i++) add(ans, f[n][i][7]);
	cout << ans << endl;
	return 0;
}