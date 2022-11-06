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
		int n; cin >> n;
		string s; cin >> s;
		string ans1, ans2;

		bool bigger = false;
		for (auto c : s)
		{
			if (bigger) ans1 += '0', ans2 += c;
			else
			{
				if (c == '0') ans1 += '0', ans2 += '0';
				else if (c == '2') ans1 += '1', ans2 += '1';
				else
				{
					bigger = true;
					ans1 += '1';
					ans2 += '0';
				}
			}
		}

		cout << ans1 << '\n' << ans2 << '\n';
	}
}