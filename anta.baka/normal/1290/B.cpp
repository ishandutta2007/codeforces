#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<vector<int>> cnt(s.size(), vector<int>(26));
	for (int i = 0; i < s.size(); i++) {
		if (i) {
			cnt[i] = cnt[i - 1];
		}
		cnt[i][s[i] - 'a']++;
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		if (s[l] != s[r] || l == r) {
			cout << "Yes\n";
		}
		else {
			int uniq = 0;
			for (int c = 0; c < 26; c++) {
				uniq += (cnt[r][c] - (l ? cnt[l - 1][c] : 0)) > 0;
			}
			cout << (uniq >= 3 ? "Yes\n" : "No\n");
		}
	}
}