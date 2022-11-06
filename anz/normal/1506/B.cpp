#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int k, n;
string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		cin >> s;

		int ans = 0;
		int last = 0;

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '*')
			{
				s[i] = 'x';
				ans++;
				last = i;
				break;
			}
		}

		while (last + k < n)
		{
			bool flag = true;

			for (int i = last + k; i > last; i--)
			{
				if (s[i] == '*')
				{
					s[i] = 'x';
					ans++;
					last = i;
					flag = false;
					break;
				}
			}

			if (flag) break;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '.') continue;
			if (s[i] == 'x') break;

			s[i] = 'x';
			ans++;
			break;
		}

		cout << ans << '\n';
	}
}