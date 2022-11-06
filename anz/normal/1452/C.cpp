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
		int ans = 0;

		int c1 = 0, c2 = 0;
		for (char c : s)
		{
			if (c == '(') c1++;
			else if (c == '[') c2++;
			else if (c == ')')
			{
				if (c1)
				{
					ans++;
					c1--;
				}
			}
			else if (c == ']')
			{
				if (c2)
				{
					ans++;
					c2--;
				}
			}
		}

		cout << ans << '\n';
	}
}