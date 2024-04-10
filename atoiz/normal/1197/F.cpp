/*input
3
3 4 5
2
1 1 1
2 2 2
1 1 1
1 0 0
0 1 1
 
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
typedef vector<ll> vl;
#define fi first
#define se second
 
const long long MOD = 998244353;
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
 
typedef vector<vector<intmod>> Matrix;
const int LOG = 32;
Matrix mat[4][LOG];
 
const int MAXN = 1020;
int N, A[MAXN], F[3][3], M;
vector<pii> vec[MAXN];
 
Matrix operator* (Matrix m1, Matrix m2)
{
	assert(!m1.empty() && !m2.empty() && SZ(m1[0]) == SZ(m2));
	Matrix ans(SZ(m1), vector<intmod>(SZ(m2[0]), 0));
	FOR(i, 0, SZ(m1) - 1) FOR(j, 0, SZ(m1[0]) - 1) FOR(k, 0, SZ(m2[0]) - 1) {
		ans[i][k] += m1[i][j] * m2[j][k];
	}
	return ans;
}

int cmp(int i, int j, int k) { return i * 16 + j * 4 + k; }
void createMatrix()
{
	FOR(i, 0, 3) mat[i][0].assign(64, vector<intmod>(64, 0)); // (mex 0) * 9 + (mex -1) * 3 + (mex -2)
 
	FOR(col, 0, 2) FOR(m1, 0, 3) FOR(m2, 0, 3) FOR(m3, 0, 3) {
		vector<bool> B(4, 0);
		if (F[col][0]) B[m1] = 1;
		if (F[col][1]) B[m2] = 1;
		if (F[col][2]) B[m3] = 1;
		int m0 = -1;
		FOR(i, 0, 3) if (!B[i]) { m0 = i; break; }
		assert(m0 >= 0);
		mat[col][0][cmp(m1, m2, m3)][cmp(m0, m1, m2)] += 1;
		mat[3][0][cmp(m1, m2, m3)][cmp(m0, m1, m2)] += 1;
	}
 
	FOR(c, 3, 3) FOR(lg, 1, LOG - 1) mat[c][lg] = mat[c][lg - 1] * mat[c][lg - 1];
}
 
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	scanf("%d", &N);
	FOR(i, 1, N) scanf("%d", &A[i]);
	scanf("%d", &M);
	FOR(i, 0, M - 1) {
		int x, y, c; scanf("%d %d %d", &x, &y, &c);
		vec[x].emplace_back(y, c - 1);
	}
 
	FOR(i, 0, 2) FOR(j, 0, 2) scanf("%d", &F[i][j]);
	createMatrix();
 
	vector<intmod> curCnt = {1, 0, 0, 0};
	FOR(i, 1, N) {
		Matrix cur(1, vector<intmod>(64, 0)); cur[0][cmp(3, 3, 3)] = 1;
		int id = 0;
 
		sort(ALL(vec[i]));
		FORA(x, vec[i]) {
			int y = x.fi, c = x.se;
			if (y - 1 > id) {
				int p = y - 1 - id;
				FOR(i, 0, LOG - 1) {
					if ((p >> i) & 1) cur = cur * mat[3][i];
				}
			}
			cur = cur * mat[c][0];
			id = y;
		}
 
		if (id < A[i]) {
			int p = A[i] - id;
			FOR(i, 0, LOG - 1) {
				if ((p >> i) & 1) cur = cur * mat[3][i];
			}
		}
 
		vector<intmod> nxtCnt = {0, 0, 0, 0};
		FOR(m0, 0, 3) {
			intmod cnt = 0;
			FOR(m1, 0, 3) FOR(m2, 0, 3) cnt += cur[0][cmp(m0, m1, m2)];
			FOR(i, 0, 3) nxtCnt[i ^ m0] += curCnt[i] * cnt;
		}
		curCnt = nxtCnt;
	}
 
	cout << curCnt[0] << endl;
 
	return 0;
}