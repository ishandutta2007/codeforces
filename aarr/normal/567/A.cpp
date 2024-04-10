#include <iostream>
using namespace std;


int a[100 * 1000 + 5];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << a[1] - a[0] << " " << a[n - 1] - a[0] << endl;
	for (int i = 1; i < n - 1; i++) {
		cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << " " << max(a[n - 1] - a[i], a[i] - a[0]) << endl;
	}
	cout << a[n - 1] - a[n - 2] << " " << a[n - 1] - a[0] << endl;
	
	return 0;
}