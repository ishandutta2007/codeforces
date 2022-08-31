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

const ll   N     =  1e6 + 1;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, q, a[N], b[N], c[N];
ll inc[N], spf[N];
vll fact[N];

void solve() {
	for(int i = 1; i < N; i++) {
		for(int j = i; j < N; j += i) fact[j].push_back(i);
		spf[i] = fact[i][1];
		if(i == 1) inc[i] = 1;
		else if((i/spf[i])%spf[i] == 0) inc[i] = 0;
		else inc[i] =- inc[i/spf[i]];
	}

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 2; i <= n; i++) c[i] = a[i] - b[i];

	ll res = 0;
	vector <ll> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 2 * i; j <= n; j += i) c[j] -= c[i];
		if (inc[i]) v.pb(i);
		else res += abs(c[i]);
	}

	sort(all(v), [&](ll i, ll j){
		ll x = -c[i] / inc[i], y = -c[j] / inc[j];
		return x < y;
	});
	vector <ll> p(v.size()), s(v.size());
	p[0] = c[v[0]] * inc[v[0]];
	for (int i = 1; i < p.size(); i++) {
		p[i] = p[i - 1] + c[v[i]] * inc[v[i]];
	}

	s.back() = c[v.back()] * inc[v.back()];
	for (int i = s.size() - 2; i >= 0; i--) {
		s[i] = s[i + 1] + c[v[i]] * inc[v[i]];
	}

	n = v.size();
	cin >> q;
	for (int i = 1; i <= q; i++) {
		ll x; cin >> x; x = a[1] - x;
		ll l = 0, r = n - 1, ans = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			ll y = -c[v[mid]] / inc[v[mid]];
			if (y > x) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		if (ans == n) deb1(res + p.back() + x * n)
		else if (ans == 0) deb1(res + -s[0] - x * n)
		else deb1(res + p[ans - 1] + x * ans - s[ans] - x * (n - ans))
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}