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

	int t; cin >> t;
	while (t--)
	{
		int n0, n1, n2; cin >> n0 >> n1 >> n2;

		string ans;

		if (n0)
		{
			ans += '0';
			for (int i = 0; i < n0; i++) ans += '0';
		}

		if (n2)
		{
			if (!ans.empty()) n1--;
			ans += '1';
			for (int i = 0; i < n2; i++) ans += '1';
		}

		if (n1)
		{
			if (ans.empty()) ans += '0';

			for (int i = 0; i < n1; i++)
			{
				if (ans.back() == '0') ans += '1';
				else ans += '0';
			}
		}

		cout << ans << '\n';
	}
}