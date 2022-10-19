#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s;
	cin >> n >> s;
	if (s / n >= 2) {
		int s1 = s;
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << (s1 - 1) / (n - i) + 1 << ' ';
			s1 = s1 - ((s1 - 1) / (n - i) + 1);
		}
		cout << "\n";
		cout << 1;
	}
	else
		cout << "NO";
	return 0;
}