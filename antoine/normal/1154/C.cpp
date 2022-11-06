#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll i, ll a, ll b, ll c) {
	if (i == 1 || i == 4 || i == 7) {
		if (!a)
			return 0;
		--a;
	} else if (i == 2 || i == 6) {
		if (!b)
			return 0;
		--b;
	} else {
		if (!c)
			return 0;
		--c;
	}
	return 1 + f(i % 7 + 1, a, b, c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b, c, ans = 0;
	cin >> a >> b >> c;

	{
		const ll d = min(a / 3, min(b / 2, c / 2));
		a -= 3 * d;
		b -= 2 * d;
		c -= 2 * d;
		ans += 7 * d;
	}

	{
		ll temp = 0;
		for (int i = 1; i <= 7; ++i)
			temp = max(temp, f(i, a, b, c));
		ans += temp;
	}
	cout << ans;
	return 0;
}