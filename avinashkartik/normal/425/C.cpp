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

const ll   N     =  1e5 + 1;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, s, e, a[N], b[N];
int dp[N][300];
vector <int> v[N];

void solve() {
	cin >> n >> m >> s >> e;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i], v[b[i]].pb(i);
	for (int i = 1; i < N; i++) v[i].pb(m + 1);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 300; j++) dp[i][j] = INFi;
	}
	dp[0][0] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 300; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j && dp[i - 1][j - 1] < m) {
				int ind = upper_bound(all(v[a[i]]), dp[i - 1][j - 1]) - v[a[i]].begin();
				if (v[a[i]][ind]!= m + 1) dp[i][j] = min(dp[i][j], v[a[i]][ind]);
			}
			if (i + dp[i][j] + j * e <= s) ans = max(ans, j);
		}
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