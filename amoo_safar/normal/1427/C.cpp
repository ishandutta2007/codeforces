// I'll Crush you !
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

ll x[N], y[N], t[N];
ll dp[N], mx[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, r;
	cin >> r >> n;
	for(int i = 1; i <= n; i++) cin >> t[i] >> x[i] >> y[i];
	x[0] = 1; y[0] = 1; t[0] = 0;
	fill(dp, dp + N, -Inf);
	dp[0] = 0; mx[0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = max(0ll, i - r - r); j < i; j++){
			if(t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])){
				dp[i] = max(dp[i], dp[j] + 1);
				//cerr << "! " << i << ' ' << j << '\n';
			}
		}
		if(i >= r + r) dp[i] = max(dp[i], mx[i - r - r] + 1);
		mx[i] = max(mx[i - 1], dp[i]);
		//cerr << i << ' ' << dp[i] << '\n';
	}
	cout << *max_element(dp, dp + N) << '\n';
	return 0;
}