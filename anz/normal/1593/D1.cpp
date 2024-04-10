#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[41];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll ans = 0;
		for (int i = 1; i < n; i++)
			ans = gcd(ans, llabs(a[i] - a[i - 1]));

		if (ans == 0) ans = -1;
		cout << ans << '\n';
	}
}