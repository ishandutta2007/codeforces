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

const ll   N     =  3e5 + 2;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, k, a[N], s[N];
int dp[502][502];

int mem(int i, int j) {
	if (i == n + 1) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = INFi;
	for (int nxt = i + 1; nxt <= n + 1; nxt++) {
		if (j + nxt - i - 1 > k) break;
		dp[i][j] = min(dp[i][j], mem(nxt, j + nxt - i - 1) + s[i] * (a[nxt] - a[i]));
	}
	return dp[i][j];
}

void solve() {
	cin >> n >> a[n + 1] >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	mset(dp, -1);
	deb1(mem(1, 0))
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}