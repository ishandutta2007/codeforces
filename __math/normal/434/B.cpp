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

using namespace std;
const int MOD = 1000000007; // check!!!
const int INF = 100000000; //1e8

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

inline int fastMin(int x, int y) { return x > y ? y : x; }
inline int fastMax(int x, int y) { return (((y - x) >> (32 - 1))&(x^y)) ^ y; }
inline int fastAbs(int x) { return ((x >> (32 - 1))&(x ^ (-x))) ^ x; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

// 1-indexed
template<class T>
class BIT {
	T bit[1001];
	int n;

public:
	BIT() {}

	BIT(int N) {
		clear(N);
	}

	void clear(int N) {
		n = N;
		memset(bit, 0, sizeof(bit));
	}

	T sum(int i) {
		T s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	//[a,b] 0-indexed	
	int sum(int a, int b) {
		return sum(b + 1) - sum(a);
	}

	//0-indexed
	int left_bound(int i) {
		int l = -1, r = i;
		int S = sum(i + 1);
		while (r - l != 1) {
			int md = (r + l) / 2;
			int val = sum(md);
			if (S - val == i - md + 1) r = md;
			else l = md;
		}
		return r;
	}

	//0-indexed
	int right_bound(int i) {
		int l = i, r = n;
		int S = sum(i);
		while (r - l != 1) {
			int md = (r + l) / 2;
			int val = sum(md + 1);
			if (val - S == md - i + 1) l = md;
			else r = md;
		}
		return l;
	}

	void add(int i, T x) {
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int solve(int a[1000][1000], BIT<int> r[1000], int x, int y, int n, int m) {
	int ans = 0;
	{
		int _ux = x - 1, _dx = x - 1;
		while (_ux > 0 && a[_ux - 1][y - 1]) _ux--;
		while (_dx < n - 1 && a[_dx + 1][y - 1]) _dx++;
		{
			int ux = _ux, dx = _dx;
			for (int cy = y - 1; cy >= 0; cy--) {
				if (!a[x - 1][cy]) break;
				ux = max(r[cy].left_bound(x - 1), ux);
				dx = min(r[cy].right_bound(x - 1), dx);
				int cur_ans = (dx - ux + 1) * (abs(cy - (y - 1)) + 1);
				ans = max(cur_ans, ans);
			}
		}
		{
			int ux = _ux, dx = _dx;
			for (int cy = y - 1; cy < m; cy++) {
				if (!a[x - 1][cy]) break;
				ux = max(r[cy].left_bound(x - 1), ux);
				dx = min(r[cy].right_bound(x - 1), dx);
				int cur_ans = (dx - ux + 1) * (abs(cy - (y - 1)) + 1);
				ans = max(cur_ans, ans);
			}
		}
	}
	return ans;
}
BIT<int> r[1000], c[1000];

int n, m, q;
int a[1000][1000];
int fa[1000][1000];
int main() {
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, n) FOR(j, m) {
		scanf("%d", a[i] + j);
		fa[j][i] = a[i][j];
	}
	FOR(i, n) c[i].clear(m);
	FOR(i, m) r[i].clear(n);
	FOR(i, n) FOR(j, m) {
		c[i].add(j + 1, a[i][j]);
		r[j].add(i + 1, a[i][j]);
	}
	FOR(i, q) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		if (t == 1) {
			int p = a[x - 1][y - 1] ^ 1;
			int df = p - a[x - 1][y - 1];
			a[x - 1][y - 1] = p;
			fa[y - 1][x - 1] = p;
			c[x - 1].add(y, df);
			r[y - 1].add(x, df);
		} else {
			if (!a[x - 1][y - 1]) {
				printf("0\n");
				continue;
			}

			int t1 = solve(a, r, x, y, n, m);
			int t2 = solve(fa, c, y, x, m, n);

			printf("%d\n", max(t1, t2));
		}
	}

}