#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

const ll maxn = 4e5 + 10;
const ll inf = 1e9;

ll a[maxn];

int main(){
	ios_base::sync_with_stdio (false);
	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll lo = a[n / 2], hi = a[n / 2] + k + 1;
	while (hi - lo > 1){
		ll mid = (lo + hi) >> 1;
		ll sum = 0;
		for (ll j = n / 2; j < n; j++)
			sum += max(0ll, mid - a[j]);
		if (sum <= k)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << endl;
}