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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[N];

int a[N];
map<ll, ll> mp;

int Main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	ll ans = n;
	vector<ll> V;
	V.pb(a[1]);
	for(int i = 2; i <= n; i++)
		if(a[i] != a[i - 1])
			V.pb(a[i]);
	int m = V.size();
	ans = m;

	mp[V[0]] = 0;
	ll mn = Inf;
	for(int i = 1; i < m; i++){
		dp[i] = i + 1;
		if(mp.count(V[i])){
			int idx = mp[V[i]];
			dp[i] = min(dp[i], dp[idx + 1] + (i - (idx + 1) - 1));
		}
		dp[i] = min(dp[i], i + mn);
		mn = min(mn, dp[i] - i);
		ans = min(ans, dp[i] + (m - 1) - i);
		mp[V[i]] = i;
	}
	cout << ans << '\n';
	
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	// cin >> T;
	while(T --) Main();
	return 0;
}