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

const int   N    =  5e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, k;

void solve() {
	cin >> n >> m >> k;
	vector <int> x, y;
	for (int i = 1; i <= n; i++) {
		int c; cin >> c;
		x.pb(c);
	}
	for (int i = 1; i <= m; i++) {
		int r; cin >> r;
		y.pb(r);
	}
	vector <pair<int, int>> p;
	for (int i = 1; i <= k; i++) {
		int x, y; cin >> x >> y;
		p.pb({x, y});
	}

	sort (all(p), [&](pair <int, int> i, pair <int, int> j) {
		return i.f < j.f;
	});

	ll i = 0, ct = 0, ans = 0;
	map <int, int> c;
	for (auto it : p) {
		while (i < n && x[i] < it.f) {
			c.clear();
			ct = 0;
			i++;
		}
		if (it.f == x[i]) continue;
		ans += ct - c[it.s];
		ct++;
		c[it.s]++;
	}

	sort (all(p), [&](pair <int, int> i, pair <int, int> j) {
		return i.s < j.s;
	});

	i = 0, ct = 0;
	c.clear();
	for (auto it : p) {
		while (i < m && y[i] < it.s) {
			c.clear();
			ct = 0;
			i++;
		}
		if (it.s == y[i]) continue;
		ans += ct - c[it.f];
		ct++;
		c[it.f]++;
	}
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