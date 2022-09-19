#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 35e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[Maxn];
ll dp[Maxn][Maxn];

void MAIN(){
	ll n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	k = min(k, m - 1);
	
	ll sz = n - m + 1;
	for(int i = 1; i + sz - 1 <= n; i++) dp[i][i + sz - 1] = max(a[i], a[i + sz - 1]);
	for(int l = sz + 1; l <= n; l ++){
		for(int i = 1; i + l - 1 <= n; i++){
			int j = i + l - 1;
			dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	ll ans = 1;
	for(int i = 0; i <= k; i++){
		ans = max(ans, dp[i + 1][n - (k - i)]);
	}
	cout << ans << '\n';
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	while(n--) MAIN();
	
	
	return 0;
}