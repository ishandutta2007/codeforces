#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> v(n, 1002);
	int x;
	int nums = 0;
	for (int i = 0; i < m; ++i) {
		cin >> x;
		if (x <= c / 2) {
			int j = 0;
			while (j < v.size() && v[j] <= x) j++;
			nums += (v[j] == 1002);
			v[j] = x;
			cout << j + 1 << endl;
		} else {
			int j = (int)v.size() - 1;
			while (j >= 0 && (v[j] != 1002 && x <= v[j])) j--;
			nums += (v[j] == 1002);
			v[j] = x;
			cout << j + 1 << endl;
		}
		if (nums == n)
			return 0;
	}
}