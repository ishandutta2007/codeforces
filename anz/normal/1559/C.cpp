#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];

		bool ans = false;
		if (a[1] == 1)
		{
			ans = true;

			cout << n + 1 << ' ';
			for (int i = 1; i <= n; i++) cout << i << ' ';
			cout << '\n';
		}
		else if (a[n] == 0)
		{
			ans = true;

			for (int i = 1; i <= n + 1; i++) cout << i << ' ';
			cout << '\n';
		}
		else
		{
			for (int i = 1; i < n; i++)
			{
				if (a[i] == 0 && a[i + 1] == 1)
				{
					ans = true;

					for (int j = 1; j <= i; j++) cout << j << ' ';
					cout << n + 1 << ' ';
					for (int j = i + 1; j <= n; j++) cout << j << ' ';
					cout << '\n';

					break;
				}
			}
		}

		if (!ans)
		{
			cout << "-1\n";
		}
	}
}