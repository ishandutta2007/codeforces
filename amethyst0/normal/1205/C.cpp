#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = 55;
int v[maxn][maxn];

int n;

int ask(int x1, int y1, int x2, int y2) {
	cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << endl;
	int ans;

	cin >> ans;

	return ans;
}

void change() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 1) {
				v[i][j] ^= 1;
			}
		}
	}
}

void ba(int x, bool yes) {
	if (yes) {
		v[x][x + 1] ^= 1;
		v[x + 1][x + 2] ^= 1;
	}
}

void solver(int x) {
	bool yes = false;
	if (v[x][x + 1] != v[x][x + 2]) {
		yes = true;
		v[x][x + 1] ^= 1;
		v[x + 1][x + 2] ^= 1;
	}

	if (v[x][x + 1] == 1) {
		if (v[x + 1][x + 2] == 1) {
			int fl = ask(x, x, x + 1, x + 2);

			ba(x, yes);

			if (fl == 1) {
				if (v[x + 1][x + 2] == 0) {
					change();
				}
			}
			else {
				if (v[x + 1][x + 2] == 1) {
					change();
				}
			}
		}
		else {
			int fl = ask(x, x + 1, x + 2, x + 2);

			ba(x, yes);

			if (fl == 1) {
				if (v[x][x + 1] == 1) {
					change();
				}
			}
			else {
				if (v[x][x + 1] == 0) {
					change();
				}
			}
		}
	}
	else {
		if (v[x + 1][x + 2] == 1) {
			int fl = ask(x, x, x + 1, x + 2);

			ba(x, yes);

			if (fl == 1) {
				if (v[x + 1][x + 2] == 0) {
					change();
				}
			}
			else {
				if (v[x + 1][x + 2] == 1) {
					change();
				}
			}
		}
		else {
			int fl = ask(x, x + 1, x + 2, x + 2);

			ba(x, yes);

			if (fl == 1) {
				if (v[x][x + 1] == 1) {
					change();
				}
			}
			else {
				if (v[x][x + 1] == 0) {
					change();
				}
			}
		}
	}
}

int main() {
	cin >> n;

	memset(v, -1, sizeof v);

	v[0][0] = 1;
	v[n - 1][n - 1] = 0;
	v[0][1] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] != -1) {
				continue;
			}

			if (j == 0 && i % 2 == 1) {
				continue;
			}

			if (i > 1) {
				int fl = ask(i - 2, j, i, j);
				v[i][j] = v[i - 2][j] ^ fl ^ 1;
			}
			else if (i > 0 && j > 0) {
				int fl = ask(i - 1, j - 1, i, j);

				v[i][j] = v[i - 1][j - 1] ^ fl ^ 1;
			}
			else if (i == 0) {
				int fl = ask(i, j - 2, i, j);

				v[i][j] = v[i][j - 2] ^ fl ^ 1;
			}
		}
	}

	for (int i = 1; i < n; i += 2) {
		int fl = ask(i, 0, i + 1, 1);

		v[i][0] = v[i + 1][1] ^ fl ^ 1;
	}

	for (int i = 0; i < n; i += 2) {
		if (v[i][i] == v[i + 2][i + 2]) {
			continue;
		}

		solver(i);
		break;
	}

	cout << "!" << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j];
		}

		cout << endl;
	}
	
	//system("pause");
	return 0;
}