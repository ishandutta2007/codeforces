#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int k, n;
int c[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> c[i];

		int ans = 987654321;
		for (int cl = 1; cl <= 100; cl++)
		{
			int res = 0;

			int idx = 0;
			while (idx < n)
			{
				if (c[idx] == cl)
				{
					idx++;
					continue;
				}
				else
				{
					idx += k;
					res++;
				}
			}

			ans = min(ans, res);
		}

		cout << ans << '\n';
	}
}