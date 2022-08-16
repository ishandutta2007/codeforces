#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first
#define  s              second
#define  newl           "\n"
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

typedef  long long             ll;
typedef  long double           ld;

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, p, a[N], dp[N], no;
vector <int> adj[N];

void dfs(int x) {
	if (adj[x].size() == 0) {
		dp[x] = 1;
		no++;
		return;
	}
	if (a[x] == 0) dp[x] = 0;
	else dp[x] = INFi;
	for (auto it : adj[x]) {
		dfs(it);
		if (a[x] == 0)
			dp[x] += dp[it];
		else
			dp[x] = min(dp[x], dp[it]);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		cin >> p;
		adj[p].pb(i);
	}
	no = 0;
	dfs(1);
	deb1(no + 1 - dp[1])
	for (int i = 1; i <= n; i++) adj[i].clear();
}

int main() {
	GODSPEED;
	int test = 1;
// 	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}