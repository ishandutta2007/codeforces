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

const int N = 1e5 + 5;

int n, buc[N];
string s[N];
void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) if(s[i][0] == s[i][s[i].size() - 1]) return puts("YES"), void();
	mem(buc, 0, N);
	for(int i = 1; i <= n; i++) {
		int x = s[i][0] - 'a' + 1, y = s[i][1] - 'a' + 1;
		if(s[i].size() == 2 && buc[y * 27 + x]) return puts("YES"), void();
		buc[x * 27 + y] = 1;
	} mem(buc, 0, N);
	for(int i = n; i; i--) {
		int x = s[i][s[i].size() - 2] - 'a' + 1, y = s[i][s[i].size() - 1] - 'a' + 1;
		if(s[i].size() == 2 && buc[y * 27 + x]) return puts("YES"), void();
		buc[x * 27 + y] = 1;
	} mem(buc, 0, N);
	for(int i = 1; i <= n; i++) if(s[i].size() == 3) {
		int x = s[i][0] - 'a' + 1, y = s[i][1] - 'a' + 1, z = s[i][2] - 'a' + 1;
		if(buc[z * 27 * 27 + y * 27 + x]) return puts("YES"), void();
		buc[x * 27 * 27 + y * 27 + z] = 1;
	} puts("NO");
}

bool Med;
int main() {
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int T; cin >> T;
	while(T--) solve();
	return flush(), 0;
} ////