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

int n, m, a[N], p[N];
char t[N];
ll dp[2][(1 << 21)];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<>());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> t[i] >> p[i];
	}

	for (int j = 0; j < (1 << m); j++) {
		dp[1][j] = INF;
	}

	dp[1][(1 << m) - 1] = 0;

	int f = 0;
	for (int i = m - 1; i >= 0; i--, f = 1 - f) {
		for (int j = 0; j < (1 << m); j++) {
			dp[f][j] = p[i] == 2? INF : -INF;
			if (__builtin_popcount(j) != i) continue;
			if (t[i] == 'p') {
				for (int pick = 0; pick < m; pick++) {
					if ((j >> pick)&1) continue;
					if (p[i] == 1) dp[f][j] = max(dp[f][j], dp[1 - f][j | (1 << pick)] + a[pick]);
					else dp[f][j] = min(dp[f][j], dp[1 - f][j | (1 << pick)] - a[pick]);
				}
			} else {
				for (int pick = 0; pick < m; pick++) {
					if ((j >> pick)&1) continue;
					if (p[i] == 1) dp[f][j] = max(dp[f][j], dp[1 - f][j | (1 << pick)]);
					else dp[f][j] = min(dp[f][j], dp[1 - f][j | (1 << pick)]);
				}
			}
		}
	}

	deb1(dp[1 - f][0])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}