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

ll n, k, dp[N][N][2];

ll mem(int i, int j, int f) {
	if(i == 0) return 0;
	if(i == n + 1) return 0;
	if(dp[i][j][f] != -1) return dp[i][j][f];
	dp[i][j][f] = mem(i + 1 - 2 * f, j, f);
	if(j != 1) dp[i][j][f] += mem(i - 1 + 2 * f, j - 1, 1 - f) + 1;
	dp[i][j][f] %= mod;
	return dp[i][j][f];
}

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}
	deb1((mem(1, k, 0) + 1) % mod)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}