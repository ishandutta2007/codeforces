#include<bits/stdc++.h>

using namespace std;

#define  f              first
#define  s              second
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;

void solve() {
	cin >> n;
	vector <int> vis(n + 1, 0), e, o;
	vector <pair<int, int>> ans;
	deb2("?", 1);
	for (int j = 1; j <= n; j++) {
		int x; cin >> x;
		if (x & 1) o.pb(j);
		else if (j != 1) e.pb(j);
		if (x == 1) {
			ans.pb({1, j});
		}
	}
	if (o.size() > e.size()) swap(o, e);
	for (auto i : o) {
		deb2("?", i);
		for (int j = 1; j <= n; j++) {
			int x; cin >> x;
			if (x == 1) {
				ans.pb({min(i, j), max(i, j)});
			}
		}
	}
	sort(all(ans));
	uniq(ans);
	deb1("!")
	for (auto it : ans) deb2(it.f, it.s)
}

int main() {
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}