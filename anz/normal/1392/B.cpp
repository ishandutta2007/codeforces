#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
ll a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];

		ll mx_val = *max_element(a, a + n);
		ll mn_val = *min_element(a, a + n);

		if (k % 2)
		{
			for (int i = 0; i < n; i++) cout << (mx_val - mn_val) - (a[i] - mn_val) << ' ';
			cout << '\n';
		}
		else
		{
			for (int i = 0; i < n; i++) cout << a[i] - mn_val << ' ';
			cout << '\n';
		}
	}
}