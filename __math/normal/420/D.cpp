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

// 1-indexed
template<class T>
class BIT {
	T bit[ten(6) * 3 + 100];
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
	void add(int i, T x) {
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int index[ten(6) * 3 + 100];
BIT<int> bit;

int main() {
	memset(index, -1, sizeof(index));
	int n, m;
	scanf("%d%d", &n, &m);
	bit.clear(ten(6) * 2 + 30);
	FOR(i, n) bit.add(m + 1 + i, 1);

	bool ok = true;
	vector<int> ans(n);
	FOR(i, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (index[x] == -1) {
			int l = 1, r = m + n + 10;
			while (r - l != 1) {
				int md = (l + r) / 2;
				if (bit.sum(md) < y) l = md;
				else r = md;
			}
			if (r - m - 1 < 0) {
				ok = false;
				break;
			}
			ans[r - m - 1] = x;
			index[x] = r;
		}
		int cur_index = bit.sum(index[x]);
		if (cur_index != y) {
			ok = false;
			break;
		}
		bit.add(index[x], -1);
		index[x] = m - i;
		bit.add(index[x], 1);
	}

	if (!ok) {
		puts("-1");
		return 0;
	}

	vector<int> fr;
	FOR(i, n) {
		if (index[i + 1] == -1) fr.push_back(i + 1);
	}
	int cnt = 0;
	FOR(i, n) {
		if (ans[i] == 0) ans[i] = fr[cnt++];
	}
	FOR(i, n) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}