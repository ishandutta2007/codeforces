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
		for (int j = 0; j < n; ++j)
			cin >> a[j];
		sort(a.begin(), a.end());
		int s;
		s = 1;
		for (int j = 1; j < n; ++j)
			if (a[j] != a[j - 1])
				s += 1;
		cout << s << endl;
	}
	return 0;
}