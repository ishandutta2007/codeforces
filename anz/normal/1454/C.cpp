#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];
map <int, int> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		mp.clear();

		int last = -1;

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (i == 0)
			{
				last = a[i];
				mp[a[i]]++;
			}

			if (a[i] != last)
			{
				last = a[i];
				mp[a[i]]++;
			}
		}

		mp[a[0]]--;
		mp[a[n - 1]]--;

		int ans = 987654321;
		for (int i = 0; i < n; i++)
		{
			int res = max(0, mp[a[i]] + 1);
			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}