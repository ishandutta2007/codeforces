#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int cl, ce, v;
	cin >> cl >> ce >> v;
	vector<int> l(cl), e(ce);
	for (auto& x : l)
		cin >> x, --x;
	for (auto& x : e)
		cin >> x, --x;
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1, --y1, --x2, --y2;
		if (x1 == x2)
		{
			cout << abs(y1 - y2) << '\n';
			continue;
		}
		int ans = 1e9;
		if (y1 > y2)
			swap(y1, y2), swap(x1, x2);
		int t = (abs(x1 - x2) + v - 1) / v;
		int t1 = abs(y1 - y2);
		int i = lower_bound(e.begin(), e.end(), y1) - e.begin();
		if (i < e.size() && i >= 0)
		{
			i = e[i];
			ans = min(ans, t + abs(i - y1) + abs(i - y2));
		}
		i = upper_bound(e.begin(), e.end(), y2) - e.begin();
		--i;
		if (i < e.size() && i >= 0)
		{
			i = e[i];
			ans = min(ans, t + abs(i - y1) + abs(i - y2));
		}
		i = lower_bound(l.begin(), l.end(), y1) - l.begin();
		if (i < l.size() && i >= 0)
		{
			i = l[i];
			ans = min(ans, abs(i - y1) + abs(i - y2) + abs(x1 - x2));
		}
		i = upper_bound(l.begin(), l.end(), y2) - l.begin();
		--i;
		if (i < l.size() && i >= 0)
		{
			i = l[i]; 
			ans = min(ans, abs(i - y1) + abs(i - y2) + abs(x1 - x2));
		}
		cout << ans << '\n';
	}

	return 0;
}