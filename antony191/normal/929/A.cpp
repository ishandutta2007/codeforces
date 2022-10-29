#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int sum = 1;
	int t_prokat = a[0];
	for (int i = 1; i < n; ++i) {
		if (a[i] - t_prokat > k)
			if (a[i] - a[i - 1] > k)
				return cout << -1, 0;
			else
				++sum, t_prokat = a[i - 1];
	}
	cout << sum;
	return 0;
}