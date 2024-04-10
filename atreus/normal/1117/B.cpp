/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
ll a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll fmx = a[n], smx = a[n - 1];
	if (k == m)
		return cout << 1ll * fmx * k << endl, 0;
	ll answer = 1ll * (m / (k + 1)) * (1ll * k * fmx + smx);
	m %= (k + 1);
	answer += m * fmx;
	cout << answer << endl;
}