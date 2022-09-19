// That's How much we have in common
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
const int N = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];
ll s2[N];
ll s1[N], H[N], dp[N];
ll n, r1, r2, r3, d;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> r1 >> r2 >> r3 >> d;
	r1 = min(r1, r3);	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		s1[i] = a[i] * r1 + r3;
		s1[i] = min(s1[i], min({r2, (a[i] + 1) * r1}) + d + d + min({r1, r2, r3}));
	}
	ll c1, c2, h1, h2;
	for(int i = 1; i + 1 <= n; i++){
		c1 = s1[i]; c2 = s1[i + 1];
		h1 = min({r2, (a[i] + 1) * r1}) + min({r1, r2, r3});
		h2 = min({r2, (a[i + 1] + 1) * r1}) + min({r1, r2, r3});
		H[i] = h1; H[i + 1] = h2;
		s2[i] = min(c1, h1) + min(c2, h2) + 2 * d;
	}
	dp[0] = 0;
	dp[1] = s1[1];
	for(int i = 2; i <= n; i++)
		dp[i] = min(dp[i - 1] + s1[i], dp[i - 2] + s2[i - 1]);

	ll ans = min({dp[n - 1] + s1[n], dp[n - 2] + s2[n - 1], dp[n - 2] + H[n - 1] + s1[n] + d});
	cout << ans + (n - 1) * d << '\n';
	return 0;
}