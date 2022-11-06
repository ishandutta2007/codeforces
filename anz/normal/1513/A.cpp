#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;

		if (k > (n - 1) / 2)
		{
			cout << "-1\n";
			continue;
		}

		for (int i = 0; i < k; i++)
			cout << i + 1 << ' ' << n - i << ' ';
		for (int i = k; i < n - k; i++)
			cout << i + 1 << ' ';
		cout << '\n';
	}
}