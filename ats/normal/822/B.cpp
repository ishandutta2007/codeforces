#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	string s, t;
	cin >> n >> m;
	cin >> s;
	cin >> t;
	int res = 1000000;
	int diff = 0;
	vector<int> res2;
	vector<int> tmp;
	for (int i = 0; i < m - n + 1; i++) {
		diff = 0;
		tmp.clear();
		for (int j = 0; j < n; j++) {
			if (s[j] != t[i+j]) {
				diff++;
				tmp.push_back(j);
			}
		}
		if (res > diff) {
			res = diff;
			res2 = tmp;
		}
	}
	cout << res << endl;
	for (int i = 0; i < res; i++) {
		if (i > 0)cout << " ";
		cout << (res2[i]+1);
	}
	cout << endl;
}