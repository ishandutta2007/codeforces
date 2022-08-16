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

const ll   N     =  6e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, l, r, f[N];

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while (y) {
		if (y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

ll ncr(ll n, ll r) {
	if (n < r || r < 0 || n < 0) return 0;
	return f[n] * fastmod(f[r]) % mod * fastmod(f[n - r]) % mod;
}

void solve() {
	cin >> n >> l >> r;
	ll d = max(1ll, min(1 - l, r - n));
	ll ans = (d - 1) * ncr(n, n / 2);
	if (n&1) ans += (d - 1) * ncr(n, (n + 1) / 2);
	for (int i = 1, j = n; ; d++) {
		if (d == 0) continue;
		while (i - d < l) i++;
		while (j + d > r) j--;
		if (i - j > 1) break;
		int left = j - i + 1;
		ans += ncr(left, n / 2 - i + 1);
		if (n&1) ans += ncr(left, (n + 1) / 2 - i + 1);
	}
	deb1(ans % mod)
}

int main() {
	GODSPEED;
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}