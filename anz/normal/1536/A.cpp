#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		bool ans = true;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] < 0) ans = false;
		}

		if (!ans)
		{
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		cout << "101\n";
		for (int i = 0; i <= 100; i++) cout << i << ' ';
		cout << '\n';
	}
}