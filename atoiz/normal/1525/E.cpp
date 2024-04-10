/*input
3 5
1 4 4 3 4
1 4 1 4 2
1 4 4 4 3

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>
#include <array>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

const int MOD = 998244353;
struct intmod
{
	int val;

	intmod(int64_t _val = 0) { val = (int) (_val % MOD); val += (val < 0 ? MOD : 0); }

	bool operator!=(intmod rhs) const { return val != rhs.val; }
	bool operator==(intmod rhs) const { return val == rhs.val; }

	intmod& operator+=(intmod rhs) { val += rhs.val; val -= (val >= MOD ? MOD : 0); return *this; }
	intmod& operator-=(intmod rhs) { val -= rhs.val; val += (val < 0 ? MOD : 0); return *this; }
	intmod& operator*=(intmod rhs) { val = (int) ((int64_t) val * rhs.val % MOD); return *this; }

	friend intmod operator+(intmod lhs, intmod rhs) { return lhs += rhs; }
	friend intmod operator-(intmod lhs, intmod rhs) { return lhs -= rhs; }
	friend intmod operator*(intmod lhs, intmod rhs) { return lhs *= rhs; }

	friend intmod sqr(intmod a) { return a * a; }
	friend intmod bpow(intmod a, int p) { intmod ans(1); while (p) { if (p & 1) ans *= a; a = sqr(a); p >>= 1; } return ans; }
	friend intmod inv(intmod a) { return bpow(a, MOD - 2); }

	intmod& operator/=(intmod rhs) { return (*this) *= inv(rhs); }
	friend intmod operator/(intmod lhs, intmod rhs) { return lhs /= rhs; }

	friend istream& operator>>(istream &is, intmod &im) { return is >> im.val; }
	friend ostream& operator<<(ostream &os, intmod im) { return os << im.val; }
};


// start of code

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> d(m, vector<int>(n));
	FOR(i, 0, n - 1) FOR(j, 0, m - 1) cin >> d[j][i];
	intmod ans = m;
	
	intmod mult = 1;
	FOR(i, 1, n) mult /= i;

	FORA(a, d) {
		intmod cur = 1;
		sort(ALL(a));
		FOR(i, 0, n - 1) {
			// cout << min(a[i], n + 1) - i - 1 << ' ';
			cur *= max(0, min(a[i], n + 1) - i - 1);
		}
		// cout << endl;
		// cout << cur << endl;
		ans -= cur * mult;
	}
	cout << ans << endl;

	return 0;
}