#include <bits/stdc++.h>
 
using namespace std;

#define F first
#define S second 
#define pb push_back
#define mk make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
ll const inf = 1'000'000'000'000'000;
ll const mod = 1'000'000'007;
ll const max_n = 100'000 + 10;
ll a[max_n];


int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	for (ll i = 0; i < m; ++i) {
		cin >> a[i];
	}
	ll sum = 0;
	ll ans = 0;
	ll cur = 0;
	while (cur < m) {
		ll r = ((a[cur] - sum - 1) / k + 1) * k + sum;
		while (cur < m && a[cur] <= r) {
			++sum;
			++cur;
		}
		++ans;
	}
	cout << ans << '\n';
	return 0;
}