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

ll n, m;
string s[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	ll ans = INF;
	vector <int> v[n + 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') {
				v[i].pb(j);
				v[i].pb(j - m);
				v[i].pb(j + m);
			}
		}
		if (v[i].size() == 0) {
			deb1(-1)
			return;
		}
		sort(all(v[i]));
	}
	
	for (int c = 0; c < m; c++) {
		ll res = 0;
		for (int r = 0; r < n; r++) {
			int it = lower_bound(all(v[r]), c) - v[r].begin();
			res += min(abs(v[r][it] - c), abs(v[r][it - 1] - c));
		}
		ans = min(ans, res);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}