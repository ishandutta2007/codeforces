#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, x, m;
pii seg[101];
int res[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> x >> m;

		memset(res, 0, sizeof res);
		for (int i = 0; i < m; i++)
		{
			int l, r; cin >> l >> r;
			seg[i] = { l,r };
		}

		for (int i = 0; i < m; i++)
		{
			if (seg[i].first <= x && x <= seg[i].second)
			{
				res[i] = 1;
				continue;
			}

			for (int j = 0; j < i; j++)
			{
				if (!res[j]) continue;
 
				if (seg[i].first < seg[j].first && seg[i].second < seg[j].first
					|| seg[i].first > seg[j].second && seg[i].second > seg[j].second) continue;

				res[i] = 1;
				break;
			}
		}

		vector <pii> tmp;
		for (int i = 0; i < m; i++)
			if (res[i]) tmp.push_back(seg[i]);

		tmp.push_back({ x,x });

		sort(tmp.begin(), tmp.end());

		int ans = 0;
		int last = 0;

		for (pii it : tmp)
		{
			if (it.second <= last) continue;

			ans += it.second - max(it.first, last + 1) + 1;

			last = it.second;
		}

		cout << ans << '\n';
	}
}