#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int K;

struct DS {
	vector<int> perm, invPerm;

	DS() {
		perm.resize(K + 1, 0);
		invPerm.resize(K + 1, 0);
	}

	bool _set(const int i, const int j) {
		if (perm[i] == j)
			return true;
		if (perm[i] || invPerm[j])
			return false;
		perm[i] = j;
		invPerm[j] = i;
		return true;
	}

	bool set(const char c, const char d) {
		return _set(int(c - 'a' + 1), int(d - 'a' + 1));
	}

	char get(const char c) const {
		const int res = perm[int(c - 'a' + 1)];
		return res ? char(res - 1 + 'a') : 0;
	}

	void complete() {
		for (int i = 1; i <= K; ++i) {
			if (perm[i])
				continue;
			for (int j = 1; j <= K; ++j)
				if (!invPerm[j]) {
					perm[i] = j;
					invPerm[j] = i;
					break;
				}
		}
		for (int i = 1; i <= K; ++i)
			assert(perm[i] && invPerm[i]);
	}

	void apply(string &s) const {
		for (char &c : s)
			c = get(c);
	}

	void print() const {
		for (char c = 'a'; c < 'a' + K; ++c)
			cout << get(c);
		cout << '\n';
	}
};

pair<bool, DS> f(const string &a, const string &s, int k) {
	const int n = (int) a.size();
	// assert(n == (int )s.size() && k <= n);

	DS ds;
	for (int i = 0; i < k; ++i)
		if (!ds.set(s[i], a[i]))
			return {false, ds};

	for (; k < n; ++k) {
		char c = ds.get(s[k]);
		if (c) {
			if (c < a[k])
				return {false, ds};
			if (c == a[k])
				continue;
			break;
		}
		c = a[k] + 1;
		while (c < 'a' + K && !ds.set(s[k], c))
			++c;
		if (c < 'a' + K)
			break;
		if (!ds.set(s[k], a[k]))
			return {false, ds};
	}

	for (; k < n; ++k)
		if (!ds.get(s[k])) {
			for (char c = 'a';; ++c) {
				assert(c < 'a' + K);
				if (ds.set(s[k], c))
					break;
			}
		}

	ds.complete();

	return {true, ds};
}

// :22

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string s, a, b;
		cin >> K >> s >> a >> b;

		const int n = (int) s.size();
		int lo = -1, hi = n;
		while (lo < hi) {
			const int mid = (lo + hi + 1) / 2;
			if (f(a, s, mid).first)
				lo = mid;
			else
				hi = mid - 1;
		}
		if (lo < 0) {
			cout << "NO\n";
			cerr << "no 1\n";
			continue;
		}
		const DS ds = f(a, s, lo).second;
		assert(f(a, s, lo).first && (lo == n || !f(a, s, lo + 1).first));

		ds.apply(s);

		assert(a <= s);
		if (s <= b) {
			cout << "YES\n";
			ds.print();
		} else {
			cerr << "no 2\n";
			cerr << lo << ' ' << s << endl;
			cout << "NO\n";
		}
	}
	return 0;
}