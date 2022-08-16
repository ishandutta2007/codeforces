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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, q, dp[N][N][2], vis[N][N], ans;
//0 -> right, 1 -> down

void add(int x, int y) {
	dp[x][y][1] = dp[x][y - 1][0] + 1;
	dp[x][y][0] = dp[x - 1][y][1] + 1;
	ans += (dp[x][y][0] + dp[x][y][1] - 2);
	for (int i = x, j = y + 1, f = 1; i <= n && j <= m;) {
		if (vis[i][j]) break;
		ans -= dp[i][j][f] - 1;
		if (f) dp[i][j][f] = dp[i][j - 1][1 - f] + 1;
		else dp[i][j][f] = dp[i - 1][j][1 - f] + 1;
		ans += dp[i][j][f] - 1;
		if (f == 1) i++;
		else j++;
		f = 1 - f;
	}
	for (int i = x + 1, j = y, f = 0; i <= n && j <= m;) {
		if (vis[i][j]) break;
		ans -= dp[i][j][f] - 1;
		if (f) dp[i][j][f] = dp[i][j - 1][1 - f] + 1;
		else dp[i][j][f] = dp[i - 1][j][1 - f] + 1;
		ans += dp[i][j][f] - 1;
		if (f == 1) i++;
		else j++;
		f = 1 - f;
	}
	ans++;
}

void remove(int x, int y) {
	ans -= (dp[x][y][0] + dp[x][y][1] - 2);
	dp[x][y][1] = 0;
	dp[x][y][0] = 0;
	for (int i = x, j = y + 1, f = 1; i <= n && j <= m;) {
		if (vis[i][j]) break;
		ans -= dp[i][j][f] - 1;
		if (f) dp[i][j][f] = dp[i][j - 1][1 - f] + 1;
		else dp[i][j][f] = dp[i - 1][j][1 - f] + 1;
		ans += dp[i][j][f] - 1;
		if (f == 1) i++;
		else j++;
		f = 1 - f;
	}
	for (int i = x + 1, j = y, f = 0; i <= n && j <= m;) {
		if (vis[i][j]) break;
		ans -= dp[i][j][f] - 1;
		if (f) dp[i][j][f] = dp[i][j - 1][1 - f] + 1;
		else dp[i][j][f] = dp[i - 1][j][1 - f] + 1;
		ans += dp[i][j][f] - 1;
		if (f == 1) i++;
		else j++;
		f = 1 - f;
	}
	ans--;
}

void solve() {
	cin >> n >> m >> q;
	// ans = n * m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vis[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			add(i, j);
			vis[i][j] = 1 - vis[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int x, y; cin >> x >> y;
		if (vis[x][y]) add(x, y);
		else remove(x, y);
		vis[x][y] = 1 - vis[x][y];
		deb1(ans)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}