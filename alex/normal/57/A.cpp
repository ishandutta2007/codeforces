#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ldb;
typedef long long int64;

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 2e18;

#define y1 qqqqqqq
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pii pair < int, int >
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define fs first
#define sc second

int n, x1, y1, x2, y2, x[10], y[10], dist[10], dist2[10];
int u[2000][2000];
int const dx[4] = {0, 0, 1, -1};
int const dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, int d)
{
	u[x][y] = d;
	forn(i, 4)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx > n || yy < 0 || yy > n) continue;
		if (x == xx && (x == 0 || x == n) && u[xx][yy] > d + 1) dfs(xx, yy, d + 1);
		if (y == yy && (y == 0 || y == n) && u[xx][yy] > d + 1) dfs(xx, yy, d + 1);
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> x1 >> y1 >> x2 >> y2;
	forn(i, n + 1)
		forn(j, n + 1)
			u[i][j] = 1000000;
	dfs(x1, y1, 0);
	cout << u[x2][y2] << endl;

	return 0;
}