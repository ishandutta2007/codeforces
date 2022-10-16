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
int n, m, ok[N], ans[N];
ll r[N];
struct rain {
	int x, p, id;
	bool operator < (const rain &rhs) {
		return x < rhs.x;
	}
} c[N];
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> c[i].x >> c[i].p, c[i].id = i;
	sort(c + 1, c + n + 1);
	multiset<int> s;
	ll sum = 0;
	for(int i = 1; i <= n; i++) {
		s.insert(c[i].x + c[i].p);
		sum += c[i].x + c[i].p;
		while(*s.begin() < c[i].x) {
			sum -= *s.begin();
			s.erase(s.begin());
		}
		r[i] = sum - 1ll * c[i].x * s.size();
	}
	sum = 0, s.clear();
	for(int i = n; i; i--) {
		if(i < n) {
			s.insert(c[i + 1].x - c[i + 1].p);
			sum += c[i + 1].x - c[i + 1].p;
		}
		while(!s.empty() && *--s.end() > c[i].x) {
			sum -= *--s.end();
			s.erase(--s.end());
		}
		r[i] += 1ll * c[i].x * s.size() - sum;
//		cout << i << " " << c[i].x << " " << r[i] << "\n";
	}
	for(int i = 1; i <= n; i++) ok[i] = 1;
	s.clear();
	ll limit = -1e18;
	for(int i = 1; i <= n; i++) {
		if(r[i] > m) limit = max(limit, r[i] - m - c[i].x);
		if(c[i].p - c[i].x < limit) ok[i] = 0;
	}
	limit = -1e18;
	for(int i = n; i; i--) {
		if(r[i] > m) limit = max(limit, r[i] - m + c[i].x);
		if(c[i].p + c[i].x < limit) ok[i] = 0;
	}
	for(int i = 1; i <= n; i++) ans[c[i].id] = ok[i];
	for(int i = 1; i <= n; i++) cout << ans[i];
	cout << "\n";
}
int main() {
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}