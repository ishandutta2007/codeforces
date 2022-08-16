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

int n, a[505][505];
vector <int> ans;

class DSU {

	public :

	int n;
	vector <int> p, sz, e;

	DSU (int n) {
		this->n = n;
		p.resize(n);
		iota(all(p), 0);
		sz.resize(n, 1);
		e.resize(n);
		iota(all(e), 0);
	}

	void make(ll n) {
		for (int i = 1; i <= n; i++) {
			p[i] = i;
			sz[i] = 1;
		}
	}

	int find(ll x) {
		return (p[x] == x) ? x : p[x] = find(p[x]);
	}

	void merge(ll x, ll y) {
		p[x] = y;
		sz[x] += sz[y];
	}

	void rem(ll u, ll v) {
		p[u] = v;
		e[u] = v;
	}

	int finde(ll x) {
		return (e[x] == x) ? x : e[x] = finde(e[x]);
	}
};

struct edge {
	ll u, v, w;
	bool operator<(edge const& other) {
		return w < other.w;
	}
};

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	ans.pb(0);
	for (int i = 1; i <= n; i++) ans.pb(a[i][i]);
	DSU d(3 * n);

	int ct = 0;
	vector <edge> e, res;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			e.pb({i, j, a[i][j]});
		}
	}
	sort(all(e));
	for(auto it : e) {
		int u = d.find(it.u), v = d.find(it.v);
		if(u != v) {
			if(ans[u] == it.w && ans[v] == it.w) {
				d.rem(u, v);
				ct++;
			} else if(ans[u] == it.w) {
				d.merge(v, u);
				res.pb({v, u, 0});
			} else if(ans[v] == it.w) {
				d.merge(u, v);
				res.pb({u, v, 0});
			} else {
				ans.pb(it.w);
				d.merge(u, ++n);
				d.merge(v, n);
				res.pb({u, n, 0});
				res.pb({v, n, 0});
			}
		}
	}

	vector <int> v;
	v.pb(0);

	deb1(ans.size() - 1 - ct)
	for (int i = 1; i < ans.size(); i++) {
		if(d.e[i] != i) continue;
		cout << ans[i] << " ";
		v.pb(i);
	}
	newl;
	deb1(ans.size() - 1 - ct)
	for(auto it : res) {
		it.u = d.finde(it.u), it.v = d.finde(it.v);
		if(it.u == it.v) continue;
		int u1 = lower_bound(all(v), it.u) - v.begin(), v1 = lower_bound(all(v), it.v) - v.begin();
		deb2(u1, v1)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}