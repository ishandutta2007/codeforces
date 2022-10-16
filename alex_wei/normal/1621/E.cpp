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

const int N = 1e5 + 5;
const ld eps = 1e-8;

int n, m, a[N], tor[N], tol[N], pre[N], suf[N];
ld val[N];
vint buc[N];

void solve() {
	cin >> n >> m, pre[0] = suf[m + 1] = tol[1] = 1, tor[m] = m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1), reverse(a + 1, a + n + 1);
	for(int i = 1; i <= m; i++) {
		int k = read(), p; buc[i].clear(); ld sum = 0;
		for(int j = 1; j <= k; j++) sum += p = read(), buc[i].pb(p);
		val[i] = sum / k;
	} sort(val + 1, val + m + 1), reverse(val + 1, val + m + 1);
	for(int i = 2; i <= m; i++) tol[i] = a[i] + eps >= val[i - 1] ? tol[i - 1] : i + 1;
	for(int i = m - 1; i; i--) tor[i] = a[i] + eps >= val[i + 1] ? tor[i + 1] : i - 1; 
	for(int i = 1; i <= m; i++) pre[i] = pre[i - 1] && a[i] + eps >= val[i];
	for(int i = m; i; i--) suf[i] = suf[i + 1] && a[i] + eps >= val[i];
	for(int i = 1; i <= m; i++) {
		ld sum = 0; for(int it : buc[i]) sum += it;
		for(int it : buc[i]) {
			ld origin = sum / buc[i].size(), after = (sum - it) / (buc[i].size() - 1);
			int lp = lower_bound(val + 1, val + m + 1, origin, greater <ld> ()) - val;
			int np = lower_bound(val + 1, val + m + 1, after, greater <ld> ()) - val;
			np -= np > lp;
			if(a[np] + eps <= after) {cout << '0'; continue;}
			cout << (pre[min(lp, np) - 1] && suf[max(lp, np) + 1] && (np <= lp ? tol[lp] <= np + 1 : tor[np] >= lp - 1));
		}
	} cout << endl;
	
}
bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int T; cin >> T; while(T--) solve();
	return flush(), 0;
}