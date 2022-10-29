#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>


using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] < 0) {
			cout << a[i];
			break;
		}
		int k = sqrt(a[i]);
		if (k * k != a[i]) {
			cout << a[i];
			break;
		}
	}
	return 0;
}