#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	ll ans = 1;
	for (const char c : set<char> { s[0], s.back() }) {
		ll i = 0, j = n - 1;
		while (s[i] == c)
			++i;
		while (s[j] == c)
			--j;
		ans += (i + 1) * (n - j) - 1;
	}
	cout << ans % 998244353;
	return 0;
}