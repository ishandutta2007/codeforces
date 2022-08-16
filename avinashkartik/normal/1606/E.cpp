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

const ll   N     =  505;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, x, f[N], dp[N][N], c[N][N], p[N][N];

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
	if (n < 0 || r < 0 || n < r) return 0;
	return f[n] * fastmod(f[r]) % mod * fastmod(f[n - r]) % mod;
}

ll mem(int i, int j) {
	if (j > x) return 0;
	if (i == n) return (x - j) / (i - 1) + 1;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = (i == 1)? 0 : mem(i, j + i - 1);
	for (int no = 1; i + no <= n; no++) {
		ll res = c[n - i][no] * p[i + no - 1][no] % mod;
		dp[i][j] = (dp[i][j] + mem(i + no, j + i + no - 1) * res) % mod;
	}
	return dp[i][j];
}

void precalc() {
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = ncr(i, j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			p[i][j] = fastmod(i, j);
		}
	}
}

void solve(){
	precalc();
	cin >> n >> x;
	mset(dp, -1);
	ll ans = 0;
	for (int i = 1; i <= x; i++) ans = (ans + mem(1, i) * n) % mod;
	ans = (p[x][n] - ans + mod) % mod;
	deb1(ans)
}

int main(){
	int test = 1;
	// cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}