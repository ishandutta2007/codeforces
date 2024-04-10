#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
ll a[200001];
int w[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < k; i++) cin >> w[i];

		sort(a, a + n);
		sort(w, w + k);
		reverse(w, w + k);

		ll ans = 0;

		int cnt = 0;
		for (int i = 0; i < k; i++)
		{
			if (w[i] == 1) break;
			ans += a[cnt];
			cnt += w[i] - 1;
		}

		reverse(w, w + k);
		for (int i = 0; i < k; i++)
		{
			if (w[i] == 1) ans += 2 * a[n - 1 - i];
			else ans += a[n - 1 - i];
		}

		cout << ans << '\n';
	}
}