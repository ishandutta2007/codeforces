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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;

void solve() {
	cin >> n;
	vector <pll> v(n), v1, v2;
	ll sum = 0;
	for (auto &[x, y] : v) cin >> x;
	for (auto &[x, y] : v) {
		cin >> y, sum += abs(y - x);
		if (x > y) v1.pb({y, x});
		else if (y > x) v2.pb({x, y});
	}
	sort(all(v1));
	sort(all(v2));
	ll p = 0, q = 0;
	ll ans = sum, j = 0, i = 0;
	for (auto [x, y] : v2) {
		while (j < v1.size() && v1[j].f <= x) {
			p = max(p, v1[j].s);
			j++;
		}
		if (p) ans = min(ans, sum - 2 * (min(y, p) - x));
	}
	for (auto [y, x] : v1) {
		while (i < v2.size() && v2[i].f <= y) {
			q = max(q, v2[i].s);
			i++;
		}
		if (q) ans = min(ans, sum - 2 * (min(x, q) - y));
	}
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