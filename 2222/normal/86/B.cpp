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

int n, m;
char s[1024][1024];

inline bool u(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j <= m && s[i][j] == '.';
}

int p[1024 * 1024], c[1024 * 1024];
bool b[1024][1024];

int sid(int x) {
	int y, z = x;
	for (; (y = p[z]) != z; z = y);
	for (; x != z; x = y) {
		y = p[x];
		p[x] = z;
	} 
	return x;
}

int f(int x, int y) { return sid(x * m + y); }

bool bad(int i, int j) {
	return u(i, j) && !u(i - 1, j) && !u(i + 1, j) && !u(i, j - 1) && !u(i, j + 1);
}

void unite(int i, int j) {
	c[i] += c[j];
	p[j] = i;
}

vi adj[1024 * 1024];

void updc(int i) {
	if (c[i] < 0) {
		int z = 0;
		for (int j : adj[i])
			if (c[j] >= 0)
				z |= 1 << (c[j] - '0');
		c[i] = '0' + __builtin_ctz(~z);
	}
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	REP (i, n) scanf("%s", s[i]);
	REP (i, n) REP (j, m) {
		if (!u(i, j)) continue;
		p[i * m + j] = i * m + j;
		c[i * m + j] = 1;
		if (bad(i, j)) {
			puts("-1");
			return 0;
		}
	}
	REP (i, n) REP (j, m) if (u(i, j) && !b[i][j]) {
		int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
		REP (k, 4) {
			int x = i + dx[k], y = j + dy[k];
			if (u(x, y) && !b[x][y]) {
				b[i][j] = b[x][y] = true;
				unite(f(i, j), f(x, y));
				break;
			}
		}
	}
	REP (i, n) {
		REP (j, m) if (u(i, j) && !b[i][j]) {
			int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
			REP (k, 4) {
				int x = i + dx[k], y = j + dy[k];
				if (u(x, y) && c[f(x, y)] + c[f(i, j)] <= 5) {
					unite(f(x, y), f(i, j));
					b[i][j] = true;
					break;
				}
			}
		}
	}
	REP (i, n) REP (j, m) if (u(i, j)) {
		if (u(i + 1, j) && f(i, j) != f(i + 1, j)) {
			adj[f(i, j)].pb(f(i + 1, j));
			adj[f(i + 1, j)].pb(f(i, j));
		}
		if (u(i, j + 1) && f(i, j) != f(i, j + 1)) {
			adj[f(i, j)].pb(f(i, j + 1));
			adj[f(i, j + 1)].pb(f(i, j));
		}
		c[f(i, j)] = -1;
	}
	REP (i, n) REP (j, m) if (u(i, j)) {
		updc(f(i, j));
		s[i][j] = c[f(i, j)];
	}
	REP (i, n) puts(s[i]);
	return 0;
}