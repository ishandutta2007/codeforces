#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<int> pos;
		pos.push_back(0);
		for (int i = 0; i < int(s.size()); ++i) {
			if (s[i] == 'R') pos.push_back(i + 1);
		}
		pos.push_back(s.size() + 1);
		int ans = 0;
		for (int i = 0; i < int(pos.size()) - 1; ++i) {
			ans = max(ans, pos[i + 1] - pos[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}