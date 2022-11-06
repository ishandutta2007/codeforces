#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;

int l[300001], r[300001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> s;

		for (int i = 0; i < n; i++)
		{
			if (s[i] != 'R')
			{
				r[i] = 0;
				continue;
			}

			int cur = 'R';
			int cnt = 0;

			int mx = i;
			for (; mx < n; mx++)
			{
				if (s[mx] == cur)
				{
					cnt++;
					if (cur == 'R') cur = 'L';
					else cur = 'R';
				}
				else
				{
					r[mx] = 0;
					break;
				}
			}

			for (int j = i; j < mx; j++)
			{
				if (s[j] == 'R') r[j] = cnt;
				else r[j] = 0;

				cnt--;
			}

			i = mx - 1;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] != 'L')
			{
				l[i + 1] = 0;
				continue;
			}

			int cur = 'L';
			int cnt = 0;

			int mx = i;
			for (; mx >= 0; mx--)
			{
				if (s[mx] == cur)
				{
					cnt++;
					if (cur == 'R') cur = 'L';
					else cur = 'R';
				}
				else
				{
					l[mx + 1] = 0;
					break;
				}
			}

			for (int j = i; j > mx; j--)
			{
				if (s[j] == 'L') l[j + 1] = cnt;
				else l[j + 1] = 0;

				cnt--;
			}

			i = mx + 1;
		}

		r[n] = 0;
		l[0] = 0;

		for (int i = 0; i <= n; i++)
		{
			int res = l[i] + r[i] + 1;
			cout << res << ' ';
		}

		cout << '\n';
	}
}