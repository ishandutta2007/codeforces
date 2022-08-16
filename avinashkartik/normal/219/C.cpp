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

const ll   N     =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, k, dp[N][26], wh[N][26];
string s;

void solve() {
	cin >> n >> k >> s;
	for (int i = 0; i < k; i++) {
		if (s[0] - 'A' == i) dp[0][i] = 0;
		else dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		int m1 = 0, m2 = 1;
		if (dp[i - 1][m1] > dp[i - 1][m2]) swap(m1, m2);
		for (int j = 2; j < k; j++) {
			if (dp[i - 1][j] <= dp[i - 1][m1]) {
				m2 = m1;
				m1 = j;
			} else if (dp[i - 1][j] < dp[i - 1][m2]) {
				m2 = j;
			}
		}
		for (int j = 0; j < k; j++) {
			if (s[i] - 'A' == j) {
				if (j == m1) dp[i][j] = dp[i - 1][m2], wh[i][j] = m2;
				else dp[i][j] = dp[i - 1][m1], wh[i][j] = m1;
			} else {
				if (j == m1) dp[i][j] = dp[i - 1][m2] + 1, wh[i][j] = m2;
				else dp[i][j] = dp[i - 1][m1] + 1, wh[i][j] = m1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < k; i++) {
		if (dp[n - 1][ans] > dp[n - 1][i]) ans = i;
	}
	deb1(dp[n - 1][ans])
	string res = "";
	for (int i = n - 1; i >= 0; i--) {
		res += ans + 'A';
		ans = wh[i][ans];
	}
	reverse(all(res));
	deb1(res)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}