#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;

		int ans = 0;
		for (int i = 0; i < k / 2; i++)
		{
			map <int, int> mp;
			for (int j = 0; j < n / k; j++)
			{
				mp[s[j * k + i]]++;
				mp[s[(j + 1) * k - 1 - i]]++;
			}

			int mx = 0;
			for (auto it : mp) mx = max(mx, it.second);
			ans += (n / k * 2) - mx;
		}

		if (k % 2)
		{
			map <int, int> mp;
			for (int j = 0; j < n / k; j++)
			{
				mp[s[j * k + k / 2]]++;
			}

			int mx = 0;
			for (auto it : mp) mx = max(mx, it.second);
			ans += (n / k) - mx;
		}

		cout << ans << '\n';
	}
}