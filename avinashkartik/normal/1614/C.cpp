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

ll n, m;

ll fastmod(ll x, ll y) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

void solve() {
	cin >> n >> m;

	vector <ll> basis(31, 0);
	int sz = 0;

	auto insert = [&](ll x) {
		for (int j = 29; j >= 0; j--) {
			if (((1ll << j)&x) == 0) continue;
			if (basis[j]) x ^= basis[j];
			else {
				basis[j] = x;
				sz++;
				break;
			}
		}
	};

	for (int i = 1; i <= m; i++) {
		ll l, r, x; cin >> l >> r >> x;
		insert(x);
	}

	ll no = fastmod(2, n - 1), ans = 0;
	for (int i = 0; i < 30; i++) {
		int s = 0, ns = 0;
		for (auto it : basis) {
			if (it == 0) continue;
			if ((it >> i)&1) s++;
			else ns++;
		}
		if (s) ans = (ans + fastmod(2, i)) % mod;
	}
	ans = (ans * no) % mod;
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