#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	const int MX = 1000001;
	vector<int> mn(MX, -1);
	iota(mn.begin(), mn.end(), 0);
	vector<int> pr;
	for (int i = 2; i < MX; ++i)
	{
		if (mn[i] == i)
			pr.push_back(i);
		for (int j : pr)
		{
			if (i * j >= MX || j > mn[i])
				break;
			mn[i * j] = j;

		}
	}
	int x;
	cin >> x;
	vector<int> p2;
	int y = x;
	while (y != mn[y])
		y /= mn[y];
	int from = x - y + 1;
	if (y == x)
		from = x;
	int to = x;
	int ans = x;
	//cerr << from << ' ' << to << '\n';
	for (int i = from; i <= to; ++i)
	{
		int j = i;
		while (j != mn[j])
			j /= mn[j];
		//cerr << i << ' ' << j << '\n';
		if (j < i)
		ans = min(ans, i - j + 1);
	}
	cout << ans << '\n';
}