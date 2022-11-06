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
		string s; cin >> s;
		ll ans = 0;
		int cur = 0;
		int mn = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char c = s[i];
			if (c == '+') cur++;
			else cur--;
			if (mn > cur)
			{
				mn = cur;
				ans += i + 1;
			}
		}
		ans += s.size();
		cout << ans << '\n';
	}
}