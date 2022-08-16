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

const ll   N     =  3e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N], dp[N], mx[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	a[0] = -INF;
	stack <int> s;
	s.push(0);
	for (int i = 1; i <= n; i++) {
		ll mxq = -INF;
		while (a[s.top()] > a[i]) {
			mxq = max(mxq, mx[s.top()]);
			s.pop();
		}
		mx[s.top()] = max(mxq, mx[s.top()]);
		dp[i] = mx[s.top()] + b[i];
		if (s.top()) dp[i] = max(dp[i], dp[s.top()]);
		s.push(i);
		mx[i] = dp[i];
	}
	deb1(dp[n])
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}