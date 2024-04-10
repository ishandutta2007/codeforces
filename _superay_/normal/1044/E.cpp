#include <bits/stdc++.h>
using namespace std;
int n, m, a[25][25];
pair<int, int> pos[405];
vector<vector<int> > ans;
inline void Op(vector<int> vec) {
	ans.emplace_back(vec);
	for (int i = 0; i < (int)vec.size(); i++) {
		assert(vec[i]);
		a[pos[vec[i]].first][pos[vec[i]].second] = vec[(i + vec.size() - 1) % vec.size()];
	}
	auto tmp = pos[vec[0]];
	for (int i = 1; i < (int)vec.size(); i++) {
		pos[vec[i - 1]] = pos[vec[i]];
	}
	pos[vec.back()] = tmp;
}
inline void ToRight(int x, int y) {
	if (x != n) {
		Op({a[x][y], a[x][y + 1], a[x + 1][y + 1], a[x + 1][y]});
	} else {
		Op({a[x][y], a[x][y + 1], a[x - 1][y + 1], a[x - 1][y]});
	}
}
inline void ToLeft(int x, int y) {
	if (x != n) {
		Op({a[x][y], a[x][y - 1], a[x + 1][y - 1], a[x + 1][y]});
	} else {
		Op({a[x][y], a[x][y - 1], a[x - 1][y - 1], a[x - 1][y]});
	}
}
inline void ToUp(int x, int y) {
	Op({a[x][y], a[x - 1][y], a[x - 1][y + 1], a[x][y + 1]});
}
vector<vector<pair<int, int> > > vs1, vs2;
inline void Swap(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		if (y1 > y2) swap(y1, y2);
		if (x1 + 1 <= n && y1 + 2 <= m) {
			for (auto &vec : vs1) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 + P.first][y1 + P.second]);
				}
				Op(cur);
			}
		} else if (x1 + 1 <= n) {
			swap(y1, y2);
			for (auto &vec : vs1) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 + P.first][y1 - P.second]);
				}
				Op(cur);
			}
		} else if (y1 + 2 <= m) {
			for (auto &vec : vs1) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 - P.first][y1 + P.second]);
				}
				Op(cur);
			}
		} else {
			swap(y1, y2);
			for (auto &vec : vs1) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 - P.first][y1 - P.second]);
				}
				Op(cur);
			}
		}
	} else {
		if (x1 > x2) swap(x1, x2);
		if (x1 + 2 <= n && y1 + 1 <= m) {
			for (auto &vec : vs2) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 + P.first][y1 + P.second]);
				}
				Op(cur);
			}
		} else if (x1 + 2 <= n) {
			for (auto &vec : vs2) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 + P.first][y1 - P.second]);
				}
				Op(cur);
			}
		} else if (y1 + 1 <= m) {
			swap(x1, x2);
			for (auto &vec : vs2) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 - P.first][y1 + P.second]);
				}
				Op(cur);
			}
		} else {
			swap(x1, x2);
			for (auto &vec : vs2) {
				vector<int> cur;
				for (auto &P : vec) {
					cur.push_back(a[x1 - P.first][y1 - P.second]);
				}
				Op(cur);
			}
		}
	}
}
int main() {
	vs1.push_back({{0, 0}, {0, 1}, {1, 1}, {1, 0}});
	vs1.push_back({{0, 1}, {0, 2}, {1, 2}, {1, 1}});
	vs1.push_back({{0, 0}, {1, 0}, {1, 1}, {1, 2}, {0, 2}, {0, 1}});
	vs2 = vs1;
	for (auto &vec : vs2) {
		for (auto &P : vec) swap(P.first, P.second);
	}
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			pos[a[i][j]] = make_pair(i, j);
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m; j++) {
			int fx, fy;
			tie(fx, fy) = pos[(i - 1) * m + j];
			if (fx == i && fy == j) continue;
			while (fy < j) {
				ToRight(fx, fy);
				fy++;
			}
			while (fy > j) {
				ToLeft(fx, fy);
				fy--;
			}
			if (fy < m) {
				while (fx > i) {
					ToUp(fx, fy);
					fx--;
				}
			} else {
				while (fx > i) {
					Swap(fx, fy, fx - 1, fy);
					fx--;
				}
			}
		}
	}
	for (int i = n - 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int fx, fy;
			tie(fx, fy) = pos[(i - 1) * m + j];
			if (fx == i && fy == j) continue;
			while (fy > j) {
				Swap(fx, fy, fx, fy - 1);
				fy--;
			}
			while (fy < j) {
				Swap(fx, fy, fx, fy + 1);
				fy++;
			}
			if (fy < m) {
				while (fx > i) {
					ToUp(fx, fy);
					fx--;
				}
			} else {
				while (fx > i) {
					Swap(fx, fy, fx - 1, fy);
					fx--;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) assert(a[i][j] == (i - 1) * m + j);
	printf("%d\n", (int)ans.size());
	for (auto &vec : ans) {
		printf("%d", (int)vec.size());
		for (int x : vec) printf(" %d", x);
		printf("\n");
	}
	return 0;
}