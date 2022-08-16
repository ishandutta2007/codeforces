#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

const ll   N     =  5e3 + 2;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], dp[N][N];
vector <int> o, z;

void solve() {
	o.pb(0);
	z.pb(0);
	int f = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) o.pb(i);
		else z.pb(i);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = INFi;
		}
	}
	ll ans = INF;
	dp[0][0] = 0;
	for (int i = 1; i < o.size(); i++) {
		ll mn = dp[i - 1][0];
		for (int j = 1; j < z.size(); j++) {
			dp[i][j] = mn + abs(o[i] - z[j]);
			mn = min(mn, dp[i - 1][j]);
			if (i == o.size() - 1) ans = min(ans, dp[i][j]);
		}
	}
	if (ans == INF) ans = 0;
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