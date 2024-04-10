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

int n, q, a[N], b[N], x[N];
vector <int> adj[N];

void solve() {
	cin >> n >> q;
	vector <int> ct(n + 1, 0), ans(n + 1, 0);
	vector <vector <int>> bits(n + 1, vector <int>(30, 0)), is_set(n + 1, vector <int>(30, 0));
	for (int i = 1; i <= q; i++) {
		cin >> a[i] >> b[i] >> x[i];
		ct[a[i]]++;
		ct[b[i]]++;
		if (a[i] != b[i]) {
			adj[a[i]].pb(i);
			adj[b[i]].pb(i);
		} else {
			for (int j = 0; j < 30; j++) {
				if ((x[i] >> j)&1) is_set[a[i]][j] = 1;
			}
		}
		for (int j = 0; j < 30; j++) {
			if ((x[i] >> j)&1) bits[a[i]][j]++, bits[b[i]][j]++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 30; j++) {
			if (ct[i] == bits[i][j] && ct[i] != 0) ans[i] += (1 << j);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		ll res = (1ll << 31) - 1;
		for (auto it : adj[i]) {
			int val = a[it] == i ? b[it] : a[it];
			res &= ans[val];
		}
		if (1 + res == (1ll << 31)) res = 0;
		for (int j = 0; j < 30; j++) {
			if (is_set[i][j]) continue;
			if ((ans[i] >> j)&(res >> j)&1) {
				ans[i] -= (1 << j);
			}
		}
		
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}