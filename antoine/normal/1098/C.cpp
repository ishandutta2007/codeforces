#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MaxN = (int) 1e5 + 9;

vector<int> f(const int n, const int d) {
	vector<int> p(n, -1);

	for (int i = 0, j = 1; j < n; ++j) {
		p[j] = i;
		i += j % d == 0;
	}
	return p;
}

ll f(vector<int> p) {
	static int cnt[MaxN + 9];
	cnt[0] = 1;
	ll ans = 1;
	for (int i = 1; i < (int) p.size(); ++i) {
		cnt[i] = cnt[p[i]] + 1;
		ans += cnt[i];
	}
	return ans;
}

int pop(vector<int> &v) {
	const int x = v.back();
	v.pop_back();
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	ll s;
	cin >> n >> s;

	int lo = 1;
	int hi = n + 1;
	while (lo < hi) {
		const int mid = (lo + hi) / 2;
		if (f(f(n, mid)) <= s)
			hi = mid;
		else
			lo = mid + 1;
	}

	vector<int> p = f(n, lo);
	s -= f(p);

	if (hi > n || (lo == 1 && s)) {
		cout << "No";
		return 0;
	}

	vector<int> depth(n, 0);

	for (int i = 1; i < n; ++i) {
		depth[i] = depth[p[i]] + 1;
	}

	map<int, int> mp;
	vector<bool> spe(n, false);

	for (int i = n - 1;; i = p[i]) {
		mp[depth[i]] = i;
		spe[i] = true;
		if (!i)
			break;
	}

	for (int i = n - 1; i >= 0 && s; --i) {
		if (spe[i])
			continue;
		const int x = (int)min(s, (ll)mp.rbegin()->first - depth[i] + 1);
		assert(x > 0);
		s -= x;
		p[i] = mp.at(depth[i] + x - 1);
		mp[mp.rbegin()->first + 1] = i;
		spe[i] = 1;
		assert(p[i] != i);
	}

	assert(!s);

	cout << "Yes\n";
	for (int i = 1; i < n; ++i)
		cout << p[i] + 1 << ' ';

	return 0;
}