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

ll n, a[N];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 1, d = 0;
	map <ll, ll> m;
	for (int i = 2; i <= n; i++) {
		map <ll, ll> nm;
		for (auto it : m) {
			ll g = __gcd(abs(a[i] - a[it.s]), it.f);
			if (g != 1) {
				ans = max(ans, i - it.s + 1);
				if (nm.find(g) == nm.end()) nm[g] = it.s;
				else nm[g] = min(nm[g], it.s);
			}
		}
		ll g = abs(a[i] - a[i - 1]);
		if (g != 1) {
			ans = max(ans, 2ll);
			if (nm.find(g) == nm.end()) nm[g] = i - 1;
		}
		m = nm;
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