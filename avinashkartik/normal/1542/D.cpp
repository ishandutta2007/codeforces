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

const ll   N     =  505;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, dp[N][N], a[N], ind;
char c[N];

ll mem(int i, int j) {
	if (i == n + 1) return a[ind];
	if (dp[i][j] != -1) return dp[i][j];
	if (i == ind) return dp[i][j] = mem(i + 1, j);
	else if (i < ind) {
		if (c[i] == '-') {
			dp[i][j] = mem(i + 1, j);
			if (j) dp[i][j] += mem(i + 1, j - 1);
			else dp[i][j] += mem(i + 1, j);
		} else {
			dp[i][j] = mem(i + 1, j);
			if (a[i] > a[ind]) dp[i][j] += mem(i + 1, j);
			else dp[i][j] += mem(i + 1, j + 1);
		}
	} else {
		if (c[i] == '-') {
			dp[i][j] = mem(i + 1, j);
			if (j) dp[i][j] += mem(i + 1, j - 1);
		} else {
			dp[i][j] = mem(i + 1, j);
			if (a[i] >= a[ind]) dp[i][j] += mem(i + 1, j);
			else dp[i][j] += mem(i + 1, j + 1);
		}
	}
	dp[i][j] %= mod;
	return dp[i][j];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == '+') cin >> a[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c[i] == '-') continue;
		mset(dp, -1);
		ind = i;
		ans += mem(1, 0);
		ans %= mod;
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