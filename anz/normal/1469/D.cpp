#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
vector <pii> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		ans.clear();

		int cur = n;
		int ptr = n - 1;
		while (ptr > 2)
		{
			int sq = max(2.0, sqrt(cur));
			for (int i = sq + 1; i <= ptr; i++)
			{
				ans.push_back({ i, n });
			}

			ans.push_back({ n, sq });
			cur = cur / sq + (cur % sq ? 1 : 0);

			ptr = sq;
		}

		while (cur > 1)
		{
			ans.push_back({ n, 2 });
			cur = cur / 2 + (cur % 2 ? 1 : 0);
		}

		cout << ans.size() << '\n';
		for (auto it : ans)
			cout << it.first << ' ' << it.second << '\n';
	}
}