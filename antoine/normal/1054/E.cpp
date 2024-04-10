#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;

string test[300][300];

struct Oper {
	int x1, y1, x2, y2;
	void reverse() {
		swap(x1, x2);
		swap(y1, y2);
	}
	void print() {
		assert(x1 != x2 || y1 != y2);
		cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1
				<< '\n';
	}

	void debug() {
		assert(x1 != x2 || y1 != y2);
		assert(!test[x1][y1].empty());
		test[x2][y2] = string(1, test[x1][y1].back()) + test[x2][y2];
		test[x1][y1].pop_back();
	}
};

string grid[300][300];

vector<Oper> f(const bool first) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
			if (first) {
				test[i][j] = grid[i][j];
			}
			if (first)
				reverse(grid[i][j].begin(), grid[i][j].end());

		}

	vector<Oper> res;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			if (i + j == 1) {
				for (int rep = (int) grid[i][j].size(); rep; --rep)
					res.push_back( { i, j, 0, 0 });
				grid[0][0] += grid[i][j];
			}

	auto adj = [](int i, int j, int x, int y) {
		return i == x || j == y;
	};

	for (int round = 0; round < 2; ++round) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (i + j != 1) {
					for(auto it = grid[i][j].begin(); it != grid[i][j].end(); ++it) {
						const int fX = *it == '0' ? 0 : 1;
						const int fY = *it == '0' ? 1 : 0;
						if(adj(i, j, fX, fY))
							res.push_back({i, j, fX, fY});
						else {
							res.push_back({i, j, fX, j});
							grid[fX][j].push_back(*it);
						}
					}
					grid[i][j].clear();
				}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	auto res1 = f(true);
	auto res2 = f(false);

	reverse(res2.begin(), res2.end());
	for (auto &&x : res2)
		x.reverse();

	cerr << res1.size() << ' ' << res2.size() << '\n';
	cout << res1.size() + res2.size() << '\n';
	for (auto &&x : res1)
		x.print();
	for (auto &&x : res2)
		x.print();
/*
	cerr << "TEST\n";

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cerr << test[i][j] << ' ';
		}
		cerr << '\n';
	}

	cerr << endl << endl;

	for (auto &&x : res1)
		x.debug();
	for (auto &&x : res2)
		x.debug();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cerr << test[i][j] << ' ';
		}
		cerr << '\n';
	}
*/
	return 0;
}