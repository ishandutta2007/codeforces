#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x, --x;
	vector<int> k(m);
	for (auto& x : k)
		cin >> x;
	int oo = 1e9;
	int ans = oo;
	vector<vector<int>> mem(m);
	for (int i = 0; i < n; ++i)
		mem[a[i]].push_back(i);
	auto fail = [&]()
	{
		cout << -1 << '\n';
		exit(0);
	};
	vector<int> pt(m);
	for (int i = 0; i < m; ++i)
	{
		if (mem[i].size() < k[i])
		{
			fail();
		}
		if (k[i] == 0)
			pt[i] = -1;
		else
			pt[i] = mem[i][k[i] - 1];
	}
	int sm = accumulate(k.begin(), k.end(), 0);
	multiset<int> st;
	for (auto& x : pt)
		st.insert(x);
	for (int i = 0; i < n; ++i)
	{
		ans = min(ans, (*st.rbegin() + 1 - i) - sm);
		if (i + 1 < n)
		{
			int col = a[i];
			if (k[col] == 0)
				continue; 
			st.erase(st.find(pt[col]));
			auto it = upper_bound(mem[col].begin(), mem[col].end(), pt[col]);
			if (it == mem[col].end())
				break;
			pt[col] = *it;
			st.insert(pt[col]);
		}
	}
	if (ans == oo)
		cout << -1 << '\n';
	else
		cout << max(0, ans) << '\n';
}