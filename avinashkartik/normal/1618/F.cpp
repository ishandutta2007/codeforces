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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll x, y;
map <pair <ll, int>, bool> dp;

ll rev(ll x) {
	ll y = 0;
	while (x) {
		y = y * 2 + (x % 2);
		x /= 2;
	}
	return y;
}

bool mem(ll x, int f) {
	if (x >= 2 * y) return 0;
	if (x == y) return 1;
	if (dp.find({x, f}) != dp.end()) return dp[{x, f}];
	dp[{x, f}] = mem(rev(2 * x + 1), 0);
	if (f == 0) dp[{x, f}] |= mem(rev(x), 1);
	return dp[{x, f}];
}

void solve() {
	cin >> x >> y;
	if (mem(x, 1) || mem(rev(x), 0)) deb1("YES")
	else deb1("NO")
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}