#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cout << (s[0] == s.back() ? "-1" : s) << '\n';
	}
	return 0;
}