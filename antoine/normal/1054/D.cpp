#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[(int) 2e5 + 9];
int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] ^= a[i - 1];
	}

	const int full = (1 << k) - 1;
	ll ansC = 0;
	map<int, ll> occ = {{0, 1}};
	for(int i = 1; i <= n; ++i) {
		if(occ[a[i] ^ full] < occ[a[i]])
			a[i] ^= full;
		ansC += occ[a[i]]++;
	}
	ll ans = (ll)n*(ll)(n+1)/2 - ansC;
	cout << ans;
	return 0;
}