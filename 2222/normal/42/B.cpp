#include <algorithm>
#include <iostream>
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

int a[8][8];

void read(int type) {
	char t[8];
	scanf("%s", t);
	int x = t[0] - 'a', y = t[1] - '1';
	a[x][y] = type;
}

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

bool b[8][8];

void go(int i, int j, int dx, int dy) {
	for (; ; ) {
		i += dx;
		j += dy;
		if (i < 0 || i > 7 || j < 0 || j > 7) return;
		b[i][j] = true;
		if (a[i][j]) return;
	}
}

void mate() {
	puts("CHECKMATE");
	exit(0);
}

void other() {
	puts("OTHER");
	exit(0);
}

bool beated() {
	CL(b, 0);
	REP (i, 8) REP (j, 8) {
		if (a[i][j] == 5) {
			REP (k, 4) go(i, j, dx[k], dy[k]);
		} else if (a[i][j] == 1) {
			REP (k, 8) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 && x < 8 && y >= 0 && y < 8) b[x][y] = true;
			}
		}
	}
	REP (i, 8) REP (j, 8)
		if (a[i][j] < 0) 
			return b[i][j];
	return false;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	read(5);
	read(5);
	read(1);
	read(-1);
	if (beated()) {
		REP (i, 8) REP (j, 8) if (a[i][j] < 0) {
			REP (k, 8) {
				int x = i + dx[k], y = j + dy[k];
				if (x >= 0 && x < 8 && y >= 0 && y < 8) {
					int q = a[x][y];
					a[x][y] = a[i][j];
					a[i][j] = 0;
					if (!beated()) other();
					a[i][j] = a[x][y];
					a[x][y] = q;
				}
			}
			mate();
		}
	}
	other();
}