#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int cnt = count(s.begin(), s.end(), '(');

	for (char &c : s)
		if (c == '?') {
			if (cnt < n / 2) {
				c = '(';
				++cnt;
			} else
				c = ')';
		}

	cerr << s << endl;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += s[i] == '(' ? 1 : -1;
		if (sum < 0 || ((!sum) != (i == n - 1))) {

			cout << ":(";
			return 0;
		}
	}
	cout << s;
	return 0;
}