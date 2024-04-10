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
// 	#define gc getchar()
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

const int N = 2e5 + 5;
int n, buc[N], a[N];
void solve() {
	vint ans;
	cin >> n, mem(buc, 0, N);
	for(int i = 1; i <= n; i++) cin >> a[i], buc[a[i]]++;
	int mex = 0; while(buc[mex]) mex++;
	for(int i = 1, cur = 0; i <= n; i++, cur = 0) {
		map <int, bool> mp;
		for(int j = i; j <= n; j++) {
			mp[a[j]] = 1;
			while(mp.find(cur) != mp.end()) cur++;
			if(cur == mex) {
				for(int p = i; p <= j; p++) {
					buc[a[p]]--;
					if(!buc[a[p]]) cmin(mex, a[p]);
				} ans.pb(cur), i = j;
				break;
			}
		}
	} cout << ans.size() << endl;
	for(int it : ans) cout << it << " "; cout << endl;
}

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int T; cin >> T;
	while(T--) solve();
	return flush(), 0;
} ////