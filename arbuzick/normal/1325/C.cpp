#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n - 1), b(n - 1);
	vector<vector<int>> m(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i] >> b[i];
		m[a[i] - 1].push_back(b[i] - 1);
		m[b[i] - 1].push_back(a[i] - 1);
	}
	int ind1, ind2;
	ind1 = n - 2;
	ind2 = 0;
	for (int i = 0; i < n - 1; i++) {
		if (m[a[i] - 1].size() == 1 || m[b[i] - 1].size() == 1) {
			cout << ind2 << endl;
			ind2 += 1;
		}
		else {
			cout << ind1 << endl;
			ind1 -= 1;
		}
	}
	return 0;
}