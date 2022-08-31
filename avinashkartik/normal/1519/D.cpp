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

const ll   N     =  5005;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N], dp[N][N], pre[N], suf[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		dp[i][i] = a[i] * b[i];
		if (i != n) dp[i][i + 1] = a[i] * b[i + 1] + a[i + 1] * b[i];
	}
	for (int len = 2; len < n; len++) {
		for (int i = 1; i + len <= n; i++) {
			dp[i][i + len] = a[i] * b[i + len] + a[i + len] * b[i] + dp[i + 1][i + len - 1];
		}
	}
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i] * b[i];
	for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i] * b[i];
	ll ans = pre[n];
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = max(ans, pre[i - 1] + dp[i][j] + suf[j + 1]);
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