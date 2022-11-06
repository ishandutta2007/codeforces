#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	vector<int> occ[26];
	for (int i = 0; i < n; ++i)
		occ[s[i] - 'a'].push_back(i);

	int m;
	cin >> m;
	while (m--) {
		string t;
		cin >> t;
		array<int, 26> occ2;
		occ2.fill(0);
		for (char c : t)
			++occ2[c - 'a'];

		int ans = 0;
		for (int i = 0; i < 26; ++i) {
			if (!occ2[i])
				continue;
			assert((int )occ[i].size() >= occ2[i]);
			ans = max(ans, occ[i][occ2[i] - 1] + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}