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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, dp[10][N][10];

void pre() {
	for (int i = 0; i < 10; i++) {
		dp[i][0][i] = 1;
		for (int j = 1; j < N; j++) {
			for (int k = 1; k < 10; k++) {
				dp[i][j][k] = dp[i][j - 1][k - 1];
			}
			dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][9]) % mod;
			dp[i][j][0] = dp[i][j - 1][9];
		}
	}
}

void solve() {
	cin >> n >> m;
	vector <int> cnt(10, 0);
	while (n) {
		cnt[n % 10]++;
		n /= 10;
	}
	ll ans = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ans = (ans + cnt[i] * dp[i][m][j]) % mod;
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	pre();
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}