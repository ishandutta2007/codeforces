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

const ll   N     =  505;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e16;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, dp[N][2 * N][2];
string s, t;

int mem(int i, int j, int f) {
	if (j == t.size() - 1) return s[i] == t[j];
	if (dp[i][j][f] != -1) return dp[i][j][f];
	if (s[i] != t[j]) return 0;
	dp[i][j][f] = 0;
	if (f == 1) {
		if (i) dp[i][j][f] |= mem(i - 1, j + 1, 0);
		if (i != s.size() - 1) dp[i][j][f] |= mem(i + 1, j + 1, 1);
	} else {
		if (i) dp[i][j][f] |= mem(i - 1, j + 1, 0);
	}
	return dp[i][j][f];
}

void solve() {
	cin >> s >> t;
	mset(dp, -1);
	for (int i = 0; i < s.size(); i++) {
		if (mem(i, 0, 1)) {
			deb1("Yes")
			return;
		}
	}
	deb1("No")
}

int main() {
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}