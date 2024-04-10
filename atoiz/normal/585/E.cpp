/*input
2 9 6
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

const int MOD = 1000000007;
struct intmod
{
	int val;

	intmod(int64_t _val = 0) { val = (int) (_val % MOD); val += (val < 0 ? MOD : 0); }

	bool operator!=(intmod rhs) const { return val != rhs.val; }
	bool operator==(intmod rhs) const { return val == rhs.val; }

	intmod operator+=(intmod rhs) { val += rhs.val; val -= (val >= MOD ? MOD : 0); return *this; }
	intmod operator-=(intmod rhs) { val -= rhs.val; val += (val < 0 ? MOD : 0); return *this; }
	intmod operator*=(intmod rhs) { val = (int) ((int64_t) val * rhs.val % MOD); return *this; }

	friend intmod operator+(intmod lhs, intmod rhs) { return lhs += rhs; }
	friend intmod operator-(intmod lhs, intmod rhs) { return lhs -= rhs; }
	friend intmod operator*(intmod lhs, intmod rhs) { return lhs *= rhs; }

	friend intmod sqr(intmod a) { return a * a; }
	friend intmod bpow(intmod a, int p) { intmod ans(1); while (p) { if (p & 1) ans *= a; a = sqr(a); p >>= 1; } return ans; }
	friend intmod inv(intmod a) { return bpow(a, MOD - 2); }

	intmod operator/=(intmod rhs) { return (*this) *= inv(rhs); }
	friend intmod operator/(intmod lhs, intmod rhs) { return lhs /= rhs; }

	friend istream& operator>>(istream &is, intmod &im) { return is >> im.val; }
	friend ostream& operator<<(ostream &os, intmod im) { return os << im.val; }
};


// start of code

const int MAXV = 1e7 + 7;
const intmod TWO = 2;
int lprime[MAXV], lsquare[MAXV], mobius[MAXV];
int nmul[MAXV];
intmod ntuples[MAXV], ncommon[MAXV];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	mobius[1] = 1;
	FOR(i, 2, MAXV - 1) {
		if (lprime[i] == 0) {
			lprime[i] = i;
			for (int j = (int) min((ll) i * i, (ll) MAXV); j < MAXV; j += i) {
				lprime[j] = i;
			}
		}

		if ((i / lprime[i]) % lprime[i] == 0) {
			mobius[i] = 0;
			lsquare[i] = lprime[i];
		} else {
			mobius[i] = -mobius[i / lprime[i]];
			lsquare[i] = lsquare[i / lprime[i]];
		}
	}

	int N;
	cin >> N;
	FOR(i, 0, N - 1) {
		int x;
		cin >> x;
		while (lsquare[x]) x /= lsquare[x];
		assert(mobius[x]);
		++nmul[x];
	}

	FOR(i, 2, MAXV - 1) if (mobius[i]) {
		for (int j = i + i; j < MAXV; j += i) {
			nmul[i] += nmul[j];
		}
	}

	FORB(i, MAXV - 1, 2) if (nmul[i]) {
		ntuples[i] = bpow(TWO, nmul[i]) - 1;
		for (int j = i + i; j < MAXV; j += i) {
			ntuples[i] -= ntuples[j];
		}
	}

	FOR(i, 2, MAXV - 1) if (nmul[i]) {
		for (int j = i; j < MAXV; j += i) {
			ncommon[j] -= nmul[i] * mobius[i];
		}
	}

	intmod ans = 0;
	FOR(i, 2, MAXV - 1) if (nmul[i]) {
		// cout << i << ": " << ntuples[i] << ' ' << ncommon[i] << ' ' << mobius[i] << endl;
		ans += ntuples[i] * (N - ncommon[i]);
	}
	cout << ans << endl;

	return 0;
}