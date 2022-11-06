#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ex[4][4] = {
{4,3,6,12},
{7,5,9,15},
{14,1,11,10},
{13,8,16,2}
};

int ans[501][501];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	if (n < 3)
	{
		cout << -1;
		return 0;
	}

	if (n == 3)
	{
		cout << "1 2 4\n";
		cout << "5 3 8\n";
		cout << "9 6 7\n";
		return 0;
	}

	if (n == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << ex[i][j] << ' ';
			cout << '\n';
		}
		return 0;
	}

	int num = 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n - 4; j++)
			{
				ans[n - 1 - i][j] = num++;
			}
		}
		else
		{
			for (int j = n - 5; j >= 0; j--)
			{
				ans[n - 1 - i][j] = num++;
			}
		}
	}

	for (int i = 0; i < n - 5; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = n - 4; j < n; j++)
			{
				ans[i][j] = num++;
			}
		}
		else
		{
			for (int j = n - 1; j >= n - 4; j--)
			{
				ans[i][j] = num++;
			}
		}
	}

	if (n % 2 == 1)
	{
		ans[n - 5][n - 4] = num++;
		ans[n - 5][n - 1] = num++;
		ans[n - 5][n - 2] = num++;
		ans[n - 5][n - 3] = num++;
	}
	else
	{
		ans[n - 5][n - 1] = num++;
		ans[n - 5][n - 4] = num++;
		ans[n - 5][n - 2] = num++;
		ans[n - 5][n - 3] = num++;
	}

	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++)
	{
		ans[n - 4 + i][n - 4 + j] = num - 1 + ex[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}