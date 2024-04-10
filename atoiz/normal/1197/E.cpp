/*input
7
4 1
4 2
4 2
2 1
5 4
6 4
3 2


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
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define out first
#define in second

const long long MOD = 1000000007;
struct intmod
{
	long long val;

	intmod(long long _val = 0) { val = _val % MOD; if (val < 0) val += MOD; }

	bool operator!=(intmod rhs) const { return val != rhs.val; }
	bool operator==(intmod rhs) const { return val == rhs.val; }

	intmod operator+=(intmod rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
	intmod operator-=(intmod rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
	intmod operator*=(intmod rhs) { val = val * rhs.val % MOD; return *this; }

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

const int MAXN = 200010, INF = MOD + 9;
int N;
pii A[MAXN];
int outs[MAXN], ptr = 0;
int minExtr[MAXN];
intmod numWays[MAXN];

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d", &N);
	FOR(i, 0, N - 1) scanf("%d %d", &A[i].out, &A[i].in);
	sort(A, A + N);

	outs[ptr++] = 0;
	FOR(i, 0, N - 1) if (outs[ptr - 1] != A[i].out) outs[ptr++] = A[i].out;
	outs[ptr] = INF;
	numWays[0] = 1;
	FOR(i, 1, ptr) minExtr[i] = INF;

	FOR(i, 0, N - 1) {
		int idIn = upper_bound(outs, outs + ptr + 1, A[i].in) - 1 - outs;
		int idOut = lower_bound(outs, outs + ptr + 1, A[i].out) - outs;

		int curExtr = minExtr[idIn] + A[i].in - outs[idIn];
		if (curExtr < minExtr[idOut]) {
			minExtr[idOut] = curExtr;
			numWays[idOut] = 0;
		}

		if (curExtr == minExtr[idOut]) {
			numWays[idOut] += numWays[idIn];
		}

		if (i == N - 1 || A[i].out < A[i + 1].out) {
			if (minExtr[idOut] == minExtr[idOut - 1] + outs[idOut] - outs[idOut - 1]) {
				numWays[idOut] += numWays[idOut - 1];
			}
			else if (minExtr[idOut] > minExtr[idOut - 1] + outs[idOut] - outs[idOut - 1]) {
				minExtr[idOut] = minExtr[idOut - 1] + outs[idOut] - outs[idOut - 1];
				numWays[idOut] = numWays[idOut - 1];
			}
		}
	}

	int maxIn = -1;
	FOR(i, 0, N - 1) maxIn = max(maxIn, A[i].in);

	// FOR(i, 0, ptr - 1) cout << outs[i] << ": " << minExtr[i] << ' ' << numWays[i] << endl;

	int bestMin = INF; intmod ans = 0;
	FOR(i, 0, ptr - 1) if (maxIn < outs[i]) {
		if (bestMin > minExtr[i]) {
			bestMin = minExtr[i];
			ans = 0;
		}
		if (bestMin == minExtr[i]) {
			ans += numWays[i];
		}
	}

	cout << ans << endl;

	return 0;
}