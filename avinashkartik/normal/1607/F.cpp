#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, vis[N][N], d[N][N], f = 0, r, c, dep[N][N];
string s[N];

int dfs(int i, int j, int d1) {
	if (i >= n || i < 0) return 0;
	if (j >= m || j < 0) return 0;
	if (vis[i][j] == 1)  {
		f = d1 - dep[i][j], r = i, c = j;
		return 0;
	}
	if (vis[i][j] == 2) return d[i][j];
	vis[i][j] = 1;
	dep[i][j] = d1;
	if (s[i][j] == 'U') d[i][j] = dfs(i - 1, j, d1 + 1) + 1;
	if (s[i][j] == 'D') d[i][j] = dfs(i + 1, j, d1 + 1) + 1;
	if (s[i][j] == 'L') d[i][j] = dfs(i, j - 1, d1 + 1) + 1;
	if (s[i][j] == 'R') d[i][j] = dfs(i, j + 1, d1 + 1) + 1;
	vis[i][j] = 2;
	if (f) {
		d[i][j] = f;
		if (r == i && c == j) f = 0;
	}
	return d[i][j];
}


void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) vis[i][j] = 0, d[i][j] = 0, dep[i][j] = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == 0) dfs(i, j, 0);
		}
	}
	int r = 0, c = 0, ans = d[r][c];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[i][j] > ans) {
				r = i, c = j, ans = d[i][j];
			}
		}
	}
	deb3(r + 1, c + 1, ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}