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

const ll   N     =  505;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, K, a[N][N], b[N][N], dp[N][N][20];

void solve() {
	cin >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> b[i][j];
		}
	}
	if (K&1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << -1 << " ";
			}
			newl;
		}
		return;
	}
	mset(dp, 0);
	for (int k = 1; k <= K / 2; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j][k] = INFi;
				if (i != n) dp[i][j][k] = min(dp[i][j][k], dp[i + 1][j][k - 1] + 2 * b[i][j]);
				if (i != 1) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + 2 * b[i - 1][j]);
				if (j != m) dp[i][j][k] = min(dp[i][j][k], dp[i][j + 1][k - 1] + 2 * a[i][j]);
				if (j != 1) dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k - 1] + 2 * a[i][j - 1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dp[i][j][K / 2] << " ";
		}
		newl;
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