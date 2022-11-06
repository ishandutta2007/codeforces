#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[501];
int b[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		int ta[501], tb[501];
		memcpy(ta, a, sizeof a);
		memcpy(tb, b, sizeof b);

		sort(ta, ta + n);
		sort(tb, tb + n);

		bool ans = true;
		for (int i = 0; i < n; i++)
		{
			if (ta[i] != tb[i]) ans = false;
		}

		if (n % 2 && a[n / 2] != b[n / 2]) ans = false;

		bool cache[501] = { 0, };
		for (int i = 0; i < n / 2; i++)
		{
			bool flag = false;
			for (int j = 0; j < n; j++)
			{
				if (n % 2 && j == n / 2) continue;

				if (cache[j]) continue;
				if (a[i] == b[j] && a[n - 1 - i] == b[n - 1 - j])
				{
					cache[j] = cache[n - 1 - j] = 1;
					flag = true;
					break;
				}
			}

			if (!flag) ans = false;
		}

		if (ans) cout << "Yes\n";
		else cout << "No\n";
	}
}