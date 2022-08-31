#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
	freopen("a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> x(n);
	ll s = 0;
	int mn = 1e9, mx = -1e9;
	map <int, int> cnt;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		cnt[x[i]]++;
		s += x[i];
		mn = min(mn, x[i]);
		mx = max(mx, x[i]);
	}
	if (mn == mx)
	{
		cout << n << '\n';
		for (int i = 0; i < n; i++)
		{
			cout << x[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		if (mn == mx - 1)
		{
			int ans = 1e9;
			int grab = -1;
			for (int c = 0; c <= n; c++)
			{
				int ret = min(c, cnt[mn]) + min(n - c, cnt[mx]);
				if (mn * (ll) c + mx * (ll) (n - c) == s && ret < ans)
				{
					ans = ret;
					grab = c;
				}
			}
			cout << ans << '\n';
			for (int i = 0; i < grab; i++) cout << mn << ' ';
			for (int i = 0; i < n - grab; i++) cout << mx << ' ';
			cout << '\n';
		}
		else
		{
			int ans = 1e9;
			int grab_x = 0;
			int grab_y = 0;
			for (int c = 0; c <= n; c++)
			{
				int need = n - c;
				ll b = s - c * (ll) mn - need * (ll) (mn + 1);
				ll a = n - c - b;
				if (a >= 0 && b >= 0 && c >= 0)
				{
					int ret = min(c, cnt[mn]) + min((int) a, cnt[mn + 1]) + min((int) b, cnt[mx]);
					if (ret < ans)
					{
						ans = ret;
						grab_x = c;
						grab_y = a;
					}
				}
			}
			cout << ans << '\n';
			for (int i = 0; i < grab_x; i++) cout << mn << ' ';
			for (int i = 0; i < grab_y; i++) cout << mn + 1 << ' ';
			for (int i = 0; i < n - grab_x - grab_y; i++) cout << mn + 2 << ' ';
			cout << '\n';
		}
	}
}