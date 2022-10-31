#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> st(n);
	vector<int> added(n, 0);
	int sz = 0;
	string s;
	int k;
	int t = 0;
	int res = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> s;
		if (s == "add") {
			cin >> k;
			k--;
			st[sz] = k;
			sz++;
			added[k] = 1;
		}
		else {
			if (sz != 0) {
				if (st[sz - 1] == t) {
					sz--;
				}
				else {
					res++;
					sz = 0;
					//cerr << "A" << endl;
				}
			}
			t++;
		}
	}
	cout << res << endl;
	return 0;
}