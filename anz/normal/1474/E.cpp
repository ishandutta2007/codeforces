#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
vector <pii> ans;
ll a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		ans.clear();

		ll sum = 0;
		for (int i = 1; i <= n; i++) a[i] = i;

		sum += (n - 1) * (n - 1);
		ans.push_back({ 1, n });
		swap(a[1], a[n]);

		if (n % 2 == 1)
		{
			sum += (n / 2) * (n / 2);
			ans.push_back({ n / 2 + 1, 1 });
			swap(a[1], a[n / 2 + 1]);
		}

		for (int i = 0; i < n / 2 - 1; i++)
		{
			ll l, r;

			l = 1, r = n - 1 - i;
			sum += (r - l) * (r - l);
			ans.push_back({ r, l });
			swap(a[l], a[r]);

			l = 2 + i, r = n;
			sum += (r - l) * (r - l);
			ans.push_back({ l, r });
			swap(a[l], a[r]);
		}

		reverse(ans.begin(), ans.end());

		cout << sum << '\n';
		for (int i = 1; i <= n; i++) cout << a[i] << ' ';
		cout << '\n';
		cout << ans.size() << '\n';
		for (auto it : ans)
			cout << it.first << ' ' << it.second << '\n';
	}
}