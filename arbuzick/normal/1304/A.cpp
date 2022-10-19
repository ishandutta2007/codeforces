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
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if ((y - x) % (a + b) != 0)
			ans[i] = -1;
		else
			ans[i] = (y - x) / (a + b);
	}
	for (i = 0; i < t; i++) {
		cout << ans[i] << endl;
	}
	return 0;
	}