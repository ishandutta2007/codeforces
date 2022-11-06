#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
map <pii, char> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	int lp_same = 0;
	int lp_dif = 0;

	for (int i = 0; i < m; i++)
	{
		char q; cin >> q;
		if (q == '+')
		{
			int u, v; cin >> u >> v;
			char c; cin >> c;

			mp[{u, v}] = c;
			if (mp.count({ v,u }))
			{
				if (mp[{v, u}] == c) lp_same++;
				else lp_dif++;
			}
		}
		else if (q == '-')
		{
			int u, v; cin >> u >> v;
			char c = mp[{u, v}];

			mp.erase({ u,v });
			if (mp.count({ v,u }))
			{
				if (mp[{v, u}] == c) lp_same--;
				else lp_dif--;
			}
		}
		else
		{
			int k; cin >> k;
			if (k % 2)
			{
				if (lp_same + lp_dif) cout << "YES\n";
				else cout << "NO\n";
			}
			else
			{
				if (lp_same) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}