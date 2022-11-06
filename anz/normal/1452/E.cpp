#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m, k;
int l[2001], r[2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		cin >> l[i] >> r[i];
	}

	int ans = 0;

	for (int cl = 1; cl + k - 1 <= n; cl++)
	{
		int cr = cl + k - 1;
		vector <pair<int, pii> > vec;

		int cur = 0;
		int res = 0;

		for (int i = 0; i < m; i++)
		{
			int cc = max(0, min(cr, r[i]) - max(cl, l[i]) + 1);
			cur += cc;

			if (l[i] <= cl || r[i] <= cr) continue;

			int si = max(cl, l[i] - k);
			vec.push_back({ si,{1,-1} });

			int nl = r[i] - k + 1, nr = l[i];
			if (nl > nr) swap(nl, nr);

			vec.push_back({ nl,{-1,1} });

			vec.push_back({ nr, {-1,1} });

			int ei = min(r[i] + 1, r[i] - (cr - l[i]));

			vec.push_back({ ei, {1,-1} });
		}

		sort(vec.begin(), vec.end());
		int d = 0;
		int p = 0;

		res = cur;

		for (int i = cl; i + k - 1 <= n; i++)
		{
			while (p < vec.size() && vec[p].first == i)
			{
				d += vec[p].second.first;
				cur += vec[p].second.second;
				p++;
			}

			cur += d;
			res = max(res, cur);
		}

		ans = max(ans, res);
	}

	cout << ans;
}