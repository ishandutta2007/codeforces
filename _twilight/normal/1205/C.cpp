#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>
#define fi first
#define sc second

const int N = 55;

const int mov[6][2] = {{-2, 0}, {0, 2}, {1, 1}, {2, 0}, {0, -2}, {-1, -1}};

int n;
int a[N][N];

int query(int x1, int y1, int x2, int y2) {
	int x;
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int _query(int x1, int y1, int x2, int y2) {
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	return query(x1, y1, x2, y2);
}

int A[9], B[9];
void solve_min(int x, int y) {
	A[0] = a[x][y], A[2] = a[x][y + 2];
	A[4] = a[x + 1][y + 1];
	A[6] = a[x + 2][y], A[8] = a[x + 2][y + 2];
	B[0] = a[x][y], B[2] = a[x][y + 2];
	B[4] = a[x + 1][y + 1];
	B[6] = a[x + 2][y], B[8] = a[x + 2][y + 2];
	
	int x13 = !query(x, y + 1, x + 1, y + 2);
	int x14 = !query(x, y + 1, x + 2, y + 1);
	int x23 = !query(x + 1, y, x + 1, y + 2);
	
	A[1] = 0;
	A[3] = A[1] ^ x13 ^ x23;
	A[5] = A[1] ^ x13;
	A[7] = A[1] ^ x14;

	B[1] = A[1] ^ 1, B[3] = A[3] ^ 1, B[5] = A[5] ^ 1, B[7] = A[7] ^ 1;

	auto Q = [&] (int* a, vector<int> s) {
		return a[s[0]] == a[s[3]] && a[s[1]] == a[s[2]];
	};
	auto Qa = [&] (vector<int> s) {
		return Q(A, s);
	};
	auto Qb = [&] (vector<int> s) {
		return Q(B, s);
	};
	
#define quit(R) a[x][y + 1] = R[1], a[x + 1][y] = R[3], a[x + 1][y + 2] = R[5], a[x + 2][y + 1] = R[7]

	boolean ra = Qa({0, 1, 2, 5}) || Qa({0, 1, 4, 5}) || Qa({0, 3, 4, 5});
	boolean rb = Qb({0, 1, 2, 5}) || Qb({0, 1, 4, 5}) || Qb({0, 3, 4, 5});
	if (ra ^ rb) {
		if (query(x, y, x + 1, y + 2) == ra) {
			quit(A);
		} else {
			quit(B);
		}
		return;
	}

	ra = Qa({3, 4, 5, 8}) || Qa({3, 4, 7, 8}) || Qa({3, 6, 7, 8});
	rb = Qb({3, 4, 5, 8}) || Qb({3, 4, 7, 8}) || Qb({3, 6, 7, 8});
	if (ra ^ rb) {
		if (query(x + 1, y, x + 2, y + 2) == ra) {
			quit(A);
		} else {
			quit(B);
		}
		return;
	}

	ra = Qa({0, 3, 6, 7}) || Qa({0, 3, 4, 7}) || Qa({0, 1, 4, 7});
	rb = Qb({0, 3, 6, 7}) || Qb({0, 3, 4, 7}) || Qb({0, 1, 4, 7});
	if (ra ^ rb) {
		if (query(x, y, x + 2, y + 1) == ra) {
			quit(A);
		} else {
			quit(B);
		}
		return;
	}

	ra = Qa({1, 4, 7, 8}) || Qa({1, 4, 5, 8}) || Qa({1, 2, 5, 8});
	rb = Qb({1, 4, 7, 8}) || Qb({1, 4, 5, 8}) || Qb({1, 2, 5, 8});
	if (ra ^ rb) {
		if (query(x, y + 1, x + 2, y + 2) == ra) {
			quit(A);
		} else {
			quit(B);
		}
		return;
	}
	assert(false);
}

int main() {
	scanf("%d", &n);
	memset(a, -1, sizeof(a));
	a[1][1] = 1, a[n][n] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i == 1 && j == 1) || (i == n && j == n)) {
				continue;
			}
			if (!((i + j) & 1)) {
				if (j == 1) {
					a[i][j] = a[i - 2][j] ^ !query(i - 2, j, i, j);
				} else if (j == 2) {
					a[i][j] = a[i - 1][j - 1] ^ !query(i - 1, j - 1, i, j);
				} else {
					a[i][j] = a[i][j - 2] ^ !query(i, j - 2, i, j);
				}
			}
		}
	}
	queue<pii> Q;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n - 2; j++) {
			if (!((i + j) & 1)) {
				if (a[i][j] ^ a[i + 2][j + 2]) {
					solve_min(i, j);
					Q.push(pii(i, j + 1));
					Q.push(pii(i + 1, j));
					Q.push(pii(i + 1, j + 2));
					Q.push(pii(i + 2, j + 1));
					goto fin;
				}
			}
		}
	}
	assert(false);
fin:
	while (!Q.empty()) {
		pii e = Q.front();
		Q.pop();
		for (int k = 0; k < 6; k++) {
			pii eu(e.fi + mov[k][0], e.sc + mov[k][1]);
			if (eu.fi < 1 || eu.fi > n || eu.sc < 1 || eu.sc > n)
				continue;
			if (a[eu.fi][eu.sc] >= 0)
				continue;
			a[eu.fi][eu.sc] = a[e.fi][e.sc] ^ !_query(eu.fi, eu.sc, e.fi, e.sc);
			Q.push(eu);
		}
	}
	putchar('!');
	for (int i = 1; i <= n; i++) {
		putchar('\n');
		for (int j = 1; j <= n; j++) {
			putchar('0' + a[i][j]);
		}
	}
	putchar('\n');
	fflush(stdout);
	return 0;
}