#include <bits/stdc++.h>

using namespace std;

const int MX = 300, MXLEN = 100000;

string s[2 * MX][MX];
int cnt[MX][2];

int main() {
	int n, m;
	ignore = scanf("%d %d", &n, &m);
	for (int i = 0; i < 2 * n; i++) {
		for (int j = 0; j < m; j++) {
			static char buff[MXLEN + 1];
			ignore = scanf(" %s", buff);
			s[i][j] = buff;
		}
	}
	
	vector<tuple<int, int, int, int>> vec;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x[2];
			x[0] = (j == 0 ? (i + 1) % n : i);
			x[1] = (j == 1 ? (i + 1) % n : i);
			for (int k = s[i][j].size() - 1; k >= 0; k--) {
				vec.emplace_back(i, j, x[s[i][j][k] - '0'], s[i][j][k] - '0');
				cnt[x[s[i][j][k] - '0']][s[i][j][k] - '0']++;
			}
		}
	}
	
	int x[2];
	x[0] = x[1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (size_t k = 0; k < s[n + i][j].size(); k++) {
				int c = s[n + i][j][k] - '0';
				while (cnt[x[c]][c] == 0) x[c]++;
				
				cnt[x[c]][c]--;
				
				if (x[c] != i) vec.emplace_back(x[c], c, i, c);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 2; j < m; j++) {
			for (int k = s[n + i][j].size() - 1; k >= 0; k--) {
				int c = s[n + i][j][k] - '0';
				
				vec.emplace_back(i, c, i, j);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		int cnt0 = count(s[n + i][0].begin(), s[n + i][0].end(), '0');
		int cnt1 = count(s[n + i][1].begin(), s[n + i][1].end(), '1');
		for (int j = 0; j < cnt0; j++) vec.emplace_back(i, 0, (i + 1) % n, 0);
		for (int j = 0; j < cnt1; j++) vec.emplace_back(i, 1, (i + 1) % n, 1);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = s[n + i][j].size() - 1; k >= 0; k--) {
				int c = s[n + i][j][k] - '0';
				int x = (c == j ? (i + 1) % n : i);
				vec.emplace_back(x, c, i, j);
			}
		}
	}
	
	printf("%d\n", (int)vec.size());
	for (auto x : vec) {
		int a, b, c, d;
		tie(a, b, c, d) = x;
		printf("%d %d %d %d\n", a + 1, b + 1, c + 1, d + 1);
		/*
		assert(s[a][b].empty() == false && (a != c || b != d) && (a == c || b == d));
		s[c][d] = s[a][b].back() + s[c][d];
		s[a][b].pop_back();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) printf("%s ", s[i][j].c_str());
			printf("\n");
		}
		*/
	}
	
	return 0;
}