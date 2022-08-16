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

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, x[N], y[N];

ll nc2(ll x){
	return x * (x - 1) / 2;
}

tuple <ll, ll, ll> val(int i, int j){
	ll my, mx, c;
	if(x[j] == x[i]) my = INF, mx = INF, c = x[i];
	else {
		my = (y[j] - y[i]);
		mx = (x[j] - x[i]);
		ll g = __gcd(mx, my);
		mx /= g, my /= g;
		c = y[i] * mx - x[i] * my;
	}
	return tuple(my, mx, c);
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	map <pll, int> m;
	set <tuple <ll, ll, ll>> s;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			tuple <ll, ll, ll> v = val(i, j);
			if(s.find(v) == s.end()) {
				s.insert(v);
				m[{get<0>(v), get<1>(v)}]++;
			}
		}
	}
	ll ans = nc2(s.size());
	for(auto it : m) {
		ans -= nc2(it.s);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}