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

const int N = 1e5 + 5;
int n, m, q, ans = 1e9, f[N][2]; // 0 -> R, 1 -> B
char l[N], r[N], t[N], b[N];
bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> m >> q >> l + 1 >> r + 1 >> t + 1 >> b + 1;
	for(int _ = 0; _ < 2; _++) {
		mem(f, 0x3f, N), f[0][0] = f[0][1] = 0;
		for(int i = 1; i <= n; i++) f[0][l[i] == 'R']++;
		for(int i = 1; i <= m; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++) {
					int cst = (j != k) * n; char ch = j ? 'B' : 'R';
					cmin(f[i][j], f[i - 1][k] + cst + (ch != t[i]) + (ch != b[i]));
				}
		for(int i = 1; i <= n; i++) f[m][r[i] == 'R']++;
		cmin(ans, min(f[m][0], f[m][1])), swap(l, t), swap(r, b), swap(n, m);
	} cout << ans << endl;
	return cerr << "Time : " << clock() << endl, flush(), 0;
} //////////////