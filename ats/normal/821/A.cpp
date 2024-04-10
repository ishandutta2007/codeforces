#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	string res;
	res = "Yes";
	bool f;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 1) {
				f = false;
				for (int i1 = 0; i1 < n; i1++) {
					for (int j1 = 0; j1 < n; j1++) {
						if (a[i][j] == a[i][i1] + a[j1][j]) {
							f = true;
						}
					}
				}
				if (!f) {
					res = "No";
				}
			}
		}
	}
	
	cout << res << endl;
	return 0;
	
}