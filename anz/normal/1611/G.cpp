#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
set <int> st[2000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < n + m; i++) st[i].clear();

		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			for (int j = 0; j < m; j++)
			{
				if (s[j] == '1') st[i + j].insert(i);
			}
		}

		int ans = 0;
		for (int i = 0; i < n + m; i++)
		{
			int idx = i;
			if (st[idx].size() == 0) continue;

			ans++;
			int x = *prev(st[idx].end());
			int y = i - x;

			st[idx].clear();

			while (true)
			{
				x++, y++;
				if (x >= n) break;

				int nx = x, ny = y;
				while (true)
				{
					auto it = st[x + y].lower_bound(x);
					if (it == st[x + y].end()) break;
					nx = *it;
					ny = x + y - nx;

					st[x + y].erase(it);
				}

				x = nx, y = ny;
			}
		}

		cout << ans << '\n';
	}
}