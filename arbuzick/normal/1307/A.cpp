#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	int i;
	vector<int> ans(t);
	for (i = 0; i < t; i++) {
		int n, d;
		cin >> n >> d;
		int j;
		vector<int> a(n);
		for (j = 0; j < n; j++)
			cin >> a[j];
		int ost;
		ans[i] = a[0];
		ost = d;
		for (j = 1; j < n; j++) {
			ans[i] += min(ost / j, a[j]);
			if (ost / j < a[j])
				ost = ost - ost / j * j;
			else
				ost = ost - a[j] * j;
		}
	}
	for (i = 0; i < t; i++)
		cout << ans[i] << endl;
	return 0;
	}