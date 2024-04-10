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

template <class T1, class T2> void cmin(T1 &a, T2 b) {a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b) {a = a > b ? a : b;}

const int N = 2e5 + 5;
int n, cnt, ans, a[N], mark[N];
int pre[N], suf[N], d[N];
pii p[N];
set <pii> s;
int main() {
	cin >> n, mem(pre, 0x3f, N);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), cmin(pre[a[i]], i), cmax(suf[a[i]], i);
	for(int i = 1; i <= n; i++) if(pre[i] < suf[i]) p[++cnt] = {pre[i], suf[i]}, d[pre[i] + 1]++, d[suf[i]]--;
	sort(p + 1, p + cnt + 1);
	for(int i = 1, res = 0, r = 0; i <= cnt; i++) {
		if(p[i].se > r) r = p[i].se, p[++res] = p[i];
		if(i == cnt) cnt = res;
	} for(int i = 1; i <= cnt; i++) mark[p[i].fi] = mark[p[i].se] = 1, s.insert(p[i]);
	while(s.size()) {
		pii t = *s.begin();
		int l = t.fi, r = t.se;
		pii it = *--s.lower_bound({r, 0});
		if(it == t) {s.erase(s.begin()); continue;}
		s.erase(s.begin());
		while(*s.begin() != it) s.erase(s.begin()), ans += 2;
		ans++;
	}
 	for(int i = 1; i <= n; i++) ans += (d[i] += d[i - 1]) > 0 && !mark[i];
 	cout << ans << endl;
	return 0;
}

/*
6
1 2 1 3 2 3

6
1 2 3 1 2 3
*/