#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
vector <int> a[2];
vector <int> b[2];

vector <int> mt[2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		a[0].clear(); a[1].clear();
		b[0].clear(); b[1].clear();
		mt[0].clear(); mt[1].clear();

		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			if (x < 0) a[0].push_back(-x);
			else a[1].push_back(x);
		}

		reverse(a[0].begin(), a[0].end());

		for (int i = 0; i < m; i++)
		{
			int x; cin >> x;
			if (x < 0) b[0].push_back(-x);
			else b[1].push_back(x);
		}

		reverse(b[0].begin(), b[0].end());

		for (int k = 0; k < 2; k++)
		{
			for (int x : a[k])
			{
				if (binary_search(b[k].begin(), b[k].end(), x))
					mt[k].push_back(x);
			}

			for (int i = 0; i < a[k].size(); i++) a[k][i] -= i;
		}

		int ans = 0;
		for (int k = 0; k < 2; k++)
		{
			int res = 0;

			int cur = 0;
			int aptr = 0, bptr = 0;
			int cbox = 0;

			while (aptr < a[k].size() || bptr < b[k].size())
			{
				if (aptr < a[k].size())
				{
					if (bptr < b[k].size())
					{
						if (a[k][aptr] <= b[k][bptr])
						{
							cur = a[k][aptr];
							aptr++;
							cbox++;
						}
						else
						{
							cur = b[k][bptr];
							bptr++;
						}
					}
					else
					{
						cur = a[k][aptr];
						aptr++;
						cbox++;
					}
				}
				else
				{
					cur = b[k][bptr];
					bptr++;
				}

				int t1 = lower_bound(b[k].begin(), b[k].end(), cur + cbox)
					- lower_bound(b[k].begin(), b[k].end(), cur);
				int t2 = (int)mt[k].size()
					- (lower_bound(mt[k].begin(), mt[k].end(), cur + cbox) - mt[k].begin());

				res = max(res, t1 + t2);
			}

			ans += res;
		}

		cout << ans << '\n';

	}

	return 0;
}