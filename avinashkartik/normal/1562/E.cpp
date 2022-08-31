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

const ll   N     =  5e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e16;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
string s;

void solve() {
	cin >> n >> s;
	s = '#' + s + '#';
	vector <vector <int>> lcp(n + 2, vector <int>(n + 2, 0));
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
		}
	}
	vector <ll> dp(n + 1, 0);
	dp[1] = n;
	for (int i = 2; i <= n; i++) {
		dp[i] = n - i + 1;
		for (int j = 1; j < i; j++) {
			int l = lcp[i][j];
			if (s[i + l] > s[j + l]) {
				dp[i] = max(dp[i], dp[j] + n - i - l + 1);
			}
		}
	}
	deb1(*max_element(all(dp)))
}

int main() {
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}