#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static int cs[(int) 3e5 + 9][3];

pair<int, string> f(string s, array<int, 3> occ) {

	int changes = 0;

	const int n = (int) s.size();
	for (const char &c : s)
		--occ[c - '0'];

	fill(cs[n], cs[n] + 3, 0);
	for (int i = n - 1; i >= 0; --i) {
		copy(cs[i + 1], cs[i + 1] + 3, cs[i]);
		cs[i][s[i] - '0']++;
	}
	for (int i = 0; i < n; ++i) {
		char &c = s[i];

		if (occ[c - '0'] >= 0)
			continue;

		bool ok = false;
		for (char d = '0'; d < c; ++d)
			if (occ[d - '0'] > 0) {
				++changes;
				occ[c - '0']++;
				occ[d - '0']--;
				ok = true;
				c = d;
				break;
			}

		if (ok)
			continue;

		if (-occ[c - '0'] < cs[i][c - '0'])
			continue;

		assert(-occ[c - '0'] == cs[i][c - '0']);

		for (char d = c + 1; d <= '2'; ++d)
			if (occ[d - '0'] > 0) {
				++changes;
				occ[c - '0']++;
				occ[d - '0']--;
				ok = true;
				c = d;
				break;
			}

		assert(ok);
	}
	assert(!occ[0] && !occ[1] && !occ[2]);
	return {changes, s};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	pair<int, string> res = f(s, array<int, 3> { n / 3, n / 3, n / 3 });

	cout << res.second;
	return 0;
}