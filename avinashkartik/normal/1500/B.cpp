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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

template<typename T>
T extgcd(T a, T b, T &x, T &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	T p = b / a;
	T g = extgcd(b - p * a, a, y, x);
	x -= p * y;
	return g;
}

template<typename T>
bool diophantine(T a, T b, T c, T &x, T &y, T &g) {
	if (a == 0 && b == 0) {
		if (c == 0) {
			x = y = g = 0;
			return true;
		}
		return false;
	}
	if (a == 0) {
		if (c % b == 0) {
			x = 0;
			y = c / b;
			g = abs(b);
			return true;
		}
		return false;
	}
	if (b == 0) {
		if (c % a == 0) {
			x = c / a;
			y = 0;
			g = abs(a);
			return true;
		}
		return false;
	}
	g = extgcd(a, b, x, y);
	if (c % g != 0) return false;
	T dx = c / a;
	c -= dx * a;
	T dy = c / b;
	c -= dy * b;
	x = dx + (T) ((__int128) x * (c / g) % b);
	y = dy + (T) ((__int128) y * (c / g) % a);
	g = abs(g);
	return true;
}

ll crt(ll k1, ll m1, ll k2, ll m2) {
	k1 %= m1;
	if (k1 < 0) k1 += m1;
	k2 %= m2;
	if (k2 < 0) k2 += m2;
	ll x, y, g;
	if (!diophantine(m1, -m2, k2 - k1, x, y, g)) {
		return -1;
	}
	ll dx = m2 / g;
	ll delta = x / dx - (x % dx < 0);
	return m1 * (x - dx * delta) + k1;
}

ll n, m, x, k, a[N], b[N], w[N];

ll f(ll x) {
	ll res = 0, lcm = n * m / __gcd(n, m);
	int sz = 2 * max(n, m);
	for (int i = 1; i <= sz; i++) {
		if (w[i] == -1) continue;
		res += x / lcm;
		if (w[i] && x % lcm >= w[i]) res++;
	}
	return x - res;
}

void solve() {
	mset(a, -1);
	mset(b, -1);
	mset(w, -1);

	cin >> n >> m >> k;
	int sz = 2 * max(n, m);

	for (int i = 1; i <= n; i++) {
		cin >> x; a[x] = i;
	}
	for (int i = 1; i <= m; i++) {
		cin >> x; b[x] = i;
	}

	for (int i = 1; i <= sz; i++) {
		if (a[i] != -1 && b[i] != -1) {
			w[i] = crt(a[i], n, b[i], m);
		}
	}

	ll l = 1, r = 4e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (f(mid) >= k) {
			r = mid - 1;
		} else l = mid + 1;
	}
	deb1(l)
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}