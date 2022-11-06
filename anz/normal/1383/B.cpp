#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int cnt[31];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		memset(cnt, 0, sizeof cnt);

		for (int i = 0; i < n; i++)
		{
			int a; cin >> a;
			for (int j = 0; j < 30; j++)
			{
				if (a & (1 << j)) cnt[j]++;
			}
		}

		int ans = 1;

		for (int i = 29; i >= 0; i--)
		{
			if (n % 2 == 0)
			{
				if (cnt[i] % 2 == 1)
				{
					ans = 0;
					break;
				}
			}
			else
			{
				if (cnt[i] % 2 == 1)
				{
					if (cnt[i] / 2 % 2 == 0) ans = 0;
					else ans = 2;
					break;
				}
			}
		}

		if (ans == 0) cout << "WIN\n";
		else if (ans == 1) cout << "DRAW\n";
		else cout << "LOSE\n";
	}
}