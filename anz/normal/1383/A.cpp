#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string a, b;

int cnt[20][20];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> a >> b;

		memset(cnt, 0, sizeof cnt);

		bool hasAns = true;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > b[i]) hasAns = false;
			int i1 = a[i] - 'a';
			int i2 = b[i] - 'a';

			cnt[i1][i2]++;
		}

		if (!hasAns)
		{
			cout << "-1\n";
			continue;
		}

		int ans = 0;
		for (int i = 0; i < 19; i++)
		{
			int mn = 20;
			for (int j = i + 1; j < 20; j++)
			{
				if (cnt[i][j]) mn = min(mn, j);
			}

			if (mn == 20) continue;
			ans++;

			int d = mn - i;
			for (int j = i + 1; j < 20; j++)
			{
				cnt[i + d][j] += cnt[i][j];
			}
		}

		cout << ans << '\n';
	}
}