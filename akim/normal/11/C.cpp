#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 300;

int c[maxn][maxn];
bool was[maxn][maxn];

int n, m;
int cnt;
int minx, miny, maxx, maxy, cminx, cminy, cmaxx, cmaxy;
int mins, minr, maxs, maxr, cmins, cminr, cmaxs, cmaxr;

int dx[] = {-1, -1 , -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void dfs(int x, int y) {
	was[x][y] = 1;
	cnt++;
	if(minx > x) minx = x, cminx = 0;
	if(maxx < x) maxx = x, cmaxx = 0;
	if(miny > y) miny = y, cminy = 0;
	if(maxy < y) maxy = y, cmaxy = 0;
	if(minx == x) cminx++;
	if(maxx == x) cmaxx++;
	if(miny == y) cminy++;
	if(maxy == y) cmaxy++;

	if(mins > x + y) mins = x + y, cmins = 0;
	if(maxs < x + y) maxs = x + y, cmaxs = 0;
	if(minr > x - y) minr = x - y, cminr = 0;
	if(maxr < x - y) maxr = x - y, cmaxr = 0;
	if(mins == x + y) cmins++;
	if(maxs == x + y) cmaxs++;
	if(minr == x - y) cminr++;
	if(maxr == x - y) cmaxr++;

	for(int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if(nx < 0 || nx >= n) continue;
		if(ny < 0 || ny >= m) continue;
		if(was[nx][ny]) continue;
		if(c[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int t;
	scanf("%d", &t);
	for(; t--;) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) {
			scanf("\n");
			for(int j = 0; j < m; j++) {
				c[i][j] = getchar() - '0';
				was[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(was[i][j]) continue;
				was[i][j] = 1;
				if(c[i][j] == 0) continue;
				minx = miny = mod;
				maxx = maxy = -mod;
				cminx = cminy = cmaxx = cmaxy = 0;
				mins = minr = mod;
				maxs = maxr = -mod;
				cmins = cminr = cmaxs = cmaxr = 0;
				cnt = 0;
				dfs(i, j);
				if(cnt == 1) continue;
				if(cminx + cminy + cmaxx + cmaxy - 4 == cnt
						&& (maxx - minx + 1 + maxy - miny + 1) * 2 - 4 == cnt
						&& maxx - minx == maxy - miny
						) {
					ans++;
				}
				if(cmins + cminr + cmaxs + cmaxr - 4 == cnt
						&& (maxs - mins - (maxs - mins) / 2 + 1 + (maxr - minr) - (maxr - minr) / 2 + 1) * 2 - 4 == cnt
						&& maxs - mins == maxr - minr
						) {
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim