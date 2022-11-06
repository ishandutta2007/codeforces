#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;

		bool flag = false;
		for (int i = n % 10; i < 10; i++)
		{
			int nn = n / 10 * 10 + i;
			if (nn % 7 == 0)
			{
				flag = true;
				cout << nn << '\n';
				break;
			}
		}

		if (!flag)
		{
			for (int i = n % 10; i >= 0; i--)
			{
				int nn = n / 10 * 10 + i;
				if (nn % 7 == 0)
				{
					flag = true;
					cout << nn << '\n';
					break;
				}
			}
		}
	}
}