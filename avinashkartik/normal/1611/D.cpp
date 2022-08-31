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

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], p[N], ind[N], f, d[N];
vector <int> adj[N];

void dfs(int x, int sum) {
	if (sum > ind[x]) f = 1;
	d[x] = ind[x] - sum;
	for (auto it : adj[x]) {
		dfs(it, ind[x]);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) adj[i].clear();
	int r = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == i) r = i;
		else adj[a[i]].pb(i);
	}
	for (int i = 1; i <= n; i++) cin >> p[i], ind[p[i]] = i - 1;
	f = 0;
	dfs(r, 0);
	if (f) {
		deb1(-1)
	} else {
		for (int i = 1; i <= n; i++) cout << d[i] << " ";
		newl;
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}