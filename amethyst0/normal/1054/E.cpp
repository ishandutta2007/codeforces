#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

#define ll long long
#define pii pair <int, int>
#define mp make_pair

using namespace std;

const int maxn = 310;

string s[maxn][maxn];
int cnt[maxn][maxn];

vector <pair <pii, pii> > ans;

void write(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) {
		return;
	}

	ans.push_back(mp(mp(x1 + 1, y1 + 1), mp(x2 + 1, y2 + 1)));

	cnt[x2][y2]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			while (!s[i][j].empty()) {
				char c = s[i][j].back();
				s[i][j].pop_back();

				if (c == '0') {
					if (i != 0) {
						write(i, j, 0, j);
					}
					else if (j != 0) {
						write(i, j, i, j - 1);
					}
					else {
						write(i, j, i, j + 1);
					}
				}
				else {
					if (i != 1) {
						write(i, j, 1, j);
					}
					else if (j != 0) {
						write(i, j, i, j - 1);
					}
					else {
						write(i, j, i, j + 1);
					}
				}
			}
		}
	}

	for (int j = 1; j < m; j++) {
		while (cnt[0][j] != 0) {
			cnt[0][j]--;
			write(0, j, 0, 0);
		}
	}

	for (int j = 0; j < m - 1; j++) {
		while (cnt[1][j] != 0) {
			cnt[1][j]--;
			write(1, j, 1, m - 1);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
		}
	}

	for (int i = 2; i < n; i++) {
		for (int j = 0; j < m; j++) {
			while (!s[i][j].empty()) {
				char c = s[i][j].back();
				s[i][j].pop_back();

				if (c == '0') {
					write(0, 0, 0, j);
					write(0, j, i, j);
				}
				else {
					write(1, m - 1, 1, j);
					write(1, j, i, j);
				}
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < m - 1; j++) {
			while (!s[i][j].empty()) {
				char c = s[i][j].back();
				s[i][j].pop_back();

				if (c == '0') {
					if (i == 0) {
						write(0, 0, 0, j);
					}
					else {
						write(0, 0, 1, 0);
						write(1, 0, 1, j);
					}
				}
				else {
					if (i == 1) {
						write(1, m - 1, 1, j);
					}
					else {
						write(1, m - 1, 0, m - 1);
						write(0, m - 1, 0, j);
					}
				}
			}
		}
	}

	while (!s[0][0].empty()) {
		char c = s[0][0].back();
		s[0][0].pop_back();

		if (c == '0') {
			write(0, 0, 0, m - 1);
			write(0, m - 1, 0, 0);
		}
		else {
			write(1, m - 1, 0, m - 1);
			write(0, m - 1, 0, 0);
		}
	}

	while (!s[1][m - 1].empty()) {
		char c = s[1][m - 1].back();
		s[1][m - 1].pop_back();

		if (c == '0') {
			write(0, 0, 0, m - 1);
			write(0, m - 1, 1, m - 1);
		}
		else {
			write(1, m - 1, 0, m - 1);
			write(0, m - 1, 1, m - 1);
		}
	}

	while (!s[0][m - 1].empty()) {
		char c = s[0][m - 1].back();
		s[0][m - 1].pop_back();

		if (c == '0') {
			write(0, 0, 0, m - 1);
		}
		else {
			write(1, m - 1, 0, m - 1);
		}
	}

	while (!s[1][0].empty()) {
		char c = s[1][0].back();
		s[1][0].pop_back();

		if (c == '0') {
			write(0, 0, 1, 0);
		}
		else {
			write(1, m - 1, 1, 0);
		}
	}

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second.first << ' ' << ans[i].second.second << '\n';
	}

	//system("pause");
}