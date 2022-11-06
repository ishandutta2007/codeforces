#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

struct Rect {
	int x1, y1, x2, y2;

	void inc(int i, int j) {
		x1 = min(x1, i);
		x2 = max(x2, i);
		y1 = min(y1, j);
		y2 = max(y2, j);
	}

	void print() const {
		cout << x1 + 1<< ' ' << y1 +1<< ' ' << x2+1 << ' ' << y2 +1<< '\n';
	}
};

vector<string> f(const map<char, Rect> &mp, const int n, const int m) {
	vector<string> grid(n, string(m, '.'));
	for (auto entry : mp) {
		const char c = entry.first;
		const Rect rect = entry.second;
		if (rect.x1 != rect.x2 && rect.y1 != rect.y2) {
			cerr << " != " << '\n';
			return {};
		}

		for (int i = rect.x1; i <= rect.x2; ++i)
			for (int j = rect.y1; j <= rect.y2; ++j) {
				grid[i][j] = c;
			}
	}
	return grid;
}

void f() {
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (string &s : grid)
		cin >> s;

	map<char, Rect> mp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] != '.') {
				char c = grid[i][j];

				if (!mp.count(c)) {
					mp[c] = {i,j,i,j};
				} else {
					mp[c].inc(i, j);
				}
			}
		}
	}

	if (!mp.empty()) {
		for (char c = 'a'; c < mp.rbegin()->first; ++c)
			if (!mp.count(c))
				mp[c] = mp.rbegin()->second;
	}

	DBG(mp.size())

	if (f(mp, n, m) != grid) {
		cerr << "err 2\n";
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	cout << mp.size() << '\n';
	for (auto e : mp)
		e.second.print();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
		f();

	return 0;
}