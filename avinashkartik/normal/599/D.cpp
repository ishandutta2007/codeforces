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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
vpll ans;

void solve() {
	cin >> n;
	ll ct = 0;
	for (ll i = 1; ;i++) {
		ll m = i * (i + 1) / 2;
		ct += i * (i - 1) / 2;
		if ((n + ct) < i * m) break;
		if ((n + ct) % m == 0) {
			ll x = (n + ct) / m;
			ans.pb({i, x});
		}
	}
	int sz = ans.size();
	for (int i = 0; i < sz; i++) {
		if (ans[i].s != ans[i].f)
			ans.pb({ans[i].s, ans[i].f});
	}
	sort(all(ans));
	uniq(ans);
	deb1(ans.size())
	for (auto it : ans) deb2(it.f, it.s)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}