#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct OccVec: array<int, 26> {
	OccVec(const int x) {
		at(0) = at(1) = x << 1 | 1;
	}

	OccVec() {
		::fill(begin(), end(), 0);
	}

	OccVec operator+(const char c) const {
		OccVec res(*this);
		res[c - 'a']++;
		return res;
	}

	OccVec operator-(const OccVec other) const {
		OccVec res(*this);
		for (int i = 0; i < 26; ++i)
			res[i] -= other[i];
		return res;
	}

	bool palindrome() const {
		int cnt = 0;
		for (int i = 0; i < 26; ++i) {
			cnt += at(i) & 1;
			if (cnt > 1)
				return false;
		}
		return true;
	}

	bool operator==(const OccVec &other) const {
		for(int i = 0; i < 26; ++i)
			if(at(i) != other[i])
				return false;
		return true;
	}
};

vector<int> manacher(const vector<OccVec> &v, const bool even) {
	int n = (int) v.size();
	vector<int> res(n);
	int l = 0, r = -1;
	for (int i = 0; i < n; ++i) {
		int k;
		if (i > r)
			k = 1;
		else
			k = min(res[l + r - i + even], r - i + even) + 1;
		while (i + k - even < n && i - k >= 0 && v[i + k - even] == v[i - k])
			++k;
		res[i] = --k;
		if (i + k - even > r) {
			l = i - k;
			r = i + k - even;
		}
	}
	return res;
}

const int MaxN = 252;
OccVec cnts[MaxN + 1][MaxN + 1];

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	memset(cnts, 0, sizeof cnts);

	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			char c;
			cin >> c;
			cnts[i][j] = cnts[i][j - 1] + c;
		}
	}

	ll ans = 0;
	for (int c1 = 1; c1 <= m; ++c1)
		for (int c2 = c1; c2 <= m; ++c2) {
			vector<OccVec> v(n);

			for (int i = 0; i < n; ++i) {
				v[i] = cnts[i][c2] - cnts[i][c1 - 1];
				if (!v[i].palindrome())
					v[i] = OccVec(i);
			}

			vector<int> r = manacher(v, true);
			ans += accumulate(r.begin(), r.end(), 0LL);
			r = manacher(v, false);

			for (int i = 0; i < n; ++i)
				if (v[i].palindrome())
					ans += r[i] + 1;
		}
	cout << ans << '\n';
	return 0;
}