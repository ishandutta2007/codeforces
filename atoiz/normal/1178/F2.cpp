/*input
8 17
1 3 2 2 7 8 2 5 5 4 4 4 1 1 6 1 1


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
#define fi first
#define se second

const long long MOD = 998244353;
struct intmod
{
	long long val;

	intmod(long long _val = 1) { val = _val % MOD; if (val < 0) val += MOD; }

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

const int MAXN = 517, MAXM = 1000030, LOG = 21;

intmod F0[MAXN][MAXN], F1[MAXN][MAXN];
intmod solve(vector<int> vec)
{
	int N = SZ(vec);
	vec.insert(vec.begin(), MAXN);
	FOR(i, 0, N + 1) FOR(j, 0, N + 1) F0[i][j] = F1[i][j] = 1;
	FOR(i, 1, N) F0[i][i] = F1[i][i] = 1;
	FOR(len, 2, N) FOR(l, 1, N - len + 1) {
		int r = l + len - 1, m = l;

		FOR(i, l + 1, r) if (vec[i] < vec[m]) m = i;
		F0[l][r] = F1[l][m - 1] * F1[m + 1][r];

		F1[l][r] = 0;
		FOR(i, l, r) F1[l][r] += F0[l][i] * F1[i + 1][r];
	}

	// if (N == 4) cout << "S " << F0[1][4] << endl;

	return F1[1][N];
}

int N, M;
int A[MAXM], L[MAXN], R[MAXN];
int st[MAXN], rr = 0;

vector<int> vec[MAXN * 2];
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d %d", &N, &M);
	FOR(i, 1, M) scanf("%d", &A[i]);
	FOR(i, 1, M) {
		R[A[i]] = i;
		if (!L[A[i]]) L[A[i]] = i;
	}

	int ptr = N + 1;
	FOR(i, 1, M) {
		int last = (rr > 0 ? st[rr - 1] : 0);
		if (last > A[i]) { puts("0"); return 0; }

		if (L[A[i]] == i) {
			vec[last].push_back(A[i]);
			st[rr++] = A[i];
		}
		if (A[i] == last && !vec[last].empty()) vec[ptr++].swap(vec[last]);
		if (R[A[i]] == i) --rr;
	}

	assert(ptr < MAXN * 2);

	// FOR(i, 0, ptr) if (!vec[i].empty()) {
	// 	FORA(j, vec[i]) cout << j << ' '; cout << ": " << solve(vec[i]) << endl;
	// }

	intmod ans = 1;
	FOR(i, 0, ptr) if (!vec[i].empty()) ans *= solve(vec[i]);
	cout << ans << endl;

	return 0;
}