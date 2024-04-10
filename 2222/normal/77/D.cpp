#define __USE_MINGW_ANSI_STDIO    0

#include <functional>
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

#define all(a)		(a).begin(), (a).end()

typedef long long int64;

const int mod = 1000000007;

inline int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
inline int mul(int x, int y) { return (int64)x * y % mod; }

int n, m;
char s[1111][1111];
int a[255][255];

bool can(int i, int j) {
	if (j < 1 || (a[i][j] & a[i][j - 1] & 1) == 0) return false;
	int k = 0;
	for (; k < i; ) {
		if ((a[k][j] & a[k][j - 1] & 2) == 0) return false;
		++k;
		if ((a[k][j] & a[k][j - 1] & 2) == 0) return false;
		++k;
	}
	if (k != i) return false;
	++k;
	for (; k < n; ) {
		if ((a[k][j] & a[k][j - 1] & 2) == 0) return false;
		++k;
		if ((a[k][j] & a[k][j - 1] & 2) == 0) return false;
		++k;
	}
	if (k != n) return false;
	return true;
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> m;
	for (int i = 0; i < 4 * n + 1; ++i) scanf("%s", s[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			for (int x = 0; x < 3; ++x)
				for (int y = 0; y < 3; ++y) 
					a[i][j] += s[1 + i * 4 + x][1 + j * 4 + y] == 'O';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			if (a[i][j] == 6)
				a[i][j] = s[1 + i * 4][2 + j * 4] == 'O' ? 1 : 2;
			else if (2 <= a[i][j] && a[i][j] <= 3) 
				a[i][j] = s[1 + i * 4][1 + j * 4] == 'O' ? 1 : 2;
			else 
				a[i][j] = 3;
	if (m == 1) {
		if (n % 2) {
			puts("0");
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			if ((a[i][0] & 2) == 0) {
				puts("0");
				return 0;
			}
		}
		puts("1");
		return 0;
	}
	vector<int> f = {1};
	for (int j = 0; j < m; ++j) {
		int k = 0, res = 0;
		bool ok = true;
		for (int i = 0; i < n; ++i)
			if ((a[i][j] & 2) == 0) ok = false;
		if (ok && (n % 2 == 0)) res = f[j];
		if (j > 0) {
			vector<int> g = {1};
			for (int i = 0; i < n; ++i) {
				int t = 0;
				if ((a[i][j] & a[i][j - 1]) & 1)
					t = add(t, g[i]);
				if (i > 0 && ((a[i][j] & a[i - 1][j] & a[i][j - 1] & a[i - 1][j - 1]) & 2))
					t = add(t, g[i - 1]);
				g.push_back(t);
			}
			if (n % 2 == 0)
				for (int i = 0; ; ++i)
					if (i == n) {
						--g.back();
						break;
					} else if ((a[i][j] & a[i][j - 1] & 2) == 0)
						break;
			res = add(res, mul(g.back(), f[j - 1]));
		}
		f.push_back(res);
	}
	cout << f.back() << endl;
	return 0;
}