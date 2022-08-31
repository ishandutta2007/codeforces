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

const ll   N     =  3e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, a[N], dp[102][200002], sum = 0, g = 0;

ll mem(int i, int j) {
	if (i == n + 1) return j == sum / 2;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = mem(i + 1, j + a[i]) | mem(i + 1, j);
	return dp[i][j];
}

void solve() {
	mset(dp, -1);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i], g = __gcd(g, a[i]);
	if (sum&1) {
		deb1(0)
		return;
	}
	int x = mem(1, 0);
	if (x == 0) {
		deb1(0)
		return;
	}
	for (int i = 1; i <= n; i++) a[i] /= g;
	for (int i = 1; i <= n; i++) {
		if (a[i]&1) {
			deb1(1)
			deb1(i)
			return;
		}
	}
	
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}