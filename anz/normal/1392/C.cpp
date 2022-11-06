#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n ;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll ans = 0;
		for (int i = n - 1; i > 0; i--)
		{
			ll d = a[i - 1] - a[i];
			if (d <= 0) continue;

			ans += d;
		}

		cout << ans << '\n';
	}
}