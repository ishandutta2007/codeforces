#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;

pii a[300001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		cin >> n >> k;
		for (int i = 0; i < k; i++) cin >> a[i].first;
		for (int i = 0; i < k; i++) cin >> a[i].second;

		sort(a, a + k);

		vector <pii> stk;
		stk.push_back(a[0]);

		for (int i = 1; i < k; i++)
		{
			if (a[i].first - stk.back().first
				<= a[i].second - stk.back().second)
				continue;

			while (!stk.empty() &&
				a[i].first - stk.back().first
				<= stk.back().second - a[i].second)
				stk.pop_back();

			stk.push_back(a[i]);
		}

		for (int v = 1; v <= stk[0].first; v++)
			cout << stk[0].second + stk[0].first - v << ' ';

		for (int i = 0; i + 1 < stk.size(); i++)
		{
			for (int v = stk[i].first + 1; v <= stk[i + 1].first; v++)
			{
				int r1 = stk[i].second + v - stk[i].first;
				int r2 = stk[i + 1].second + stk[i + 1].first - v;

				cout << min(r1, r2) << ' ';
			}
		}

		for (int v = stk.back().first + 1; v <= n; v++)
			cout << stk.back().second + v - stk.back().first << ' ';

		cout << '\n';
	}
}