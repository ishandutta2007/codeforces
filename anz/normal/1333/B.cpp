#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[100001];
int b[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];

		int m1 = 0, p1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 1) p1++;
			if (a[i] == -1) m1++;
		}

		bool ans = true;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] == 1) p1--;
			if (a[i] == -1) m1--;

			if (a[i] == b[i]) continue;

			if (a[i] > b[i])
			{
				if (m1 <= 0)
				{
					ans = false;
					break;
				}
			}
			else
			{
				if (p1 <= 0)
				{
					ans = false;
					break;
				}
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}