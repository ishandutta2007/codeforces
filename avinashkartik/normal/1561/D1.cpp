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

const ll   N     =  4e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, dp[N], c[N];

void solve() {
	cin >> n >> m;
	dp[1] = 1;
	ll curs = 1, curd = 0;
	for (int i = 2; i <= n; i++) {
		c[i]++;
		curd = (curd + c[i]) % m;
		dp[i] = (curs + curd) % m;
		curs = (curs + dp[i]) % m;
		for (int j = 2 * i; j < min(n + 1, (ll)i * i); j += i) {
			c[j] = (c[j] + dp[j / i] - dp[j / i - 1] + m) % m;
			c[j] = (c[j] + dp[i] - dp[i - 1] + m) % m;
		}
		if ((ll) i * i <= n) c[i * i] = (c[i * i] + dp[i] - dp[i - 1] + m) % m;
		// deb2(i, dp[i])
	}
	deb1(dp[n])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}