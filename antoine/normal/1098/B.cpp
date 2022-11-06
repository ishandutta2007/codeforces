#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string f(const int n, const char a, const char b) {
	string s(n, a);
	for (int i = 1; i < n; i += 2)
		s[i] = b;
	return s;
}

int simCnt(const string &s1, const string &s2) {
	assert(s1.size() == s2.size());
	int res = 0;
	for (int i = 0; i < (int) s1.size(); ++i)
		res += s1[i] == s2[i];
	return res;
}

int f(vector<string> &grid, const string &acgt) {
	int res = 0;
	for (int i = 0; i < (int) grid.size(); ++i) {
		const char a = acgt[(i & 1) << 1];
		const char b = acgt[(i & 1) << 1 | 1];
		const string s1 = f(grid[0].size(), a, b);
		const string s2 = f(grid[0].size(), b, a);
		// cerr << s1 << ' ' << s2 << endl;

		res += max(simCnt(grid[i], s1), simCnt(grid[i], s2));
		grid[i] = simCnt(grid[i], s1) > simCnt(grid[i], s2) ? s1 : s2;
	}
	return res;
}

int f(vector<string> &grid) {
	pair<int, vector<string>> res = { 0, { } };

	string acgt = "ACGT";

	do {
		vector<string> temp = grid;
		const int curr = f(temp, acgt);
		res = max(res, { curr, temp });
		// cerr << curr << endl;
	} while (next_permutation(acgt.begin(), acgt.end()));
	grid = res.second;
	// cerr << res.first << endl;

	return res.first;
}

vector<string> rev(const vector<string> &grid) {
	const int n = (int)grid.size();
	const int m = (int)grid[0].size();
	vector<string> res(m, string(n, '.'));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			res[j][i] = grid[i][j];
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;

	cin >> n >> m;
	vector<string> grid(n);
	for (string &s : grid)
		cin >> s;

	{
		auto grid2 = rev(grid);

		if (f(grid2) > f(grid))
			grid = rev(grid2);
	}

	for (const string &s : grid)
		cout << s << '\n';
	return 0;
}