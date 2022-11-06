#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
int a[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;

		bool isValid = false;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == k) isValid = true;
		}
		a[n] = 0;

		if (!isValid)
		{
			cout << "no\n";
			continue;
		}

		if (n == 1)
		{
			cout << "yes\n";
			continue;
		}

		bool ans = false;
		for (int i = 0; i < n - 1; i++)
		{
			int cnt = 0;
			for (int j = i; j < i + 3; j++)
			{
				if (a[j] >= k) cnt++;
			}

			if (cnt >= 2) ans = true;
		}

		if (ans) cout << "yes\n";
		else cout << "no\n";
	}
}