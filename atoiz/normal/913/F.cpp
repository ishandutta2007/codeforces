/*input
4
1 2

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

// start of code

const int MOD = 998244353;
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

const int MAXN = 2007;
int N, A, B;
intmod P, powP[MAXN], powQ[MAXN], F[MAXN], G[MAXN], H[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> A >> B;
	P = (intmod) A / B;
	powP[0] = powQ[0] = 1;
	FOR(i, 1, N) powP[i] = powP[i - 1] * P, powQ[i] = powQ[i - 1] * (1 - P);

	F[0] = F[1] = G[1] = 1;
	FOR(n, 2, N) {
		FORB(i, n, 1) F[i] = F[i - 1] * powQ[n - i] + F[i] * powP[i];

		G[n] = 1;
		FOR(i, 1, n - 1) G[n] -= G[i] * F[i];

		H[n] = 0;
		intmod tot = 0;
		FOR(i, 1, n - 1) tot += F[i] * G[i] * (H[i] + H[n - i] + (n * (n - 1) / 2 - (n - i) * (n - i - 1) / 2));
		H[n] = (tot + F[n] * G[n] * n * (n - 1) / 2) / (1 - F[n] * G[n]);
	}

	cout << H[N] << endl;
	return 0;
}