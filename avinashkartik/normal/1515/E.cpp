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

const ll   N     =  405;
// const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, mod, dp[2][N][N], f[N], p2[N], c[N][N];

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while (y) {
		if (y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

ll ncr(ll n, ll r) {
	return f[n] * fastmod(f[r]) % mod * fastmod(f[n - r]) % mod;
}

void solve() {
	cin >> n >> mod;
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
	p2[0] = 1;
	for (int i = 1; i <= n; i++) {
		p2[i] = p2[i - 1] * 2 % mod;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			c[i][j] = ncr(i, j);
		}
	}
	mset(dp, 0);
	ll ans = 0;
	dp[1][1][1] = 1;
	for (int i = 1, f = 1; i <= n; i++, f = 1 - f) {
		for (int j = 0; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[1 - f][j][k] = 0;
			}
		}
		for (int j = 0; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (i == n && j) {
					ans = (ans + dp[f][j][k] * p2[j - 1] % mod * c[k][j] % mod) % mod;
					continue;
				}
				if (j) {
					dp[1 - f][0][k] = (dp[1 - f][0][k] + dp[f][j][k] * p2[j - 1] % mod * c[k][j] % mod) % mod;
				}
				dp[1 - f][j + 1][k + 1] = (dp[1 - f][j + 1][k + 1] + dp[f][j][k]) % mod;
			}
		}
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