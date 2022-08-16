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

const ll   N     =  1e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m;

void solve() {
	cin >> n >> m;
	vector <int> ct(n + 1, 0), ans(m + 1, 0);
	vector <vector<int>> v(m + 1);
	vector <pair<int, int>> vp;
	for (int i = 1; i <= m; i++) {
		int k, f; cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> f;
			v[i].pb(f);
		}
		vp.pb({v[i].size(), i});
	}
	sort(all(vp));
	for (auto it : vp) {
		int ind = v[it.s][0];
		for (auto x : v[it.s]) {
			if (ct[ind] > ct[x]) ind = x;
		}
		ans[it.s] = ind;
		ct[ind]++;
		if (ct[ind] > (m + 1) / 2) {
			deb1("NO")
			return;
		}
	}
	deb1("YES")
	for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}