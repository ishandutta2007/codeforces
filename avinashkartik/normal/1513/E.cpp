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

ll n, a[N], f[N];

void pre() {
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
}

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while (y) {
		if (y & 1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

ll ncr(ll n, ll r) {
	return f[n] * fastmod(f[r]) % mod * fastmod(f[n - r]) % mod;
}

void solve() {
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	if (sum % n) {
		deb1(0)
		return;
	}
	sum /= n;
	vector <int> ct(3);
	map <int, int> m[3];
	for (int i = 1; i <= n; i++) {
		if (a[i] < sum) ct[0]++, m[0][a[i]]++;
		if (a[i] == sum) ct[1]++, m[1][a[i]]++;
		if (a[i] > sum) ct[2]++, m[2][a[i]]++;
	}
	if (ct[1] == n) {
		deb1(1)
		return;
	}
	ll ans = 2;
	if (ct[0] == 1) ans += ct[2] - 1;
	if (ct[2] == 1) ans += ct[0] - 1;
	ans = ans * f[ct[0]] % mod;
	ans = ans * f[ct[2]] % mod;
	ans = ans * ncr(n, ct[1]) % mod;
	for (auto it : m[0]) {
		ans = ans * fastmod(f[it.s]) % mod;
	}
	for (auto it : m[2]) {
		ans = ans * fastmod(f[it.s]) % mod;
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	pre();
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}