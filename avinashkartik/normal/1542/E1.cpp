#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
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

const ll   N     =  55;
// const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, dp[N][N * N], mod;

ll mem(int i, int j) {
	if (j < 0) return 0;
	if (i == 0) {
		return j == 0;
	}
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	for (int ii = 0; ii < i; ii++) {
		dp[i][j] += mem(i - 1, j - ii);
		dp[i][j] %= mod;
	}
	return dp[i][j];
}

void solve() {
	cin >> n >> mod;
	mset(dp, -1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n * n; j++) {
			mem(i, j);
		}
	}
	ll ans = 0, cur = 1;
	for (ll i = 1; i < n; i++) {
		ll left = n - i + 1;
		for (ll dif = 1; dif < left; dif++) {
			ll res = 0;
			for (ll p = n * n, q = n * n - dif - 1; q >= 0; p--, q--) {
				res = (res + mem(n - i, p)) % mod;
				ans += cur * (left - dif) % mod * res % mod * mem(n - i, q) % mod;
				ans %= mod;
			}
		}
		cur = (cur * left) % mod;
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}