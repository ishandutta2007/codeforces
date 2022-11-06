#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];
int psum[201][200001];
vector <int> idx[201];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		for (int k = 1; k <= 200; k++) idx[k].clear();

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			idx[a[i]].push_back(i);
			for (int k = 1; k <= 200; k++)
			{
				if (a[i] == k) psum[k][i] = psum[k][i - 1] + 1;
				else psum[k][i] = psum[k][i - 1];
			}
		}

		int ans = 0;
		for (int k = 1; k <= 200; k++)
		{
			ans = max(ans, (int)idx[k].size());
			if (idx[k].size() < 2) continue;

			for (int i = 0; i < idx[k].size() / 2; i++)
			{
				int idx_front = idx[k][i];
				int idx_back = idx[k][idx[k].size() - 1 - i];

				int mid_max = 0;
				for (int j = 1; j <= 200; j++)
				{
					int res = psum[j][idx_back - 1] - psum[j][idx_front];
					mid_max = max(mid_max, res);
				}

				ans = max(ans, mid_max + (i + 1) * 2);
			}
		}

		cout << ans << '\n';
	}
}