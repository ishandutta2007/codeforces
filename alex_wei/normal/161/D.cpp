#include <bits/stdc++.h> ////////////////////
using namespace std;

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
#define forcd(x) for(int it : e[id]) if(it != f && !vis[it])

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

const int N = 5e4 + 5;
const int K = 500 + 5;
uint n, k, ans, d[N][K];
vint e[N];
void dfs(int id, int f) {
	d[id][0] = 1;
	for(int it : e[id]) if(it != f) {
		dfs(it, id);
		for(int j = 0; j < k; j++)
			d[id][j + 1] += d[it][j];
	}
}
void dfs2(int id, int f) {
	ans += d[id][k];
	for(int it : e[id]) if(it != f) {
		for(int j = k - 1; ~j; j--) 
			d[it][j + 1] += d[id][j] - (j ? d[it][j - 1] : 0);
		dfs2(it, id);
	}
}

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> k;
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].pb(v), e[v].pb(u);
	dfs(1, 0), dfs2(1, 0), cout << (ans >> 1) << endl;
	return cerr << "Time : " << clock() << endl, flush(), 0;
}