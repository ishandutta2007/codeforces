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

const int N = 500 + 5;
int n, a[N];
vector <int> len;
vector <pii> ans;
void flip(int p) {
//	cerr << "flip " << p << endl;
	for(int i = p; i <= n; i++) ans.push_back({i - 1, a[n - (i - p)]});
	len.push_back(n - p + 1 << 1);
	reverse(a + p, a + n + 1);
}
void solve() {
	cin >> n;
	len.clear(), ans.clear();
	for(int i = 1; i <= n; i++) cin >> a[i];
	map <int, bool> mp;
	for(int i = 1; i <= n; i++) mp[a[i]] ^= 1;
	for(auto it : mp) if(it.second) return puts("-1"), void();
	for(int i = 1; i <= n; i += 2) {
		if(a[i] != a[i + 1]) {
			int pos = -1;
			for(int j = i + 2; j <= n; j++) if(a[j] == a[i]) pos = j;
			flip(pos), flip(i + 1);
		}
	}
//	for(int i = 1; i <= n; i++) cout << a[i] << " ";
//	cout << endl;
	cout << ans.size() << endl;
	for(pii it : ans) cout << it.fi << " " << it.se << endl;
	cout << n / 2 + len.size() << endl;
	for(int i = 1; i <= n / 2; i++) cout << 2 << " ";
	rev(len);
	for(int it : len) cout << it << " ";
	cout << endl;
}
int main() {
	int T; cin >> T;
	while(T--) solve();
	return 0;
}