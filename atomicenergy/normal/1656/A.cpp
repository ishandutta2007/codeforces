#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		vector<int> v(n);
		int mn = 0;
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (v[i] < v[mn]) mn = i;
			if (v[i] > v[mx]) mx = i;
		}
		cout << mn + 1 << " " << mx + 1 << endl;
	}
}