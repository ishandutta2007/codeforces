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

const ll   N     =  2e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll k, n;
map <pll, ll> dp;
map <ll, int> c;
map <string, int> ind = {{"white", 1}, {"yellow", 6}, {"red", 2}, {"orange", 5}, {"blue", 3}, {"green", 4}};

ll fastmod(ll x, ll y) {
	ll res = 1;
	x %= mod;
	while (y > 0) {
		if (y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

vector <ll> extras;

ll mem(ll i, int j, int kk) {
	if (c.find(i) == c.end()) {
		extras.pb(i);
		return 1;
	}
	if (c[i] && j != c[i]) return 0;
	if (dp.find({i, j}) != dp.end()) return dp[{i, j}];
	if (kk == k - 1) return 1;
	ll res1 = 0, res2 = 0;
	for (int c1 = 1; c1 <= 6; c1++) {
		if (c1 == j || c1 == 7 - j) continue;
		res1 += mem(2 * i, c1, kk + 1);
		res2 += mem(2 * i + 1, c1, kk + 1);
	}
	dp[{i, j}] = (res1 % mod) * (res2 % mod) % mod;
	return dp[{i, j}];
}

void solve() {
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		string s; cin >> s;
		c[x] = ind[s];
		while (x) {
			if (c.find(x) == c.end()) c[x] = 0;
			x /= 2;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= 6; i++) ans += mem(1, i, 0);
	ans %= mod;
	sort(all(extras));
	uniq(extras);
	ans = ans * fastmod(4, (1ll << k) - 1 - c.size() - extras.size()) % mod;
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