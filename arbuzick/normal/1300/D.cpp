#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	if (n % 2 == 1)
		cout << "NO";
	else {
		int mx, my;
		mx = x[0] + x[n / 2];
		my = y[0] + y[n / 2];
		for (int i = 1; i < n / 2; i++) {
			if (x[i] + x[i + n / 2] != mx || y[i] + y[i + n/2] != my) {
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
	}
	return 0;
}