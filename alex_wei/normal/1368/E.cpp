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
		return x = sgn ? -x : x;
	}
	template <typename T>
	inline void recprint(T x) {if(x >= 10) recprint(x / 10); pc(x % 10 + '0');}
	template <typename T>
	inline void print(T x) {if(x < 0) pc('-'), x = -x; recprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 4e5 + 5;
int n, m, d[N], cnt, deg[N], hd[N], nxt[N], to[N];
void add(int u, int v) {nxt[++cnt] = hd[u], hd[u] = cnt, to[cnt] = v;}
void solve() {
	cin >> n >> m, cnt = 0, mem(hd, 0, n + 2), mem(d, 0, n + 2);
	for(int i = 1, x, y; i <= m; i++) cin >> x >> y, add(x, y), deg[y]++;
	queue <int> q; vint ans;
	for(int i = 1; i <= n; i++) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int t = q.front(); q.pop();
		if(d[t] == 2) ans.pb(t);
		for(int i = hd[t]; i; i = nxt[i]) {
			int it = to[i];
			if(d[t] < 2) cmax(d[it], d[t] + 1);
			if(!--deg[it]) q.push(it);
		}
	}
	cout << ans.size() << "\n";
	for(int it : ans) cout << it << " "; cout << "\n";
}

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int T; cin >> T; while(T--) solve();
	return cerr << "Time : " << clock() << endl, flush(), 0;
} ////////