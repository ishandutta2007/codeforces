#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(20);
	int n;
	string s;
	cin >> n >> s;
	int nn = n;
	while (true) {
		int pos = -1;
		for (int i = 0; i < n; i++) {
			if ((i > 0 && s[i - 1] + 1 == s[i]) || (i < n - 1 && s[i + 1] + 1 == s[i])) {
				if (pos == -1 || s[pos] < s[i]) {
					pos = i;
				}
			}
		}
		if (pos == -1)
			break;
		s.erase(s.begin() + pos);
	}
	cout<<nn-s.size() << endl;
	return 0;
}