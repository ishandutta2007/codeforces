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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, k;

ll ps[N], a[N], d[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	k = min(2ll, k);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> d[i];
	ll ans = max(0ll, a[n] - d[n]);
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];
	if(k == 0){
		for(int i = 1; i <= n; i++)
			ans = max(ans, (ps[n] - ps[i - 1]) - d[i]);
	}
	if(k == 2){
		for(int i = 1; i < n; i++)
			ans = max(ans, ps[n] - d[i]);
	}
	if(k == 1){
		for(int i = 2; i < n; i++)
			ans = max(ans, (ps[n] - a[i]) - d[1]);
		for(int i = 2; i < n; i++)
			ans = max(ans, (ps[n] - ps[i - 1]) - d[i]);
		
		ll res = -(*min_element(d + 1, d + n));
		for(int i = 1; i < n; i++) res += a[i];
		ans = max(ans, res);
		
		sort(d + 1, d + n + 1);
		res = -(d[1] + d[2]);

		for(int i = 1; i <= n; i++)
			res += a[i];
		ans = max(ans, res);
	}
	cout << ans << '\n';
	return 0;
}