#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> p(n + 1, 0);
	for (int i = 2; i <= n; ++i)
		cin >> p[i];

	vector<ll> s(n + 1);

	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	const int Inf = (int) 1e9 + 9;

	vector<ll> mn(n + 1, Inf);
	for (int i = n; i >= 2; --i) {
		if (s[i] != -1)
			mn[p[i]] = min(mn[p[i]], s[i]);
		mn[p[i]] = min(mn[p[i]], mn[i]);
	}

	for (int i = 1; i <= n; ++i)
		if (s[i] != -1 && mn[i] < s[i]) {
			cout << -1;
			return 0;
		}

	for (int i = 2; i <= n; ++i) {
		if (s[i] == -1) {
			if (mn[i] == Inf)
				s[i] = s[p[i]];
			else
				s[i] = mn[i];
		}
	}


	ll ans = s[1];
	for(int i = 2; i <= n; ++i)
		ans += s[i] - s[p[i]];

	cout << ans;
	return 0;
}