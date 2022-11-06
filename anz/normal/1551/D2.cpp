#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
char ans[101][101];

void printAns()
{
	if (n % 2 == 1)
	{
		k -= m / 2;
		for (int i = 0; i < m / 2; i++)
		{
			ans[n - 1][i * 2] = ans[n - 1][i * 2 + 1] =
				(i % 2 ? 'y' : 'z');
		}
	}
	else if (m % 2 == 1)
	{
		for (int i = 0; i < n / 2; i++)
		{
			ans[i * 2][m - 1] = ans[i * 2 + 1][m - 1] =
				(i % 2 ? 'y' : 'z');
		}
	}

	for (int i = 0; i < n / 2; i++) for (int j = 0; j < m / 2; j++)
	{
		if (k > 0)
		{
			k -= 2;
			ans[i * 2][j * 2] = ans[i * 2][j * 2 + 1] =
				((i + j) % 2 ? 'a' : 'c');
			ans[i * 2 + 1][j * 2] = ans[i * 2 + 1][j * 2 + 1] =
				((i + j) % 2 ? 'b' : 'd');
		}
		else
		{
			ans[i * 2][j * 2] = ans[i * 2 + 1][j * 2] =
				((i + j) % 2 ? 'e' : 'g');
			ans[i * 2][j * 2 + 1] = ans[i * 2 + 1][j * 2 + 1] =
				((i + j) % 2 ? 'f' : 'h');
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cout << ans[i][j];
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m >> k;

		bool ans = true;

		if (n % 2 == 1)
		{
			int h = m / 2;
			if (k < h) ans = false;
			if ((k - h) % 2) ans = false;
		}
		else if (m % 2 == 1)
		{
			int v = n / 2;
			int rk = n * m / 2 - k;
			if (rk < v) ans = false;
			if ((rk - v) % 2) ans = false;
		}
		else
		{
			if (k % 2) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";

		if (ans) printAns();
	}
}