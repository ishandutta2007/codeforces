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

const ll   N     =  1e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, dp[1002][1002][2];
string s, t;

void solve() {
	cin >> s >> t;
	n = s.size(), m = t.size();
	s = '#' + s + '#';
	t = '#' + t + '#';
	mset(dp, 0);
	for (int i = 1, ct = 0; i <= n; i++) {
		if (s[i] == s[i - 1]) ct = 1;
		else ct++;
		dp[i][0][0] = ct;
	}
	for (int i = 1, ct = 0; i <= m; i++) {
		if (t[i] == t[i - 1]) ct = 1;
		else ct++;
		dp[0][i][1] = ct;
	}
	ll ans = 0;
	for (int i = 1, c1 = 0; i <= n; i++) {
		for (int j = 1, c2 = 0; j <= m; j++) {
			if (s[i] != s[i - 1]) dp[i][j][0] += dp[i - 1][j][0];
			if (s[i] != t[j]) dp[i][j][0] += dp[i - 1][j][1];
			if (t[j] != s[i]) dp[i][j][1] += dp[i][j - 1][0];
			if (t[j] != t[j - 1]) dp[i][j][1] += dp[i][j - 1][1];
			dp[i][j][0] = (dp[i][j][0] + 1) % mod;
			dp[i][j][1] = (dp[i][j][1] + 1) % mod;
			ans = (ans + dp[i][j][0] + dp[i][j][1]) % mod;
		}
	}
	for (int i = 1, ct = 0; i <= n; i++) {
		if (s[i] == s[i - 1]) ct = 1;
		else ct++;
		ans = (ans + mod - ct * m) % mod;
	}
	for (int i = 1, ct = 0; i <= m; i++) {
		if (t[i] == t[i - 1]) ct = 1;
		else ct++;
		ans = (ans + mod - ct * n) % mod;
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}