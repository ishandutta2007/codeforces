#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// :25

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	string res;
	while (!s.empty()) {
		if (s.size() & 1) {
			res += s[0];
			s = s.substr(1);
		} else {
			res += s.back();
			s.pop_back();
		}
	}

	reverse(res.begin(), res.end());
	cout << res << endl;
	return 0;
}