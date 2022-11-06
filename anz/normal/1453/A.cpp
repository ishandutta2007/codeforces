#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int x[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> x[i];

		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			int y; cin >> y;
			bool flag = false;
			for (int i = 0; i < n; i++)
			{
				if (x[i] == y) flag = true;
			}
			if (flag) ans++;
		}

		cout << ans << '\n';
	}
}