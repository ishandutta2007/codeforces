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

const ll   N     =  1e6 + 2;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n, m, k, a[N];
vector <tuple <ll, ll, ll, ll>> adj[N];

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= k; i++) {
		int a, b, c, d, h;
		cin >> a >> b >> c >> d >> h;
		adj[a].pb({b, c, d, h});
	}
	
	map <ll, ll> d[n + 1];
	d[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		sort(all(adj[i]));
		multiset <ll> s;
		vector <pair <ll, ll>> v;
		for (auto it : d[i]) {
			v.pb(it);
			s.insert(it.s + it.f * a[i]);
		}
		if (v.size() == 0) continue;
		ll mn = INF, j = 0;
		for (auto [b, ci, di, hi] : adj[i]) {
			while (j < v.size() && v[j].f < b){
				s.erase(s.find(v[j].s + v[j].f * a[i]));
				mn = min(mn, v[j].s - v[j].f * a[i]);
				j++;
			}
			ll dist = INF;
			if (s.size()) dist = min(dist, *s.begin() - b * a[i]);
			if (s.size() != v.size()) dist = min(dist, mn + b * a[i]);
			if (d[ci].find(di) == d[ci].end() || dist - hi < d[ci][di]) {
				d[ci][di] = dist - hi;
			}
		}
	}

	ll ans = INF;
	for (int i = 1; i <= m; i++) {
		if (d[n].find(i) != d[n].end()) ans = min(ans, d[n][i] + (m - i) * a[n]);
	}
	if (ans >= INF) deb1("NO ESCAPE")
	else deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}