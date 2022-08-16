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

const ll   N     =  1e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, k, dp[N], b[N], c[N];

int mem(int i) {
	if (i == 1) return 0;
	if (dp[i] != -1) return dp[i];
	dp[i] = INFi;
	for (int j = 1; j < i; j++) {
		int no = j / (i - j);
		for (int x = max(1, no - 2); x <= no + 2; x++) {
			if (j + j / x == i) dp[i] = min(dp[i], mem(j) + 1);
		}
	}
	return dp[i];
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> b[i], b[i] = dp[b[i]];
	for (int i = 1; i <= n; i++) cin >> c[i];
	int sum = accumulate(b + 1, b + n + 1, 0);
	if (k >= sum) {
		deb1(accumulate(c + 1, c + n + 1, 0))
		return;
	}
	vector <vector <ll>> dp(2, vector <ll> (k + 1, -INFi));
	dp[0][0] = 0;
	int f = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[f][j] = dp[1 - f][j];
			if (j >= b[i]) dp[f][j] = max(dp[f][j], dp[1 - f][j - b[i]] + c[i]);
			ans = max(ans, dp[f][j]);
		}
		f = 1 - f;
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	mset(dp, -1);
	dp[1] = 0;
	for (int i = 2; i <= 1e3; i++) mem(i);
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}