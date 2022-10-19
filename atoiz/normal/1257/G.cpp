/*input
3
2999999 43 2999957

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

const int MOD = 998244353;
struct intmod
{
	int val;

	intmod(long long _val = 0) { val = int(_val % MOD); val += (val < 0 ? MOD : 0); }

	bool operator!=(intmod rhs) const { return val != rhs.val; }
	bool operator==(intmod rhs) const { return val == rhs.val; }

	intmod operator+=(intmod rhs) { val += rhs.val; val -= (val >= MOD ? MOD : 0); return *this; }
	intmod operator-=(intmod rhs) { val -= rhs.val; val += (val < 0 ? MOD : 0); return *this; }
	intmod operator*=(intmod rhs) { val = int((long long) val * rhs.val % MOD); return *this; }

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

const intmod ROOT = 3;

void fft(vector<intmod> &A, bool inv = 0)
{
	int N = (int) A.size();
	int lg = __lg(N);
	for (int i = 1, j = 0; i < N; ++i) {
		int d = lg - 1;
		for (; (j >> d) & 1; --d) j ^= (1 << d);
		j ^= (1 << d);
		if (i < j) swap(A[i], A[j]);
	}

	for (int k = 1; k <= lg; ++k) {
		intmod w = bpow(ROOT, (inv ? (MOD - 1) - ((MOD - 1) >> k) : (MOD - 1) >> k));
		for (int i = 0; i < N; i += (1 << k)) {
			intmod cur = 1;
			for (int j = i; j < i + (1 << (k - 1)); ++j) {
				intmod tmp = cur * A[j + (1 << (k - 1))];
				A[j + (1 << (k - 1))] = A[j] - tmp;
				A[j] = A[j] + tmp;
				cur *= w;
			}
		}
	}

	if (inv) {
		intmod invN = bpow(intmod(N), MOD - 2);
		for (int i = 0; i < N; ++i) {
			A[i] *= invN;
		}
	}
}

vector<intmod> operator* (vector<intmod> A, vector<intmod> B)
{
	int N = 1 << (32 - __builtin_clz((int) A.size() + (int) B.size() - 1));
	while ((int) A.size() < N) A.emplace_back(0);
	while ((int) B.size() < N) B.emplace_back(0);
	fft(A);
	fft(B);
	for (int i = 0; i < N; ++i) A[i] *= B[i];
	while (!A.empty() && A.back() == 0) A.pop_back();
	fft(A, 1);
	return A;
}

bool operator< (const vector<intmod> &A, const vector<intmod> &B)
{
	return A.size() > B.size();
}

const int MAXV = 3e6 + 7;
int cnt[MAXV];

signed main()
{
	// freopen("in.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	FOR(i, 0, n - 1) {
		int p;
		cin >> p;
		++cnt[p];
	}

	priority_queue<vector<intmod>> pq;
	FOR(p, 0, MAXV - 1) if (cnt[p]) {
		pq.emplace(cnt[p] + 1, 1);
	}
	while (SZ(pq) > 1) {
		auto vec1 = pq.top(); pq.pop();
		auto vec2 = pq.top(); pq.pop();
		pq.push(vec1 * vec2);
	}

	cout << pq.top()[n / 2] << endl;

	return 0;
}