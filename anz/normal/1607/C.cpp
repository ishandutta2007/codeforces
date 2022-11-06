#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a, a + n);

		ll p = 0;

		ll ans = a[0];

		for (int i = 0; i + 1 < n; i++)
		{
			p -= a[i] + p;
			ans = max(ans, a[i + 1] + p);
		}

		//cout << "ANS: ";
		cout << ans << '\n';
	}
}