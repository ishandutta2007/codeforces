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
		return sgn ? -x : x;
	}
	template <class T>
		inline void rprint(T x) {if(x >= 10) rprint(x / 10); pc(x % 10 + '0');}
	template <class T>
		inline void print(T x) {if(x < 0) pc('-'), x = -x; rprint(x);}
} using namespace IO;

template <class T1, class T2> void cmin(T1 &a, T2 b){a = a < b ? a : b;}
template <class T1, class T2> void cmax(T1 &a, T2 b){a = a > b ? a : b;}

const int N = 1e6 + 5;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m;
vector <char> mp[N];
vint ok[N];
queue <pii> q;
bool legal(int x, int y) {return x && y && x <= n && y <= m && mp[x][y] == '.';}
void dfs(int x, int y) {
	int cnt = 0;
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		cnt += legal(xx, yy) && !ok[xx][yy];
	} 
	if(cnt > 1) return;
	ok[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if(legal(xx, yy) && !ok[xx][yy]) dfs(xx, yy);
	} 
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		mp[i].clear(), mp[i].resize(m + 1),
		ok[i].clear(), ok[i].resize(m + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> mp[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(mp[i][j] == 'L') {
				ok[i][j] = 1;
				for(int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					if(legal(x, y)) dfs(x, y);
				}
			}
	for(int i = 1; i <= n; i++, cout << "\n")
		for(int j = 1; j <= m; j++)
			cout << (ok[i][j] && mp[i][j] != 'L' ? '+' : mp[i][j]); 
}
bool Med;
int main(){
	fprintf(stderr, "%.3lf\n", (&Mbe - &Med) / 1048576.0);
	int T; cin >> T; while(T--) solve(); 
	return cerr << "Time : " << clock() << endl, flush(), 0;
}

/*
1
3 2
.#
..
L. 
*/