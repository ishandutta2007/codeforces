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
		int n, x;
		cin >> n >> x;
		vector<int> l(n);
		int j, m;
		m = 0;
		for (j = 0; j < n; j++) {
			cin >> l[j];
			m = max(m, l[j]);
		}
		ans[i] = max(0, x / m - 1);
		if ((x - ans[i]*m) % m != 0)
			ans[i] += 2;
		else
			ans[i] += 1;
		for (j = 0; j < n; j++) {
			if (x % l[j] == 0 && x / l[j] < ans[i])
				ans[i] = x / l[j];
		}

	}
	for (i = 0; i < t; i++)
		cout << ans[i] << endl;
	return 0;
}