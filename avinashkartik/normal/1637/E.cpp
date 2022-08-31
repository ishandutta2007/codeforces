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

int n, m, u[N], v[N];
map <pair<int, int>, bool> bad;

void solve() {
	cin >> n >> m;
	map <int, int> cnt;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(all(a));
	uniq(a);
	
	bad.clear();
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		u[i] = lower_bound(all(a), u[i]) - a.begin();
		v[i] = lower_bound(all(a), v[i]) - a.begin();
		bad[{u[i], v[i]}] = 1;
		bad[{v[i], u[i]}] = 1;
	}
	
	vector <int> ct(n);
	vector <vector <int>> g(n + 1);
	vector <int> v;
	n = a.size();
	
	for (int i = 0; i < n; i++) {
		ct[i] = cnt[a[i]];
		g[ct[i]].pb(i);
		v.pb(ct[i]);
	}
	sort(all(v));
	uniq(v);
	
	for (int i = 0; i <= n; i++) {
		reverse(all(g[i]));
	}
	
	auto f = [&](int x, int y) -> ll {
		if (bad.find({x, y}) != bad.end() || x == y) return 0;
		return (ll) (ct[x] + ct[y]) * (a[x] + a[y]);	
	};
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (auto j : v) {
			if (j > ct[i]) break;
			for (auto it : g[j]) {
				ll x = f(i, it);
				if (!x) continue;
				ans = max(ans, x);
				break;
			}
		}
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