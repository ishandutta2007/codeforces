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

const ll   N     =  4e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], p[N], mx = 0, mxd[N], mnd[N];
vll adj[N], d[N];

void dfs(int x, ll dep = 0){
	d[dep].pb(x);
	mx = max(mx, dep);
	mxd[dep] = max(mxd[dep], a[x]);
	mnd[dep] = min(mnd[dep], a[x]);
	for(auto it : adj[x]) {
		dfs(it, dep + 1);
	}
}

void solve() {
	cin >> n;
	for(int i = 2; i <= n; i++) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	vll dp(n + 1, 0);
	for(int i = 2; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) mxd[i] = -INF, mnd[i] = INF;
	dfs(1);
	ll mxi = -INF, mni = -INF;
	for(int i = 1; i <= mx; i++) {
		for(auto it : d[i]) {
			if(i > 1) {
				dp[it] = dp[p[it]] + max(abs(a[p[it]] - mxd[i - 1]), abs(a[p[it]] - mnd[i - 1]));
				dp[it] = max(dp[it], max(mxi - a[p[it]], mni + a[p[it]]));
			}
		}
		mxi = -INF, mni = -INF;
		for(auto it : d[i]) {
			mxi = max(mxi, dp[it] + a[it]);
			mni = max(mni, dp[it] - a[it]);
		}
	}
	ll ans = -INF;
	for(auto it : d[mx]) {
		ans = max(ans, dp[it] + max(abs(a[it] - mxd[mx]), abs(a[it] - mnd[mx])));
	}
	deb1(ans)
	for(int i = 0; i <= n; i++) adj[i].clear(), d[i].clear();
	mx = 0;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}