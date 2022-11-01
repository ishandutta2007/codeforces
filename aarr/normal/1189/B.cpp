#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (a[n - 2] + a[n - 3] > a[n - 1]) {
		cout << "YES" << endl;
		for (int i = 0; i < n - 2; i++) {
			cout << a[i] << " ";
		}
		cout << a[n - 1] << " " << a[n - 2] << endl;
	}
	else {
		cout << "NO";
	}
	return 0;
}