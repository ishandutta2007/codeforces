#include <bits/stdc++.h>
using namespace std;

string solve(int N, vector<pair<int, int>> E)
{
	vector<vector<int>> G(N);
	for (int i = 0; i < (int)E.size(); i++)
	{
		auto [a, b] = E[i];
		G[a].push_back(i);
		G[b].push_back(i);
	}
	vector<bool> vis(N);
	set<int> backE;
	vector<int> P(N);
	vector<int> H(N);
	function<void(int, int, int)> dfs = [&](int a, int p, int h)
	{
		vis[a] = 1;
		for (int e : G[a])
		{
			int x = a ^ E[e].first ^ E[e].second;
			if (x != p)
			{
				if (vis[x])
					backE.insert(e);
				else
					dfs(x, a, h + 1), P[x] = e;
			}
		}
		H[a] = h;
	};
	dfs(0, -1, 0);
	string ans(E.size(), '0');
	if (backE.size() == 3)
	{
		set<int> N;
		for (int e : backE)
			N.insert(E[e].first), N.insert(E[e].second);
		if (N.size() == 3)
		{
			int T = *N.begin();
			for (int t : N)
				if (H[T] < H[t])
					T = t;
			auto it = backE.begin();
			while (1)
			{
				if (E[*it].first == T || E[*it].second == T)
				{
					backE.erase(it);
					break;
				}
				++it;
			}
			backE.insert(P[T]);
		}
	}
	for (int e : backE)
		ans[e] = '1';
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>> E(M);
		for (auto &[a, b] : E)
		{
			cin >> a >> b;
			--a, --b;
		}
		cout << solve(N, E) << '\n';
	}
}