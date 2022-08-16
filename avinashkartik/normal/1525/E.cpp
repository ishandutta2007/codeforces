#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

const ll   N     =  5e4 + 2;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, a[25][N], f[N];

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while (y) {
		if (y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

void solve() {
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
	ll ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int no = 0; no < m; no++) {
		vector <ll> v(n);
		for (int i = 0; i < n; i++) v[i] = a[i][no];
		sort(all(v), greater<>());
		// debv(v)
		ll i = 0, res = 0, cur = 1;
		for (int mv = 1; mv <= n; mv++) {
			while(i < n && v[i] >= n - mv + 2) i++;
			// deb1(i)
			res += cur * (n - i) * f[n - mv];
			cur *= (i - mv + 1);
			res %= mod;
			cur %= mod;
		}
		// deb1(res)
		ans += res;
		ans %= mod;
	}
	// deb2(ans, f[n])
	deb1((ans * fastmod(f[n])) % mod)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}