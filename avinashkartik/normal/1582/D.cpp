#include <bits/stdc++.h>

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

const ll   N     =  3e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N];

pll calc(ll x, ll y) {
	int f = 0;
	if (x < 0) f ^= 1, x = -x;
	if (y < 0) f ^= 1, y = -y;
	ll lcm = x * y / gcd(x, y);
	if (f == 0) return {-lcm / x, lcm / y};
	return {lcm / x, lcm / y};
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n&1) {
		if (a[1] != -a[2]) {
			pll p = calc(a[1] + a[2], a[3]);
			b[1] = p.f, b[2] = p.f, b[3] = p.s;
		} else if (a[1] != -a[3]) {
			pll p = calc(a[1] + a[3], a[2]);
			b[1] = p.f, b[3] = p.f, b[2] = p.s;
		} else {
			pll p = calc(a[2] + a[3], a[1]);
			b[2] = p.f, b[3] = p.f, b[1] = p.s;
		}
		for (int i = 4; i <= n; i += 2) {
			pll p = calc(a[i], a[i + 1]);
			b[i] = p.f, b[i + 1] = p.s;
		}
	} else {
		for (int i = 1; i <= n; i += 2) {
			pll p = calc(a[i], a[i + 1]);
			b[i] = p.f, b[i + 1] = p.s;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << b[i] << " ";
	}
	newl;
}

int main(){
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}