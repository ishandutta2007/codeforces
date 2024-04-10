#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void no() {
	cout << "No";
	exit(0);
}

int n;
map<int, vector<vector<pair<int, int>>>> mp;
map<int, int> occ;
int grid[21][21];

vector<pair<int, int>> f(const int i, const int j) {
	vector<pair<int, int>> v;
	for (int x : { i, n - 1 - i })
		for (int y : { j, n - 1 - j })
			v.push_back( { x, y });
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

void assign(vector<pair<int, int>> &v, const int x) {
	for (const pair<int, int> &pos : v)
		grid[pos.first][pos.second] = x;
	occ[x] -= (int) v.size();
	assert(occ[x] >= 0);
}

bool assign(const int p, const int x) {
	if (mp[p].empty())
		return false;

	assign(mp[p].back(), x);
	mp[p].pop_back();
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;


	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			const vector<pair<int, int>> v = f(i, j);
			mp[v.size()].push_back(v);
		}


	for (auto &&e : mp) {
		auto &&v = e.second;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}

	cerr << "Test" << endl;
	for (int i = 0; i < n * n; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}

	cerr << "Test" << endl;
	for (auto &&e : occ) {
		for (int p : { 4, 2, 1 })
			while (e.second >= p && assign(p, e.first)) {
				cerr << e.second << '\n';
			}
		if (e.second > 0)
			no();
	}

	cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << grid[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}