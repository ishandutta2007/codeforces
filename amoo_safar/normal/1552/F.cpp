// Doooop !
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

const ll Mod = 998244353ll;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


int x[N], y[N], s[N];
ll dp[N];
ll ps[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> s[i];

	for(int i = 0; i < n; i++){
		int idx = lower_bound(x, x + n, y[i]) - x;
		if(idx == i){
			dp[i] = x[i] - y[i];
		} else {
			dp[i] = x[i] - y[i] + ps[i] - ps[idx];
		}
		dp[i] %= Mod;
		ps[i + 1] = ps[i] + dp[i];
	}
	ll ans = x[n - 1] + 1;
	for(int i = 0; i < n; i++) ans += s[i] * dp[i];
	cout << ans % Mod << '\n';
	return 0;
}