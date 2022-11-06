#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPal(const string &s) {
	for (int i = 0, j = (int) s.size() - 1; i < j; ++i, --j)
		if (s[i] != s[j])
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	const int n = (int) s.size();
	if (set<char>(s.begin(), s.begin() + n / 2).size() <= 1) {
		cout << "Impossible";
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		const string t = s.substr(i) + s.substr(0, i);
		if (t != s && isPal(t)) {
			cout << 1;
			return 0;
		}
	}
	cout << 2;
	return 0;
}