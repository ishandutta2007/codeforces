#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m, x1, y1, x2, y2;
	cin >> n >> m;
	int **a = new int*[n];
	vector<int> q(24);
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
		for (int j = 0; j < m; ++j) {
			char tmp;
			cin >> tmp;
			if (tmp == '#')
				a[i][j] = 0;
			else
				a[i][j] = 1;
			if (tmp == 'S') {
				x1 = i;
				y1 = j;
			}
			else
			if (tmp == 'E') {
				x2 = i;
				y2 = j;
			}
		}
	}
	string s;
	cin >> s;
	int* c = new int[4];
	int* k = new int[4];
	c[0] = c[1] = c[2] = c[3] = 0;
	for (int i = 0; i < s.size(); ++i) {
		++c[s[i] - '0'];
		int r = 0;
		for (k[0] = 0; k[0] < 4; ++k[0])
			for (k[1] = 0; k[1] < 4; ++k[1])
				for (k[2] = 0; k[2] < 4; ++k[2])
					for (k[3] = 0; k[3] < 4; ++k[3]) {
						if (k[0] + k[1] + k[2] + k[3] == 6 && k[0] != k[1] && k[0] != k[2] && k[0] != k[3] && k[1] != k[2] && k[1] != k[3] && k[2] != k[3]) {
							int x = x1, y = y1;
							for (int j = 0; j < 4; ++j)
								switch (k[j]) {
								case 0:
									x += c[j];
									break;
								case 1:
									x -= c[j];
									break;
								case 2:
									y += c[j];
									break;
								case 3:
									y -= c[j];
								}
							if (x >= 0 && x < n && y >= 0 && y < m) {
								if (a[x][y] == 1) {
									if (x == x2 && y == y2 && q[r] != 1)
										q[r] = 2;
								}
								else
									if (q[r] != 2)
										q[r] = 1;
							}
							else
								if (q[r] != 2)
									q[r] = 1;
							++r;
						}
					}
	}
	int t = 0;
	for (int i = 0; i < 24; ++i)
		if (q[i] == 2)
			++t;
	cout << t;
	return 0;
}