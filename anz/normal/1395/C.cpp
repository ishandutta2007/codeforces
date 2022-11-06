#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int a[201], b[201];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	for (int ans = 0; ans < (1 << 9); ans++)
	{
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			bool res = false;
			for (int j = 0; j < m; j++)
			{
				if ((a[i] & b[j] | ans) == ans)
				{
					res = true;
					break;
				}
			}

			if (!res)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			cout << ans;
			return 0;
		}
	}
}