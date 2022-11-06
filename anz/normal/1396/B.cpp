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

		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}

		if (n == 1)
		{
			cout << "T\n";
			continue;
		}

		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > sum - a[i]) flag = true;
		}

		if (flag)
		{
			cout << "T\n";
			continue;
		}

		if (sum % 2 == 0) cout << "HL\n";
		else cout << "T\n";
	}
}