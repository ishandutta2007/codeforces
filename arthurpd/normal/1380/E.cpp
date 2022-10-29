#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, m, t, a, b;
	cin >> n >> m;
	vector<set<int>> towers(m + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		towers[t].insert(i);
	}

	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int x : towers[i])
		{
			if (towers[i].find(x + 1) == towers[i].end())
				ans++;
		}
	}

	cout << (ans - 1) << endl;
	for (int i = 0; i < m - 1; i++)
	{
		cin >> a >> b;
		if (towers[a].size() < towers[b].size())
			swap(towers[a], towers[b]);

		for (int x : towers[b])
		{
			if (towers[a].find(x - 1) != towers[a].end())
				ans--;
			if (towers[a].find(x + 1) != towers[a].end())
				ans--;
		}

		for (int x : towers[b])
			towers[a].insert(x);
		towers[b].clear();

		cout << (ans - 1) << endl;
	}
}