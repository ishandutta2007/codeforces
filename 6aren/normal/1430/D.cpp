#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> a;
		int cur = 0;
		char prev = '2';
		for (char ch : s) {
			// cout << prev << ' ' << ch << endl;
			if (ch != prev) {
				if (prev != '2') {
					a.push_back(cur);
				}
				cur = 1;
			}
			else {
				cur++;
			}
			prev = ch;
		}
		a.push_back(cur);
		reverse(a.begin(), a.end());
		int cnt = 0;
		int cursor = a.size() - 1;
		int ans = 0;

		while (a.size() != 0) {
			ans++;
			while (cursor >= (int) a.size()) {
				cursor--;
				// cout << cursor << endl;
			}
			while (cursor >= 0 && a[cursor] == 1) {
				// cout << cursor << endl;
				cursor--;
			}
			if (cursor == -1) {
				a.pop_back();
				if (a.size()) a.pop_back();
			} else {
				a[cursor]--;
				a.pop_back();
			}
		}
		cout << ans << '\n';
	}

	return 0;
}