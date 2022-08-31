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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, f[N], b[N], ans[N];
vector <int> ind[N];

void solve() {
	int flag = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> f[i], ind[f[i]].pb(i);
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		if (ind[b[i]].size() == 0) {
			flag = 2;
		} else if (ind[b[i]].size() != 1) {
			if (flag == 0) flag = 1;
		} else {
			ans[i] = ind[b[i]][0];
		}
	}
	if (flag == 0) {
		deb1("Possible")
		for (int i = 1; i <= m; i++) cout << ans[i] << " ";
	} else if (flag == 1) {
		deb1("Ambiguity")
	} else deb1("Impossible")
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}