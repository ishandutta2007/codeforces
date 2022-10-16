#pragma GCC optimize("Ofast")

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

const int N = 1e5 + 5;
int n, a[N], buc[N << 1], ans;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n <= 2) puts("0"), exit(0);
	gp_hash_table <long long, int> mp;
	for(int d = -100; d <= 100; d++) {
		mp.clear();
		for(int i = 1; i <= n; i++) cmax(ans, ++mp[a[i] - i * d]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= min(n, i + 1500); j++) {
			int d = a[j] - a[i];
			if(d % (j - i)) continue;
			cmax(ans, ++buc[d / (j - i) + N] + 1);
		}
		for(int j = i + 1; j <= min(n, i + 1500); j++) {
			int d = a[j] - a[i];
			if(d % (j - i)) continue;
			buc[d / (j - i) + N] = 0;
		}
	}
	cout << n - ans << endl;
	return 0;
}