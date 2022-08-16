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

const ll   N     =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, x, a[N], dp[N][3];

ll mem(int i, int j) {
	if (i == n + 1) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = mem(i + 1, 0);
	if (j == 0) {
		dp[i][j] = max(dp[i][j], mem(i + 1, 1) + 1);
	} else if (j == 1 && a[i] + a[i - 1] >= 2 * x) {
		dp[i][j] = max(dp[i][j], mem(i + 1, 2) + 1);
	} else if (j == 2 && a[i] + a[i - 1] + a[i - 2] >= 3 * x && a[i] + a[i - 1] >= 2 * x) {
		dp[i][j] = max(dp[i][j], mem(i + 1, 2) + 1);
	}
	return dp[i][j];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> x;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = -1;
	}
	deb1(mem(1, 0))
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}