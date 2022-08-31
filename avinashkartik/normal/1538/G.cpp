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

const ll   N     =  5e4 + 5;
const ll   mod   = 	1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll x, y, a, b;

ll ff(ll n, ll i) {
	ll x1 = i * a + (n - i) * b;
	ll y1 = i * b + (n - i) * a;
	x1 = x - x1, y1 = y - y1;
	if (x1 < 0) return x1;
	if (y1 < 0) return y1;
	return x1 + y1;
}

bool f(ll mid) {
	ll l = 0, r = mid;
	while (r - l > 3) {
		ll m1 = l + (r - l) / 3;
		ll m2 = r - (r - l) / 3;
		if(ff(mid, m1) > ff(mid, m2)) {
			r = m2 - 1;
		} else l = m1 + 1;
	}
	bool ans = 0;
	for (ll i = l; i <= r; i++) {
		ans |= ff(mid, i) >= 0;
	}
	return ans;
}

void solve() {
	cin >> x >> y >> a >> b;
	ll l = 0, r = 2e9, ans = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (f(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}