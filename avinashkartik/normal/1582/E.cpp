#include <bits/stdc++.h>

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

const ll   N     =  3e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], p[N];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
	int sq = sqrt(2 * n);
	vector <vector <ll>> dp(n + 2);
	dp[n + 1].assign(sq + 1, -1);
	dp[n + 1][0] = INF;
	for (int i = n; i >= 1; i--) {
		dp[i].assign(sq + 1, -1);
		dp[i][0] = INF;
		if (i + sq + 1 <= n + 1) dp[i + sq + 1].clear();
		for (int j = 1; j <= sq; j++) {
			if (i + j > n + 1) break;
			if (p[i + j - 1] - p[i - 1] < dp[i + j][j - 1]) dp[i][j] = p[i + j - 1] - p[i - 1];
			dp[i][j] = max(dp[i][j], dp[i + 1][j]);
		}
	}
	int ans = 1;
	for (int j = 1; j <= sq; j++) {
		if (dp[1][j] > 0) ans = j;
	}
	deb1(ans)
}

int main(){
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}