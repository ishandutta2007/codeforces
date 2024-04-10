#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
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
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

int fastMin(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ x; }
int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
ll fastMin(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ x; }
ll fastMax(ll x, ll y) { return (((y - x) >> (64 - 1))&(x^y)) ^ y; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int n, m;
char c[1000][1001];
int dp[1005][1005];

int main() {
	cin >> n >> m;
	FOR(i, n) cin >> c[i];

	Pii s(-1,-1),e;
	FOR(i, n) FOR(j, m) {
		if (c[i][j] == 'X') {
			if(s.first == -1) s = Pii(i, j);
			e = Pii(i, j);
		}
	}
	if (s.first == -1) {
		puts("0");
		return 0;
	}

	int hmove = e.first - s.first, wmove = e.second - s.second;
	if (hmove < 0 || wmove < 0) {
		puts("-1");
		return 0;
	}
	int ans = ten(8);
	FOR(i, n + 3) FOR(j, m + 3) dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + (c[i][j] == 'X');
	const int sum = dp[n][m];
	for (int h = 1; h <= hmove + 1; h++) for (int w = 1; w <= wmove + 1; w++) {
		int _sum = h*w + h*(wmove + 1 - w) + w*(hmove + 1 - h);
		if (sum != _sum) continue;
		int x = dp[s.first + h][s.second + w] - dp[s.first + h][s.second] - dp[s.first][s.second + w] + dp[s.first][s.second];
		if (x != h * w) continue;
		Pii cur = s;
		bool ok = true;
		while (cur.first + h != e.first + 1 || cur.second + w != e.second + 1) {
			int _h = cur.first + 1, _w = cur.second;
			int a = dp[_h + h][_w + w] - dp[_h + h][_w] - dp[_h][_w + w] + dp[_h][_w];
			if (a == h * w) {
				cur.first++;
				continue;
			}
			_h = cur.first , _w = cur.second + 1;
			a = dp[_h + h][_w + w] - dp[_h + h][_w] - dp[_h][_w + w] + dp[_h][_w];
			if (a == h * w) {
				cur.second++;
				continue;
			}
			ok = false;
			break;
		}
		if (ok) {
			ans = min(ans, h*w);
		}
	}
	if (ans == ten(8)) ans = -1;
	cout << ans << endl;

	return 0;
}