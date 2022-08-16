#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, a[N], f[N], pos[N];

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
	if (n < r || n < 0 || r < 0) return 0;
	return f[n] * fastmod(f[r]) % mod * fastmod(f[n - r]) % mod;
}

void solve() {
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
	cin >> n >> k;
	ll ct = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], pos[a[i]] = i;
	}
	for (int i = 1; i < n; i++) {
		ct -= pos[a[i] + 1] > pos[a[i + 1] + 1];
	}
	ll ans = 0;
	for (int i = n - ct + 1, j = 0; i <= k; i++, j++) {
		if (j > ct - 1) break;
		// deb2(k, i)
		// deb2(ct - 1, j)
		ans = (ans + ncr(k, i) * ncr(ct - 1, j)) % mod;
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