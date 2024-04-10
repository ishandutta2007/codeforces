/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int n, m;

vector <vector <int> > v;
vector <vector <int> > buf;

void trans(int x, int tp) {
	if (tp == 0) {
		vector <int> now;

		for (int i = 0; i < m; i += 2) {
			now.push_back(v[x][i]);
		}

		reverse(now.begin(), now.end());

		int pos = m - 1;

		if (pos % 2 == 0) {
			pos--;
		}

		for (int i = pos; i >= 0; i -= 2) {
			now.push_back(v[x][i]);
		}

		v[x] = now;
	}
	else {
		vector <int> now;

		for (int i = 0; i < n; i += 2) {
			now.push_back(v[i][x]);
		}

		reverse(now.begin(), now.end());

		int pos = n - 1;

		if (pos % 2 == 0) {
			pos--;
		}

		for (int i = pos; i >= 0; i -= 2) {
			now.push_back(v[i][x]);
		}

		for (int i = 0; i < n; i++) {
			v[i][x] = now[i];
		}
	}
}

set <pii> bad;

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != n - 1) {
				if (bad.count(mp(buf[i][j], buf[i + 1][j]))) {
					return false;
				}
			}

			if (j != m - 1) {
				if (bad.count(mp(buf[i][j], buf[i][j + 1]))) {
					return false;
				}
			}
		}
	}

	return true;
}

bool checks() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != n - 1) {
				if (bad.count(mp(v[i][j], v[i + 1][j]))) {
					return false;
				}
			}

			if (j != m - 1) {
				if (bad.count(mp(v[i][j], v[i][j + 1]))) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	cin >> n >> m;

	if (n == 1 && m == 1) {
		cout << "YES\n";
		cout << 1 << endl;
		return 0;
	}

	v.resize(n);

	for (int i = 0; i < n; i++) {
		v[i].resize(m);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = i * m + j + 1;
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i != n - 1) {
				bad.insert(mp(v[i][j], v[i + 1][j]));
				bad.insert(mp(v[i + 1][j], v[i][j]));
			}

			if (j != m - 1) {
				bad.insert(mp(v[i][j], v[i][j + 1]));
				bad.insert(mp(v[i][j + 1], v[i][j]));
			}
		}
	}*/

	buf = v;

	if (m >= 4) {
		for (int i = 0; i < n; i++) {
			trans(i, 0);
			if (i % 2 == 1) {
				reverse(v[i].begin(), v[i].end());

				if (m % 2 == 1) {
					reverse(v[i].begin(), v[i].begin() + m / 2);
					reverse(v[i].begin() + m / 2, v[i].end());
				}
			}
		}
	}
	else if (n >= 4) {
		for (int i = 0; i < m; i++) {
			trans(i, 1);

			if (i % 2 == 1) {
				for (int j = 0; j < n - j - 1; j++) {
					swap(v[j][i], v[n - j - 1][i]);
				}

				if (n % 2 == 1) {
					for (int j = 0; j < n / 2 - j - 1; j++) {
						swap(v[j][i], v[n / 2 - j - 1][i]);
					}

					int l = n / 2;
					int r = n - 1;

					while (l < r) {
						swap(v[l][i], v[r][i]);
						l++;
						r--;
					}
				}
			}
		}
	}
	else {
		if (n == 1 || m == 1) {
			cout << "NO" << endl;
			return 0;
		}

		if (n == 2 && m == 2) {
			cout << "NO" << endl;
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i != n - 1) {
					bad.insert(mp(v[i][j], v[i + 1][j]));
					bad.insert(mp(v[i + 1][j], v[i][j]));
				}

				if (j != m - 1) {
					bad.insert(mp(v[i][j], v[i][j + 1]));
					bad.insert(mp(v[i][j + 1], v[i][j]));
				}
			}
		}

		vector <int> f;

		for (int i = 1; i <= n * m; i++) {
			f.push_back(i);
		}

		while (true) {
			int pos = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					buf[i][j] = f[pos++];
				}
			}

			if (check()) {
				printf("YES\n");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						printf("%d ", buf[i][j]);
					}

					printf("\n");
				}

				return 0;
			}

			if (!next_permutation(f.begin(), f.end())) {
				break;
			}
		}

		printf("NO\n");
		return 0;
	}

	//if (!checks()) {
	//	throw 1;
	//}

	cout << "YES" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", v[i][j]);
		}

		printf("\n");
	}

	return 0;
}