#include <bits/stdc++.h>
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

namespace IO {
	char buf[1 << 21], *p1 = buf, *p2 = buf, Obuf[1 << 24], *O = Obuf;
	#define gc (p1 == p2 && (p2 = (p1 = buf) + \
		fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
	#define pc(x) (*O++ = x)
	#define flush() fwrite(Obuf, 1, O - Obuf, stdout)
	inline ll read() {
	    ll x = 0, sgn = 0; char s = gc;
	    while(!isdigit(s)) sgn |= s == '-', s = gc;
	    while(isdigit(s)) x = x * 10 + s - '0', s = gc;
	    return sgn ? -x : x;
	}
	inline void rec_print(ll x) {if(x >= 10) rec_print(x / 10); pc(x % 10 + '0');}
	inline void print(ll x) {if(x < 0) pc('-'), x = -x; rec_print(x);}
} using namespace IO;

template <class T> void cmin(T &a, T b){a = a < b ? a : b;}
template <class T> void cmax(T &a, T b){a = a > b ? a : b;}
bool Mbe;

const int N = 500 + 5;
int n, m, ans, a[N][N], p[N][N];
char mp[N][N];

bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> mp[i][j], p[i][j] = mp[i][j] == 'B';
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans += a[i][j] = 
				(p[i][j] ^ p[i][j + 1] ^ p[i + 1][j] ^ p[i + 1][j + 1]);
	for(int i = 1, ok = 0; i < n && !ok; i++)
		for(int j = 1; j < m && !ok; j++)
			if(a[i][j] && a[i][m] && a[n][j] && a[n][m])
				ok = 1, ans--;
	cout << ans << endl;
    return cerr << "Time : " << clock() << endl, flush(), 0;
}