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
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, l[N], r[N], dp[52][N], spf[N], inc[N];
ll pre[N], ct[N];
vector <int> fact[N];

void solve() {
	for(int i = 1; i < N; i++) {
		for(int j = i; j < N; j += i) fact[j].push_back(i);
		spf[i] = fact[i][1];
		if(i == 1) inc[i] = 1;
		else if((i/spf[i])%spf[i] == 0) inc[i] = 0;
		else inc[i] =- inc[i/spf[i]];
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	for (int g = 1; g <= m; g++) {
		int tot = m / g, f = 0;
		for (int i = 1; i <= n; i++) {
			int no = (l[i] + g - 1) / g;
			if (no * g > r[i]) f = 1;
			tot -= no;
		}
		if (tot < 0 || f == 1) continue;
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int li = (l[i] + g - 1) / g, ri = r[i] / g, rb = min(tot, ri - li);
			pre[0] = dp[i - 1][0];
			for (int j = 1; j <= tot; j++) {
				pre[j] = (pre[j - 1] + dp[i - 1][j]) % mod;
			}
			for (int j = 0; j <= tot; j++) {
				dp[i][j] = pre[min(j, rb)];
				// deb4(g, i, j, dp[i][j])
			}
		}
		for (int j = 0; j <= tot; j++) ct[g] = (ct[g] + dp[n][j]) % mod;
	}
	ll ans = 0;
	for (int g = 1; g <= m; g++) {
		// deb2(g, ct[g])
		ans = (ans + mod + ct[g] * inc[g]) % mod;
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