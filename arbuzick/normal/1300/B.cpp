#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	vector<int> ans(t);
	int i;
	for (i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> a(n * 2);
		int j;
		for (j = 0; j < n * 2; j++)
			cin >> a[j];
		sort(a.begin(), a.end());
		ans[i] = a[n] - a[n - 1];
	}
	for (i = 0; i < t; i++)
		cout << ans[i] << endl;
	return 0;
	}