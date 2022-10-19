#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int j = 0; j < n; j++)
			cin >> a[j];
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		for (int j = 0; j < n; j++)
			cout << a[j] << " ";
		cout << endl;
	}
	return 0;
}