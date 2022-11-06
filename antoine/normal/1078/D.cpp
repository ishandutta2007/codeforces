#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// :37

const int Max3N = (int) 3e5 + 9;
const int MaxLg = 19;

int n;
int a[Max3N + 9];

struct Range {
	int l = -1, r = -2;

	Range() {}

	Range(const int _l, const int _r) {
		l = max(_l, 0);
		r = min(_r, 3 * n - 1);
	}

	Range(const Range &r1, const Range &r2) {
		l = min(r1.l, r2.l);
		r = max(r1.r, r2.r);
	}

	Range operator+(const int x) const {
		return Range(l + x, r + x);
	}
	Range operator-(const int x) const {
		return *this + (-x);
	}

	int size() const {
		return r - l + 1;
	}
};

Range dp[Max3N + 9][MaxLg + 1];

struct STable {
	struct Val {
		int iL = -1, iR = 2;

		Val(){}
		Val(const int i) : iL(i), iR(i) {}

		Val(const Val &v1, const Val &v2) {
			auto left = [](const int i) {return i - a[i];};
			auto right = [](const int i) {return i + a[i];};
			iL = left(v1.iL) < left(v2.iL) ? v1.iL : v2.iL;
			iR = right(v1.iR) > right(v2.iR) ? v1.iR : v2.iR;
		}
	};

	int pre[Max3N + 9]; // pre[i]: biggest k s.t. 2^k <= i
	Val table[(int) Max3N + 9][MaxLg + 1];

	STable() {
		for (int i = 1, k = 0; i <= Max3N; ++i)
			pre[i] = (1 << (k + 1)) <= i ? ++k : k;

		assert(pre[Max3N] <= MaxLg);
	}

	void init() {
		for (int i = 3 * n - 1; i >= 0; --i) {
			table[i][0] = Val(i, i);

			for (int j = 1; i + (1 << j) <= 3 * n; ++j)
				table[i][j] = Val(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}

	Val query(const int l, const int r) {
		const int k = pre[r - l + 1];
		return Val(table[l][k], table[r + 1 - (1 << k)][k]);
	}
} sTable;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	copy(a, a + n, a + n);
	copy(a, a + n, a + 2 * n);

	sTable.init();

	for (int i = 0; i < 3 * n; ++i)
		dp[i][0] = Range(i - a[i], i + a[i]);

	for (int k = 1; k <= MaxLg; ++k) {
		for (int i = n; i < 2 * n; ++i) {
			const STable::Val val = sTable.query(dp[i][k - 1].l, dp[i][k - 1].r);
			dp[i][k] = Range(dp[val.iL][k - 1], dp[val.iR][k - 1]);
		}
		for (int i = 0; i < n; ++i)
			dp[i][k] = dp[i + n][k] - n;
		for (int i = 2 * n; i < 3 * n; ++i)
			dp[i][k] = dp[i - n][k] + n;
	}

	for (int i = n; i < 2 * n; ++i) {
		int res = 0;
		Range curr(i, i);
		for (int k = MaxLg; k >= 0; --k) {
			const STable::Val val = sTable.query(curr.l, curr.r);
			const Range temp(dp[val.iL][k], dp[val.iR][k]);
			if (temp.size() < n) {
				curr = temp;
				res += 1 << k;
			}
		}
		cout << ++res << ' ';
	}
	return 0;
}