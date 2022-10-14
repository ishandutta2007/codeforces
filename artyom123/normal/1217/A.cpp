#include <bits/stdc++.h>

using namespace std;

#define pb push_back

mt19937 gen(time(0));

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int t;
	cin >> t;
	while (t--) {
		int str, inte, exp;
		cin >> str >> inte >> exp;
		if (inte + exp - str < 0) {
			cout << exp + 1 << "\n";
			continue;
		}
		int k = (inte + exp - str) / 2 + 1;
		cout << max(0, exp - k + 1) << "\n";
	}
	return 0;
}