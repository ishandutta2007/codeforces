#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int q;
	cin >> q;
	int i;
	vector<int> t(100), l(100), h(100);
	vector<int> ans(q);
	for (i = 0; i < q; i++) {
		int n, m;
		cin >> n >> m;
		int j;
		for (j = 0; j < n; j++)
			cin >> t[j] >> l[j] >> h[j];
		int tv, tn;
		for (j = 0; j < n; j++) {
			int v;
			if (j == 0) {
				v = t[j];
				if (m + v < l[j] || m - v > h[j]) {
					ans[i] = -1;
					break;
				}
				else {
					tv = min(h[j], m + v);
					tn = max(l[j], m - v);
				}

			}
			else {
				v = t[j] - t[j - 1];
				if (tv + v < l[j] || tn - v > h[j]) {
					ans[i] = -1;
					break;
				}
				else {
					tv = min(h[j], tv + v);
					tn = max(l[j], tn - v);
				}
			}
		}
	}
	for (i = 0; i < q; i++) {
		if (ans[i] == -1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
	}