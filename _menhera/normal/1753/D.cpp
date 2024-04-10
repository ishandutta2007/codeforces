#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, p, q;
	cin >> N >> M >> p >> q;
	vector<string> V(N);
	for (auto &y : V)
		cin >> y;
	auto val = [&](int a, int b)
	{
		return 0 <= a && a < N && 0 <= b && b < M;
	};
	auto idx = [&](int a, int b)
	{ return a * M + b; };
	vector<vector<pair<int, int>>> G(N * M);
	auto push = [&](int fx, int fy, int tx, int ty, int c)
	{
		if (val(fx, fy) && val(tx, ty) && V[fx][fy] != '#')
			G[idx(fx, fy)].emplace_back(idx(tx, ty), c);
	};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (V[i][j] == 'L')
			{
				push(i - 1, j + 1, i, j, p);
				push(i + 1, j + 1, i, j, p);
				push(i, j + 2, i, j, q);
			}
			if (V[i][j] == 'R')
			{
				push(i - 1, j - 1, i, j, p);
				push(i + 1, j - 1, i, j, p);
				push(i, j - 2, i, j, q);
			}
			if (V[i][j] == 'U')
			{
				push(i + 1, j - 1, i, j, p);
				push(i + 1, j + 1, i, j, p);
				push(i + 2, j, i, j, q);
			}
			if (V[i][j] == 'D')
			{
				push(i - 1, j - 1, i, j, p);
				push(i - 1, j + 1, i, j, p);
				push(i - 2, j, i, j, q);
			}
		}
	}

	using pli = pair<long long, int>;
	vector<long long> DS(N * M, -1);
	priority_queue<pli, vector<pli>, greater<pli>> Q;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (V[i][j] == '.')
				Q.emplace(0LL, idx(i, j));
	while (!Q.empty())
	{
		auto [d, v] = Q.top();
		Q.pop();
		if (DS[v] != -1)
			continue;
		DS[v] = d;
		for (auto [u, w] : G[v])
			Q.emplace(d + w, u);
	}

	long long ans = LLONG_MAX;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i != N - 1)
				if (DS[idx(i, j)] != -1 && DS[idx(i + 1, j)] != -1)
					ans = min(ans, DS[idx(i, j)] + DS[idx(i + 1, j)]);
			if (j != M - 1)
				if (DS[idx(i, j)] != -1 && DS[idx(i, j + 1)] != -1)
					ans = min(ans, DS[idx(i, j)] + DS[idx(i, j + 1)]);
		}
	}
	if (ans == LLONG_MAX)
		ans = -1;
	cout << ans << '\n';
}