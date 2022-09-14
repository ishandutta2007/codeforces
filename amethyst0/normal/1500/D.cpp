#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 1510;
int ch[maxn][maxn];
short d[2][maxn][maxn][10];
int col[2][maxn][maxn][10];

int cnt[maxn * maxn];
int in;

bool dl = false;

void add(int x) {
	dl = false;
	if (x == -1) {
		return;
	}

	if (cnt[x] == 0) {
		in++;
	}

	cnt[x]++;
}

void del(int x) {
	if (x == -1) {
		dl = false;
		return;
	}

	if (cnt[x] == 1) {
		dl = true;
		in--;
	}
	else {
		dl = false;
	}

	cnt[x]--;
}

short ans[maxn][maxn][10];
int cl[maxn][maxn][10];
int q;

void upd(int x, int y, int a, int b, int c, int last, int &prev) {
	int it = in;
	if (it <= q) {
		int len = min(d[0][x][y][a - 1], d[1][x][y][b - 1]);
		len = min(len, ans[x + 1][y + 1][c - 1] + 1);
		ans[x][y][it - 1] = max(ans[x][y][it - 1], (short)len);
	}

	prev = it;
}

ll tot[maxn];

mt19937 rr(12);
int n;

ll res[maxn];

void stup() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			set <int> cur;

			for (int d = 1; d <= min(n - i, n - j); d++) {
				for (int a = 0; a < d; a++) {
					cur.insert(ch[i + d - 1][a + j]);
					cur.insert(ch[a + i][j + d - 1]);
				}

				if ((int)cur.size() <= q) {
					res[d]++;
				}
				else {
					//cout << d - 1 << ' ';
					break;
				}

				if (d == min(n - i, n - j)) {
					//cout << d << ' ';
				}
			}
		}
		//cout << '\n';
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << '\n';
	}
}

int main() {
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &ch[i][j]);
			//ch[i][j] = rr() % (q + 1) + 1;
			ch[i][j]--;
		}
	}

	memset(col, -1, sizeof col);

	for (int it = 1; it <= q; it++) {
		for (int i = 0; i < n; i++) {
			int r = 0;
			for (int j = 0; j < n; j++) {
				while (r < n && in <= it) {
					if (in == it && cnt[ch[i][r]] == 0) {
						break;
					}
					add(ch[i][r]);
					r++;
				}
				d[0][i][j][it - 1] = r - j;
				if (it == 1) {
					col[0][i][j][0] = ch[i][j];
				}
				else if (j + d[0][i][j][it - 2] != n) {
					col[0][i][j][it - 1] = ch[i][j + d[0][i][j][it - 2]];
				}

				del(ch[i][j]);
			}
		}
	}

	for (int it = 1; it <= q; it++) {
		for (int j = 0; j < n; j++) {
			int r = 0;
			for (int i = 0; i < n; i++) {
				while (r < n && in <= it) {
					if (in == it && cnt[ch[r][j]] == 0) {
						break;
					}
					add(ch[r][j]);
					r++;
				}
				d[1][i][j][it - 1] = r - i;
				if (it == 1) {
					col[1][i][j][0] = ch[i][j];
				}
				else if (i + d[1][i][j][it - 2] != n) {
					col[1][i][j][it - 1] = ch[i + d[1][i][j][it - 2]][j];
				}

				del(ch[i][j]);
			}
		}
	}

	memset(cl, -1, sizeof cl);

	assert(in == 0);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (i == n - 1 || j == n - 1) {
				for (int it = 1; it <= q; it++) {
					ans[i][j][it - 1] = 1;
					if (it == 1) {
						cl[i][j][it - 1] = ch[i][j];
					}
				}

				continue;
			}

			for (int it = 1; it <= q; it++) {
				add(col[0][i][j][it - 1]);
				add(col[1][i][j][it - 1]);
				add(cl[i + 1][j + 1][it - 1]);
				if (i == 0 && j == 0) {
					//cout << "!" << d[0][i][j][it - 1] << ' ' << d[1][i][j][it - 1] << ' ' << ans[i + 1][j + 1][it - 1] << '\n';
				}
			}

			int a = q;
			int b = q;
			int c = q;
			int last = -1;
			int prev = in;

			while (a > 1 || b > 1 || c > 1) {
				upd(i, j, a, b, c, last, prev);

				int val = -1;
				if (a != 1) {
					val = max(val, (int)d[0][i][j][a - 2]);
				}

				if (b != 1) {
					val = max(val, (int)d[1][i][j][b - 2]);
				}

				if (c != 1) {
					val = max(val, ans[i + 1][j + 1][c - 2] + 1);
				}

				if (a != 1 && val == d[0][i][j][a - 2]) {
					del(col[0][i][j][a - 1]);
					last = col[0][i][j][a - 1];
					a--;
				}
				else if (b != 1 && val == d[1][i][j][b - 2]) {
					del(col[1][i][j][b - 1]);
					last = col[1][i][j][b - 1];
					b--;
				}
				else {
					del(cl[i + 1][j + 1][c - 1]);
					last = cl[i + 1][j + 1][c - 1];
					c--;
				}

				if (dl) {
					int it = in;
					if (it < q) {
						cl[i][j][it] = last;
					}
				}
			}

			upd(i, j, a, b, c, last, prev);
			if (ans[i][j][0] == 0) {
				ans[i][j][0] = 1;
				cl[i][j][1] = ch[i + 1][j + 1];
			}

			cl[i][j][0] = ch[i][j];

			del(col[0][i][j][0]);
			del(col[1][i][j][0]);
			del(cl[i + 1][j + 1][0]);

			for (int it = 1; it <= q; it++) {
				if (ans[i][j][it - 1] == 0) {
					assert(it != 1);
					ans[i][j][it - 1] = ans[i][j][it - 2];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << ans[i][j][q - 1] << ' ';
			tot[ans[i][j][q - 1]]++;
		}
		//cout << '\n';
	}

	for (int i = maxn - 2; i >= 0; i--) {
		tot[i] += tot[i + 1];
	}

	for (int i = 1; i <= n; i++) {
		printf("%lld\n", tot[i]);
	}

	//stup();
}