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
	} return s;
}


/*
int val[N << 2]
void build(int l, int r, int x) {
	if(l == r) return val[x] = pre[l], void();
	int m = l + r >> 1;
	build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
}
int query(int l, int r, int ql, int qr, int x) {
	if(ql <= l && r <= qr) return val[x];
	int m = l + r >> 1;	
}
like a sb
*/

const int K = 20;
const int N = 2e5 + 5;

int n, m, a[N], d[N];
int stmin[K][N], stmax[K][N], lg[N];
int qmin(int l, int r) {
	if(l > r) return N;
	int d = lg[r - l + 1];
	return min(stmin[d][l], stmin[d][r - (1 << d) + 1]);
}
int qmax(int l, int r) {
	if(l > r) return -N;
	int d = lg[r - l + 1];
//	cerr << "qmax " << l << " " << r << " " << d << endl;
	return max(stmax[d][l], stmax[d][r - (1 << d) + 1]);
}
struct segment {
	int l, r;
	bool operator < (const segment &v) const {return l != v.l ? l < v.l : r > v.r;}
} s[N];
vector<int> buc[N];
bool ban(int u, int v) {
	int l = 0, r = m;
	while(l < r) {
		int m = l + r + 2 >> 1;
		if(s[m].l <= u) l = m;
		else r = m - 1;
	}
	if(l == 0 || s[l].r < v) return 0;
	return 1;
}
bool check(int len) {
	for(int l = 1, r = len; r <= n; l++, r++) {
		if(qmax(1, l - 1) > 0) continue;
		if(qmin(r + 1, n) < l) continue;
		if(qmax(r + 1, n) > r) continue;
//		cerr << "see " << len << " " << l << " " << r << " " << qmax(1, l - 1) << " " << qmin(r + 1, n) << endl;
		return 1;
	}
	return 0;
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) a[i] = d[i] = read(), buc[i].clear();
	sort(d + 1, d + n + 1);
	for(int i = 1; i <= n; i++) a[i] = lower_bound(d + 1, d + n + 1, a[i]) - d;
	for(int i = 1; i <= n; i++) buc[a[i]].push_back(i);
	for(int i = 1; i <= m; i++) s[i].l = read(), s[i].r = read();
	sort(s + 1, s + m + 1);
	for(int i = 1, cnt = 0, r = 0; i <= m; i++) {
		if(s[i].r > r) r = s[i].r, s[++cnt] = s[i];
		if(i == m) m = cnt;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < buc[i].size(); j++) {
			int p = buc[i][j];
			if(j == 0 || !ban(buc[i][j - 1], p)) {stmin[0][p] = N, stmax[0][p] = -N; continue;}
			stmax[0][p] = buc[i][j - 1];
			int l = 0, r = j - 1;
			while(l < r) {
				int m = l + r >> 1;
				if(ban(buc[i][m], p)) r = m;
				else l = m + 1;
			}
			stmin[0][p] = buc[i][l];
		}
	}
//	for(int i = 1; i <= n; i++) cout << "chk " << i << " " << stmin[0][i] << " " << stmax[0][i] << endl;
	for(int i = 1; i < K; i++)
		for(int j = 1; j + (1 << i) - 1 <= n; j++) {
			stmin[i][j] = min(stmin[i - 1][j], stmin[i - 1][j + (1 << i - 1)]);
			stmax[i][j] = max(stmax[i - 1][j], stmax[i - 1][j + (1 << i - 1)]);
		}
	int l = 0, r = n;
	while(l < r) {
		int m = l + r >> 1;
		if(check(m)) r = m;
		else l = m + 1;
	}
	cout << l << endl;
}

int main() {
	for(int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
	int T = 1;
	cin >> T;
	while(T--) solve();
	return 0;
}