#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[41];

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		set <int> st;

		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
		{
			int d = abs(a[i] - a[j]);
			for (int k = 1; k * k <= d; k++)
			{
				if (d % k == 0)
				{
					st.insert(k);
					st.insert(d / k);
				}
			}
		}

		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			for (int k = 0; k < n; k++)
			{
				if (a[i] == a[k]) cnt++;
			}

			if (cnt >= n / 2)
			{
				ans = INF;
				break;
			}

			for (int x : st)
			{
				int cnt = 0;
				for (int k = 0; k < n; k++)
				{
					if (abs(a[i] - a[k]) % x == 0) cnt++;
				}

				if (cnt >= n / 2)
				{
					ans = max(ans, x);
				}
			}
		}

		if (ans == INF) ans = -1;
		cout << ans << '\n';
	}
}