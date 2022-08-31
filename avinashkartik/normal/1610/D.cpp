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

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N];

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while (y > 0) {
		if (y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

ll calc(vector <int> v) {
	ll e = 0, o = 0;
	for (auto it : v) {
		if (it&1) o++;
		else e++;
	}
	return fastmod(2, e) * (fastmod(2, o - 1) - 1) % mod;
}

void solve() {
	cin >> n;
	ll e = 0, o = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i]&1) o++;
		else e++;
	}
	ll ans = fastmod(2, e) * (fastmod(2, o) - 1) % mod;
	for (int i = 1; i < 30; i++) {
		vector <int> v;
		for (int j = 1; j <= n; j++) 
			if (a[j] % (1 << i) == 0) v.pb(a[j] / (1 << i));
		ans = (ans + calc(v)) % mod;
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