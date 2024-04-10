
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

const int N = 2e5 + 5;
ll n, a[N], s[N];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	ll sum = 0;
	for(int i = 1; i < n; i++) sum += a[i] + a[n];
	if(sum < 0) return puts("INF"), void();
	sum = 0;
	for(int i = 2; i <= n; i++) sum += a[1] + a[i];
	if(sum > 0) return puts("INF"), void();
	ll ans = -1e18;
	if(n == 2) return cout << a[1] * a[2] << endl, void();
	for(int i = 2; i < n; i++) {
		ll cur = a[1] * (s[n - 1] - s[i - 1]) + a[n] * s[i - 1];
		ans = max(ans, cur + (-a[i]) * (a[1] * (n - i) + a[n] * (i - 1) + s[n - 1]));
	}
	ans = max(ans, a[1] * (s[n] - s[1]) + (-a[1]) * (s[n] - s[1] + a[1] * (n - 1)));
	ans = max(ans, a[n] * s[n - 1] + (-a[n]) * (s[n - 1] + a[n] * (n - 1)));
	cout << ans << endl;
}
int main() {
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}