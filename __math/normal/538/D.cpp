#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

char s[50][51];
char ans[200][200];
char test[50][51];

int main() {
	int n; cin >> n;
	FOR(i, n) cin >> s[i];
	vector<Pii> v;
	FOR(i, n) FOR(j, n) if (s[i][j] == 'o') v.push_back(Pii(i, j));
	for (int dx = -n+1; dx < n; dx++) {
		for (int dy = -n+1; dy < n; dy++) {
			bool ok = true;
			for (auto& p : v) {
				int nx = p.first + dx, ny = p.second + dy;
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (s[nx][ny] == '.') ok = false;
				}
			}
			ans[dx + n - 1][dy + n - 1] = ok ? 'x' : '.';
		}
	}
	ans[n-1][n-1] = 'o';
	FOR(i, n) FOR(j, n) test[i][j] = '.';
	for (auto& p : v) {
		for (int dx = -n+1; dx < n; dx++) {
			for (int dy = -n+1; dy < n; dy++) {
				if (ans[dx + n-1][dy + n-1] != 'x') continue;
				int nx = p.first + dx, ny = p.second + dy;
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					test[nx][ny] = 'x';
				}
			}
		}
	}
	for (auto& p : v) test[p.first][p.second] = 'o';

	bool yes = true;
	FOR(i, n) FOR(j, n) if (s[i][j] != test[i][j]) yes = false;
	if (yes) {
		puts("YES");
		FOR(i, 2 * n - 1) cout << ans[i] << endl;
	} else {
		puts("NO");
	}
}