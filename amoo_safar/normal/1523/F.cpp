// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const int Log = 14;

ll x[Log], y[Log];
ll a[N], b[N];
ll t[N];

ll dp[1 << Log][N];
ll ds[1 << Log][N];

ll mn[N];
ll m2[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for(int i = 0; i < m; i++)
		cin >> a[i] >> b[i] >> t[i];
	vector<int> VV;
	for(int i = 0; i < m; i++) VV.pb(i);
	sort(all(VV), [&](int i, int j){
		return t[i] < t[j];
	});

	memset(dp, 31, sizeof dp);
	for(int i = 0; i < (1 << Log); i++)
		fill(ds[i], ds[i] + N, -Inf);
	
	for(int i = 0; i < n; i++) dp[1 << i][0] = 0;
	for(int i = 0; i < m; i++) ds[0][i] = 1;

	for(int mk = 0; mk < (1 << n); mk++){
		memset(mn, 31, sizeof mn);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				if(mk >> j & 1)
					mn[i] = min(mn[i], abs(x[j] - a[i]) + abs(y[j] - b[i]));
		}
		// if(mk == 4) debug(mn[1]);
		memset(m2, 31, sizeof m2);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				if(mk >> j & 1)
					m2[i] = min(m2[i], abs(x[j] - x[i]) + abs(y[j] - y[i]));
		}

		for(int cnt = 0; cnt <= m; cnt++){
			if(dp[mk][cnt] >= Inf) break;
			for(int nw = 0; nw < n; nw++)
				dp[mk | (1 << nw)][cnt] = min(dp[mk | (1 << nw)][cnt], dp[mk][cnt] + m2[nw]);
			for(int nw = 0; nw < m; nw ++)
				if(dp[mk][cnt] + mn[nw] <= t[nw])
					ds[mk][nw] = max(ds[mk][nw], cnt + 1ll);
		}
		for(int la : VV){//int la = 0; la < m; la++){
			if(ds[mk][la] < 0) continue;
			dp[mk][ ds[mk][la] ] = min(dp[mk][ ds[mk][la] ] , t[la]);
			for(int nw = 0; nw < m; nw ++)
				if(t[la] < t[nw] && t[la] + abs(a[la] - a[nw]) + abs(b[la] - b[nw]) <= t[nw])
					ds[mk][nw] = max(ds[mk][nw], ds[mk][la] + 1ll);

			for(int nw = 0; nw < m; nw ++)
				if(t[la] < t[nw] && t[la] + mn[nw] <= t[nw])
					ds[mk][nw] = max(ds[mk][nw], ds[mk][la] + 1ll);
			for(int nw = 0; nw < n; nw ++){
				dp[mk | (1 << nw)][ ds[mk][la] ] = min(dp[mk | (1 << nw)][ ds[mk][la] ], t[la] + min(abs(x[nw] - a[la]) + abs(y[nw] - b[la]), m2[nw]));
			}
		}

		// for(int cnt = 0; cnt <= m; cnt++){
		// 	if(dp[mk][cnt] >= Inf) break;
		// 	for(int nw = 0; nw < n; nw++)
		// 		dp[mk | (1 << nw)][cnt] = min(dp[mk | (1 << nw)][cnt], dp[mk][cnt] + m2[nw]);
		// 	for(int nw = 0; nw < m; nw ++)
		// 		if(dp[mk][cnt] + mn[nw] <= t[nw])
		// 			ds[mk][nw] = max(ds[mk][nw], cnt + 1ll);
		// }

		// for(int cnt = 0; cnt <= m; cnt++){
		// 	if(dp[mk][cnt] >= Inf) continue;
		// 	for(int nw = 0; nw < n; nw++)
		// 		dp[mk | (1 << nw)][cnt] = min(dp[mk | (1 << nw)][cnt], dp[mk][cnt] + m2[nw]);
		// 	for(int nw = 0; nw < m; nw ++)
		// 		if(dp[mk][cnt] + mn[nw] <= t[nw])
		// 			ds[mk][nw] = max(ds[mk][nw], cnt + 1ll);
		// }
		// for(int la : VV){//int la = 0; la < m; la++){
		// 	if(ds[mk][la] < 0) continue;
		// 	dp[mk][ ds[mk][la] ] = min(dp[mk][ ds[mk][la] ] , t[la]);
		// 	for(int nw = 0; nw < m; nw ++)
		// 		if(la != nw && t[la] + abs(a[la] - a[nw]) + abs(b[la] - b[nw]) <= t[nw])
		// 			ds[mk][la] = max(ds[mk][nw], ds[mk][la] + 1ll);

		// 	for(int nw = 0; nw < m; nw ++)
		// 		if(la != nw && t[la] + mn[nw] <= t[nw])
		// 			ds[mk][la] = max(ds[mk][nw], ds[mk][la] + 1ll);
		// }
	}
	// debug(ds[4][1]);
	// debug(dp[0][1]);
	// debug(dp[1][1]);
	// debug(dp[3][1]);
	// debug(dp[6][0]);
	for(int ans = m; ans >= 0; ans --){
		// debug(dp[(1<<n) - 1][ans]);
		if(dp[(1 << n) - 1][ans] < Inf)
			return cout << ans <<'\n', 0;
	}
	cout << 0 << '\n';
	return 0;
}