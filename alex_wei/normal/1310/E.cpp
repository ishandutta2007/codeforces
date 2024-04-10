#include <bits/stdc++.h> ///////
using namespace std;

#define int long long
#define db double
#define ll long long
#define ld long double
#define uint unsigned int
#define ull unsigned long long
#define vint vector <int>
#define vpii vector <pii>

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
	inline void rec_print(T x) {if(x >= 10) rec_print(x / 10); pc(x % 10 + '0');}
	template <typename T>
	inline void print(T x) {if(x < 0) pc('-'), x = -x; rec_print(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 3e3 + 5;
const int mod = 998244353;
void add(int &x, ll y) {x = (x + y) % mod;}
int n, k, f[N];

namespace K1 {
	void solve() {
		int ans = 0; f[0] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++) add(f[j], f[j - i]);
		for(int i = 1; i <= n; i++) add(ans, f[i]);
		cout << ans << endl, exit(0);
	}
}

namespace K2 {
	void solve() {
		int ans = 0; f[0] = 1;
		for(int i = 1; i * (i + 1) >> 1 <= n; i++)
			for(int j = i * (i + 1) >> 1; j <= n; j++)
				add(f[j], f[j - (i * (i + 1) >> 1)]);
		for(int i = 1; i <= n; i++) add(ans, f[i]);
		cout << ans << endl;
	}
}

namespace BF {
	int ans;
	vint cur;
	bool check() {
		vint tmp = cur, nw;
		for(int j = 1; j < k; j++, nw.clear()) {
			int sum = 0; sor(tmp), rev(tmp);
			for(int i = 0; i < tmp.size(); i++) sum += tmp[i] * (i + 1);
			if(sum > n) return 0;
			if(j + 3 < k && sum > 23) return 0;
			for(int i = 0; i < tmp.size(); i++)
				for(int j = 0; j < tmp[i]; j++) nw.pb(i + 1);
			tmp = nw;
		} return 1;
	}
	bool dfs(int lim) {
		if(!check()) return 0;
		ans++;
		for(int i = lim, res; ; i++) {
			cur.pb(i), res = dfs(i), cur.pop_back();
			if(!res) return 1;
		} return 1;
	}
	void solve() {dfs(1), cout << ans - 1 << endl;}
}

bool Med;
signed main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> k;
	if(k == 1) K1 :: solve();
	else if(k == 2) K2 :: solve();
	else BF :: solve(); 
	return cerr << "Time : " << clock() << endl, flush(), 0;
}