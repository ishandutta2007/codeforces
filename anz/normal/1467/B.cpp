#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[300001];

bool isHill(int x)
{
	if (x <= 0 || x >= n - 1) return false;
	if (a[x - 1] < a[x] && a[x] > a[x + 1]) return true;
	if (a[x - 1] > a[x] && a[x] < a[x + 1]) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (isHill(i)) ans++;
		}

		int res = ans;

		for (int i = 0; i < n; i++)
		{
			int org = a[i];

			if (i - 1 >= 0)
			{
				int cnt1 = 0, cnt2 = 0;
				for (int d = -1; d <= 1; d++)
				{
					if (isHill(i + d)) cnt1++;
				}

				a[i] = a[i - 1];
				
				for (int d = -1; d <= 1; d++)
				{
					if (isHill(i + d)) cnt2++;
				}

				ans = min(ans, res - cnt1 + cnt2);

				a[i] = org;
			}
			
			if (i + 1 < n)
			{
				int cnt1 = 0, cnt2 = 0;
				for (int d = -1; d <= 1; d++)
				{
					if (isHill(i + d)) cnt1++;
				}

				a[i] = a[i + 1];

				for (int d = -1; d <= 1; d++)
				{
					if (isHill(i + d)) cnt2++;
				}

				ans = min(ans, res - cnt1 + cnt2);

				a[i] = org;
			}
		}

		cout << ans << '\n';
	}
}