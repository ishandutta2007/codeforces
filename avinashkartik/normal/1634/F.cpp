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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, q, m, c[N], d[N], f[N];

void solve() {
	cin >> n >> q >> m;
	
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		c[i] += x;
	}
	
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		c[i] -= x;
	}
	
	f[1] = f[2] = 1 % m;
	for (int i = 3; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % m;
	
	set <int> s;
	d[1] = c[1], d[2] = c[2] - c[1];
	for (int i = 3; i <= n; i++) {
		d[i] = (c[i] - c[i - 1] - c[i - 2] + 5 * m) % m;
		if (d[i]) s.insert(i);
	}
	
	auto add = [&](int i, ll x) {
		if (i > n) return;
		d[i] = (d[i] + m + x) % m;
		if (d[i] == 0) s.erase(i);
		else s.insert(i);
	};
	
	for (int i = 1; i <= q; i++) {
		char c;
		int l, r;
		cin >> c >> l >> r;
		if (c == 'A') {
			add(l, 1);
			add(r + 1, -f[r - l + 2]);
			add(r + 2, -f[r - l + 1]);
		} else {
			add(l, -1);
			add(r + 1, f[r - l + 2]);
			add(r + 2, f[r - l + 1]);
		}
		if (s.size() == 0) deb1("YES")
		else deb1("NO")
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