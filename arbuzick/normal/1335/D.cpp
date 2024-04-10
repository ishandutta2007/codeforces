#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> c = { 0, 3, 6, 2, 4, 7, 1, 5, 8 };
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		vector<string> s(9);
		for (int i = 0; i < 9; ++i)
			cin >> s[i];
		for (int i = 0; i < 9; ++i) {
			for (int a = 0; a < 9; ++a) {
				if (c[i] == a) {
					int p = s[i][a] - '0';
					//cout << p << endl;
					p += 1;
					if (p == 10)
						p = 1;
					char b = '0' + p;
					cout << b;
				}
				else
					cout << s[i][a];
			}
			cout << endl;
		}
	}
	return 0;
}