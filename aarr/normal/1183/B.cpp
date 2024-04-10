#include <iostream>
using namespace std;

int a[105];

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int n, k, mini = 1000 * 1000 * 1000 + 7, maxi = 0;
		cin >> n;
		cin >> k;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			mini = min(mini, a[j]);
			maxi = max(maxi, a[j]);
		}
		//cout << mini << " " << maxi << endl;
		if (abs(mini + k - maxi) <= k) 
			cout << mini + k << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}