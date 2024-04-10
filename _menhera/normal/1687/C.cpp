#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> C, vector<pair<int, int>> LR)
{
	int N = C.size(), M = LR.size();
	long long s = 0;
	vector<int> zero = {0};
	for (int i = 0; i < N; i++)
	{
		s += C[i];
		if (!s)
			zero.push_back(i + 1);
	}
	if (s)
		return false;
	int K = (int)zero.size() - 1;

	vector<int> tmp(K);
	iota(tmp.begin(), tmp.end(), 0);
	set<int> unused(tmp.begin(), tmp.end());

	vector<int> indeg(M);
	vector<vector<int>> direct(K);
	queue<int> Q;
	for (int i = 0; i < M; i++)
	{
		auto &[l, r] = LR[i];
		int il = upper_bound(zero.begin(), zero.end(), l) - zero.begin() - 1;
		int ir = lower_bound(zero.begin(), zero.end(), r) - zero.begin();
		/*cout << i << endl;
		cout << l << " " << r << endl;
		cout << il << " " << ir << endl;*/
		if (zero[il] != l)
		{
			++indeg[i];
			direct[il].push_back(i);
		}
		if (zero[ir] != r)
		{
			++indeg[i];
			direct[ir - 1].push_back(i);
		}
		l = il, r = ir;
		if (!indeg[i])
			Q.emplace(i);
	}
	while (!Q.empty())
	{
		int i = Q.front();
		Q.pop();
		auto [l, r] = LR[i];
		// cout << i << " " << l << " " << r << endl;
		auto it = unused.lower_bound(l);
		while (it != unused.end() && *it < r)
		{
			for (auto x : direct[*it])
				if (--indeg[x] == 0)
					Q.push(x);
			it = unused.erase(it);
		}
	}
	return unused.empty();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<int> A(N), B(N);
		for (int &x : A)
			cin >> x;
		for (int &x : B)
			cin >> x;
		vector<pair<int, int>> LR(M);
		for (auto &[l, r] : LR)
		{
			cin >> l >> r;
			--l;
		}
		vector<int> C(N);
		for (int i = 0; i < N; i++)
		{
			C[i] = A[i] - B[i];
			if (C[i] == 0)
				LR.emplace_back(i, i + 1);
		}
		if (solve(C, LR))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}