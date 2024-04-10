#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

char s[10][10];
const char *q = "BRWY";
int c[10], z[10], d[4][4];
bool b[10][10];
int id[10][10];
bool adj[10][10];

int A[22][22];
const int S = 21, T = 20;
bool u[22];

vector<pii> zz;

bool dfs(int x) {
	u[x] = true;
	if (A[x][T]) {
		--A[x][T];
		++A[T][x];
		return true;
	}
	int y0 = x < 10 ? 10 : 0, y1 = x >= 10 && x < 20 ? 10 : 20;
	FOR (y, y0, y1) {
		if (A[x][y] && (y == T || !u[y] && dfs(y))) {
			--A[x][y];
			++A[y][x];
			return true;
		}
	}
	return false;
}

int best = -1;
pii p[100];
int m;

char dr[100][100], ans[100][100];

void put(int i0, int j0, int i1, int j1, int col) {
	int x = zz[col].X, y = zz[col].Y;
	if ((s[i1][j1] == x) + (s[i0][j0] == y) > (s[i1][j1] == y) + (s[i0][j0] == x)) {
		swap(x, y);
	}
	dr[i0 * 2][j0 * 2] = q[x];
	dr[i1 * 2][j1 * 2] = q[y];
}

void check() {
	int r = 0;
	int d[10], e[10];
	m = 0;
	REP (i, 10) {
		d[i] = c[i];
		e[i] = z[i];
		for (; d[i] > 0 && e[i] > 0; ) {
			r += 2;
			--d[i];
			--e[i];
			p[m++] = pii(i, i);
		}
	}
	if (r + (28 - m) <= best) return;
	CL(A, 0);
	int flow = 0;
	REP (i, 10) {
		A[S][i] = d[i];
		A[i + 10][T] = e[i];
	}
	REP (i, 10) REP (j, 10) {
		if (adj[i][j]) {
			A[i][j + 10] = 28;
			for (; A[S][i] && A[i][j + 10] && A[j + 10][T]; ) {
				++r;
				--A[S][i];
				--A[i][j + 10];
				--A[j + 10][T];
				++A[T][j + 10];
				++A[j + 10][i];
				++A[i][S];
			}
		}
	}
	for (; CL(u, 0), dfs(S); ++r);
	if (r > best) {
		REP (i, 10) REP (j, 10) {
			REP (k, A[j + 10][i]) {
				--d[i];
				--e[j];
				p[m++] = pii(j, i);
			}
		}
		REP (i, 10) REP (j, 10) {
			for (; d[i] > 0 && e[j] > 0; ) {
				--d[i];
				--e[j];
				p[m++] = pii(j, i);
			}
		}
		best = r;
		REP (i, 7) REP (j, 8) dr[i * 2][j * 2] = '.';
		REP (i, 7) REP (j, 8) {
			if (dr[i * 2][j * 2 + 1] == '-') {
				int x = id[s[i][j]][s[i][j + 1]];
				REP (l, m) {
					if (p[l].X == x) {
						put(i, j, i, j + 1, p[l].Y);
						p[l] = p[--m];
						break;
					}
				}
			} else if (dr[i * 2 + 1][j * 2] == '|') {
				int x = id[s[i][j]][s[i + 1][j]];
				REP (l, m) {
					if (p[l].X == x) {
						put(i, j, i + 1, j, p[l].Y);
						p[l] = p[--m];
						break;
					}
				}
			}
		}
		REP (i, 13) REP (j, 15) ans[i][j] = dr[i][j];
	}
}

void go(int i, int j) {
	if (i == 7) {
		check();
		return;
	}
	if (j == 8) {
		go(i + 1, 0);
		return;
	}
	if (!b[i][j]) {
		go(i, j + 1);
		return;
	}
	if (b[i][j + 1]) {
		b[i][j] = b[i][j + 1] = false;
		z[id[s[i][j]][s[i][j + 1]]]++;
		dr[i * 2][j * 2 + 1] = '-';
		go(i, j + 1);
		dr[i * 2][j * 2 + 1] = '.';
		z[id[s[i][j]][s[i][j + 1]]]--;
		b[i][j] = b[i][j + 1] = true;
	}
	if (b[i + 1][j]) {
		b[i][j] = b[i + 1][j] = false;
		z[id[s[i][j]][s[i + 1][j]]]++;
		dr[i * 2 + 1][j * 2] = '|';
		go(i, j + 1);
		dr[i * 2 + 1][j * 2] = '.';
		z[id[s[i][j]][s[i + 1][j]]]--;
		b[i][j] = b[i + 1][j] = true;
	}
}

int main() {
	REP (i, 7) {
		gets(s[i]);
		REP (j, 8) {
			b[i][j] = true;
			s[i][j] = find(q, q + 4, s[i][j]) - q;
		}
	}
	REP (i, 4) for (int j = 3; j >= i; --j) {
		id[i][j] = sz(zz);
		id[j][i] = sz(zz);
		cin >> c[sz(zz)];
		zz.pb(pii(i, j));
	}
	REP (i, 10) REP (j, 10) 
		if (zz[i].X == zz[j].X || zz[i].X == zz[j].Y || zz[i].Y == zz[j].X || zz[i].Y == zz[j].Y) {
			adj[i][j] = true;
		}
	REP (i, 13) REP (j, 15) dr[i][j] = '.';
	go(0, 0);
	cout << best << endl;
	REP (i, 13) cout << ans[i] << endl;
	return 0;
}