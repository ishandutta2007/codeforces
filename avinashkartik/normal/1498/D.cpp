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
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, ans[N];

void update(int i, int x){
	ans[i] = min(ans[i], x);
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) ans[i] = n + 1;
	for(int i = 1; i <= n; i++) {
		ll t, x, y;
		cin >> t >> x >> y;
		vector <int> vis(m + 1, 0), prv(m + 1, 0);
		if(t == 2) vis[0] = 1;
		for(int i = 1; i <= m; i++) prv[i] = ans[i];
		for(int j = 0; j <= m; j++) {
			if(prv[j] > i) continue;
			if(vis[j] == 1) continue;
			vector <int> v;
			if(t == 2) {
				ll k = j;
				while(k <= m) {
					vis[k] = 1;
					v.pb(k);
					k = k * x;
					int f = 0;
					if(k % 100000) f = 1;
					k = k / 100000 + f;
				}
				multiset <int> s;
				for(int ii = 0; ii < v.size(); ii++) {
					if(ii > y) {
						s.erase(s.find(prv[v[ii - y - 1]]));
					}
					if(s.size() && *s.begin() < i) update(v[ii], i);
					s.insert(prv[v[ii]]);
				}
			} else {
				ll k = j;
				while(k <= m) {
					vis[k] = 1;
					v.pb(k);
					k = k + x / 100000;
					int f = 0;
					if(x % 100000) f = 1;
					k = k + f;
				}
				multiset <int> s;
				for(int ii = 0; ii < v.size(); ii++) {
					if(ii > y) {
						s.erase(s.find(prv[v[ii - y - 1]]));
					}
					if(s.size() && *s.begin() < i) {
						update(v[ii], i);
					}
					s.insert(prv[v[ii]]);
				}

			}
		}
	}
	for(int i = 1; i <= m; i++) {
		if(ans[i] > n) ans[i] = -1;
		cout << ans[i] << " ";
	}
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}