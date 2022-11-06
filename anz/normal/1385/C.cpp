#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		bool flag = false;
		int ans = 0;

		for (int i = n - 2; i >= 0; i--)
		{
			if (!flag)
			{
				if (a[i] < a[i + 1])
				{
					flag = true;
				}
			}
			else
			{
				if (a[i] > a[i + 1])
				{
					ans = i + 1;
					break;
				}
			}
		}

		cout << ans << '\n';
	}
}