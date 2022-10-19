/*input
3
2 6 8

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MOD = 1e9 + 7;
int add(int x, int y) { return x -= ((x += y) >= MOD ? MOD : 0); }
int sub(int x, int y) { return x += ((x -= y) < 0 ? MOD : 0); }
int mul(int x, int y) { return (int) ((int64_t) x * y % MOD); }

int main()
{
	int N;
	cin >> N;

	vector<int> A(N);
	for (int &x : A) cin >> x;
	int M = *max_element(A.begin(), A.end());

	vector<int> basis;
	for (int x : A) {
		bool noFactors = true;
		int cntMult = 0;
		for (int y : A) {
			if (y == x);
			else if (y % x == 0) ++cntMult;
			else if (x % y == 0) noFactors = false;
		}
		if (noFactors && cntMult >= 2) basis.push_back(x);
	}

	vector<vector<int>> choose(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i <= N; ++i) choose[i][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= i; ++j) {
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1]);
		}
	}

	vector<int> fact(N + 1, 1);
	for (int i = 2; i <= N; ++i) fact[i] = mul(fact[i - 1], i);

	auto calc = [&](vector<int> curBasis, vector<int> curVals) -> int
	{
		// for (int x : curBasis) cout << x << ' ';
		// cout << "| ";
		// for (int x : curVals) cout << x << ' ';
		int numBasis = (int) curBasis.size(), numVals = (int) curVals.size();
		for (int &x : curVals) {
			int mask = 0;
			for (int i = 0; i < numBasis; ++i) {
				if (x % curBasis[i] == 0) {
					mask |= (1 << i);
				}
			}
			assert(mask > 0);
			x = mask;
		}

		vector<int> dp(1 << numBasis, 0), subset(1 << numBasis, 0);
		for (int x : curVals) {
			for (int i = 0; i < (1 << numBasis); ++i) {
				if ((i & x) == x) {
					++subset[i];
				}
			}
		}

		for (int x : curVals) {
			dp[x] = add(dp[x], mul(choose[numVals - 1][subset[x] - 1], fact[subset[x] - 1]));
		}

		for (int i = 1; i < (1 << numBasis) - 1; ++i) {
			for (int x : curVals) if ((i & x) && (i | x) != i) {
				dp[i | x] = add(dp[i | x], mul(dp[i], mul(choose[numVals - subset[i] - 1][subset[i | x] - subset[i] - 1], fact[subset[i | x] - subset[i] - 1])));
			}
		}

		// cout << ": " << dp[(1 << numBasis) - 1] << endl;
		return dp[(1 << numBasis) - 1];
	};

	vector<bool> deadBasis(basis.size(), false), deadVals(M + 1, false);
	int curSize = 0, ans = 1;
	for (int x : basis) deadVals[x] = true;
	for (int i = 0; i < (int) basis.size(); ++i) if (!deadBasis[i]) {
		deadBasis[i] = true;
		vector<int> curBasis = {basis[i]};
		vector<int> curVals;

		bool run = true;
		while (run) {
			run = false;
			for (int x : A) if (!deadVals[x]) {
				for (int y : curBasis) if (x % y == 0) {
					deadVals[x] = true;
					curVals.push_back(x);
					run = true;
					break;
				}
			}

			for (int j = i + 1; j < (int) basis.size(); ++j) if (!deadBasis[j]) {
				for (int x : curVals) if (x % basis[j] == 0) {
					deadBasis[j] = true;
					curBasis.push_back(basis[j]);
					run = true;
					break;
				}
			}
		}

		assert((int) curVals.size() >= 2);
		ans = mul(ans, choose[curSize += (int) curVals.size() - 1][(int) curVals.size() - 1]);
		ans = mul(ans, calc(curBasis, curVals));
	}

	cout << ans << endl;
}