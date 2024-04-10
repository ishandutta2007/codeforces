#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define i128 __int128
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>
#define pll pair <ll, ll>
#define pii pair <int, int>

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

bool Mbe;
namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
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

const int N = 5e5 + 5;
const int mod = 998244353;
void add(int &x, int y) {x += y; x >= mod && (x -= mod);}
int n, a[N], f[N], g[N], c[N], d[N];
void solve() {
	cin >> n, mem(f, 0, n + 2), mem(c, 0, n + 2), mem(d, 0, n + 2);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		add(f[a[i]], g[i] = (f[a[i]] + (a[i] ? f[a[i] - 1] : 1)) % mod);
	int ans = 0;
	for(int i = n; i; i--) {
		add(c[a[i]], (c[a[i]] + (a[i] >= 2 ? d[a[i] - 2] : 0) + 1) % mod);
		add(d[a[i]], (d[a[i]] + c[a[i] + 2] + 1) % mod);
		add(ans, 1ll * g[i] * (c[a[i] + 2] + 1) % mod);
	} cout << (ans + c[1]) % mod << endl;
}
bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int T; cin >> T; while(T--) solve();
	return cerr << "Time : " << clock() << endl, flush(), 0;
}