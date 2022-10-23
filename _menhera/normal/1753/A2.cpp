#include <bits/stdc++.h>
using namespace std;

vector<int> calcMin(vector<int> V)
{
	if (V.size() == 1)
		return {+1};
	vector<int> D(V.size());
	vector<int> R(V.size());
	D[0] = V[0];
	D[1] = min(V[0] - V[1], V[0] + V[1]);
	for (int i = 2; i < (int)V.size(); i++)
		D[i] = min(D[i - 2] + V[i - 1] - V[i], D[i - 1] + V[i]);

	int i;
	for (i = (int)V.size() - 1; i >= 2;)
	{
		if (D[i] == D[i - 2] + V[i - 1] - V[i])
		{
			R[i - 1] = +1;
			R[i] = -1;
			i -= 2;
		}
		else
		{
			R[i] = +1;
			--i;
		}
	}
	if (i == 1)
	{
		if (D[1] == V[0] - V[1])
			R[1] = -1, R[0] = +1;
		else
			R[1] = +1, R[0] = +1;
	}
	else
		R[0] = +1;
	return R;
}

vector<int> calcMax(vector<int> V)
{
	for (int &x : V)
		x = -x;
	return calcMin(V);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> V(N);
		for (int &x : V)
			cin >> x;

		vector<int> sgnMin = calcMin(V);
		vector<int> sgnMax = calcMax(V);
		vector<int> cursgn = sgnMin;

		int cur = 0;
		for (int i = 0; i < N; i++)
			cur += cursgn[i] * V[i];
		for (int i = 0; i < N && cur; i++)
			if (cursgn[i] != +1)
			{
				cursgn[i] = +1;
				cur += 2 * V[i];
			}
		for (int i = 0; i < N && cur; i++)
			if (+1 != sgnMax[i])
			{
				cursgn[i] = -1;
				cur += -2 * V[i];
			}

		if (cur == 0)
		{
			vector<pair<int, int>> P;
			for (int i = 0; i < N;)
			{
				if (i != N - 1 && cursgn[i + 1] == -1)
					P.emplace_back(i, i + 1), i += 2;
				else
					P.emplace_back(i, i), i += 1;
			}
			cout << P.size() << '\n';
			for (auto [a, b] : P)
				cout << a + 1 << " " << b + 1 << '\n';
		}
		else
			cout << -1 << '\n';
	}
}