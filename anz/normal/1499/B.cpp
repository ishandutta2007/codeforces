#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> s;

		bool ans = false;
		for (int k = 0; k <= s.size(); k++)
		{
			int last = -123;

			bool flag = true;
			for (int i = 0; i < s.size(); i++)
			{
				if (k > i)
				{
					if (s[i] == '1')
					{
						if (last + 1 >= i) flag = false;
						last = i;
					}
				}
				else
				{
					if (s[i] == '0')
					{
						if (last + 1 >= i) flag = false;
						last = i;
					}
				}
			}

			if (flag) ans = true;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}