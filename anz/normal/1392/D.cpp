#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
string s;
vector <int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> s;

		v.clear();

		bool flag = false;
		int st = 0;
		for (st; st < n; st++)
		{
			if (s[st] != s[(st + 1) % n])
			{
				flag = true;
				st++;
				break;
			}
		}

		if (!flag)
		{
			cout << (n - 1) / 3 + 1 << '\n';
		}
		else
		{
			int cnt = 1;
			for (int i = 0; i < n - 1; i++)
			{
				if (s[(st + i) % n] != s[(st + i + 1) % n])
				{
					v.push_back(cnt);
					cnt = 1;
				}
				else cnt++;
			}
			v.push_back(cnt);

			int ans = 0;
			for (int x : v)
				ans += x / 3;
			
			cout << ans << '\n';
		}
	}
}