#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;

	bool ans = false;
	for (int d = 1; d <= n; ++d)
		for (int i = 0; i + 4 * d < n; ++i) {
			bool good = true;
			for (int j = 0; j <= 4; ++j)
				good &= s[i + d * j] == '*';
			ans |= good;
		}

	if (ans)
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;
}