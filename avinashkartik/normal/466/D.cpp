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

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, h, a[N], dp[2005][2005];

ll mem(int i, int j) {
	if (j < 0) return 0;
	if (i == n + 1) return j == 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = 0;
	if (j + a[i] == h) dp[i][j] = (mem(i + 1, j) + j * mem(i + 1, j - 1)) % mod;
	if (j + a[i] + 1 == h) dp[i][j] = ((j + 1) * mem(i + 1, j) + mem(i + 1, j + 1)) % mod;
	return dp[i][j];
}

void solve() {
	cin >> n >> h;
	for (int i = 1; i <= n; i++) cin >> a[i];
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