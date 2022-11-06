#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int n, K;
string grid[2009];
const int dx[2] = { 0, 1 };
const int dy[2] = { 1, 0 };
int dist[2009][2009];
int parent[2009][2009];

void bfs() {

	struct Cell {
		int x, y;
		vector<Cell> adj() const {
			vector<Cell> res;
			for (int i = 0; i < 2; ++i) {
				const int x = this->x + dx[i];
				const int y = this->y + dy[i];
				if (0 <= x && x < n && 0 <= y && y < n)
					res.push_back( { x, y });
			}
			return res;
		}
	};

	memset(dist, 120, sizeof dist);
	dist[0][0] = 0;
	deque<Cell> q;
	q.push_front( { 0, 0 });
	while (!q.empty()) {
		const Cell u = q.front();
		q.pop_front();
		const int w = grid[u.x][u.y] != 'a';
		for (const Cell v : u.adj()) {
			if (dist[v.x][v.y] > dist[u.x][u.y] + w) {
				dist[v.x][v.y] = dist[u.x][u.y] + w;
				if (w)
					q.push_back(v);
				else
					q.push_front(v);
			}
		}
	}
}

pair<int, int> getPrev(pair<int, int> cell) {
	const int x = cell.first;
	const int y = cell.second;
	assert(x || y);
	for (const int k = parent[x][y]; k != -1;)
		return {x-dx[k], y - dy[k]};
	assert(dist[x][y] <= K);
	for (int k = 0; k < 2; ++k) {
		const int i = x - dx[k];
		const int j = y - dy[k];
		if (i < 0 || j < 0)
			continue;
		if (dist[i][j] + (grid[i][j] != 'a') == dist[x][y])
			return {i, j};
	}
	assert(false);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(parent, -1, sizeof parent);
	memset(dist, -1, sizeof dist);

	cin >> n >> K;
	for (int i = 0; i < n; ++i)
		cin >> grid[i];

	bfs();

	cerr << "Done BFS\n";

	int currLen = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (dist[i][j] <= K)
				currLen = max(currLen, i + j);

	for (; currLen < 2 * (n - 1); ++currLen) {
		cerr << "CurrLen: " << currLen << endl;
		char ch = 'z' + 1;
		for (int i = 0, j = currLen; i < n && j >= 0; ++i, --j) {
			if (j >= n)
				continue;
			if (dist[i][j] > K && parent[i][j] == -1)
				continue;
			ch = min(ch, grid[i][j]);
		}
		cerr << "min ch: " << ch << endl;
		assert(ch <= 'z');
		for (int i = 0, j = currLen; i < n && j >= 0; ++i, --j) {
			if (j >= n)
				continue;
			// cerr << "(" << i << ", " << j << ") ";
			if (dist[i][j] > K && parent[i][j] == -1)
				continue;
			if (grid[i][j] != ch)
				continue;
			for (int k = 0; k < 2; ++k) {
				const int x = i + dx[k];
				const int y = j + dy[k];
				if (x >= n || y >= n)
					continue;
				parent[x][y] = k;
			}
		}
		// cerr<< endl;
	}
	cerr << "Done Phase 2\n";

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			assert(
					parent[i][j] == -1
							|| (i - dx[parent[i][j]] >= 0
									&& j - dy[parent[i][j]] >= 0));
	string res(1, grid[n - 1][n - 1]);
	pair<int, int> curr = { n - 1, n - 1 };
	while (curr.first || curr.second) {
		curr = getPrev(curr);
		assert(curr.first >= 0 && curr.second >= 0);
		res += grid[curr.first][curr.second];
	}
	reverse(res.begin(), res.end());
	for (char &c : res)
		if (c != 'a' && --K >= 0)
			c = 'a';
	cout << res << '\n';
	return 0;
}