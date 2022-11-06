#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		int cur; cin >> cur;
		int ans = 0;

		for (int i = 1; i < n; i++)
		{
			int a; cin >> a;
			if (cur < a)
			{
				while (cur * 2 < a)
				{
					cur *= 2;
					ans++;
				}

				cur = a;
			}
			else
			{
				int tmp = a;
				swap(cur, a);

				while (cur * 2 < a)
				{
					cur *= 2;
					ans++;
				}

				cur = tmp;
			}
		}

		cout << ans << '\n';
	}
}