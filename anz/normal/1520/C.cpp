#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ans[101][101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		if (n == 1)
		{
			cout << "1\n";
			continue;
		}
		else if (n == 2)
		{
			cout << "-1\n";
			continue;
		}

		int cur = 1;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		{
			if ((i + j) % 2 == 0) ans[i][j] = cur++;
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		{
			if ((i + j) % 2 == 1) ans[i][j] = cur++;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
			cout << '\n';
		}
	}
}