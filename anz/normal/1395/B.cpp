#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, sx, sy;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> sx >> sy;
	cout << sx << ' ' << sy << '\n';

	for (int i = 1; i <= m; i++)
	{
		if (i == sy) continue;
		cout << sx << ' ' << i << '\n';
	}

	for (int i = m; i >= 1; i--)
	{
		if (i % 2)
		{
			for (int j = 1; j <= n; j++)
			{
				if (j == sx) continue;
				cout << j << ' ' << i << '\n';
			}
		}
		else
		{
			for (int j = n; j >= 1; j--)
			{
				if (j == sx) continue;
				cout << j << ' ' << i << '\n';
			}
		}
	}
}