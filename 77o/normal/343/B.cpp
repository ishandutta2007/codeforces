#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	for (char c; cin >> c;) {
		if (!s.empty() && c == s.back()) {
			s.pop_back();
		} else {
			s += c;
		}
	}
	if (s.empty()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
    return 0;
}