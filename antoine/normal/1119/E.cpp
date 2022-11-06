#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<ll> a(n + 9, 0);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	ll ans = 0;

	for (int i = n, j = n; i >= 1; --i) {
		if (a[i] & 1) {
			a[i]--;
			while (i <= j && a[j] == 0)
				--j;
			if (i <= j) {
				assert(a[j] >= 2);
				a[j] -= 2;
				ans++;
			}
		}
	}

	int i = 1, j = n;
	while (i < j) {
		const ll d = min(a[i], a[j] / 2);
		a[i] -= d, a[j] -= 2 * d;
		ans += d;
		if (!a[i])
			i++;
		else if (!a[j])
			j--;
	}
	ans += a[i] / 3;
	cout << ans;
	return 0;
}