#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;

int a[N];
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		sort(a, a + n);
		bool b = true;
		for (int j = 0; j < n - 1; j++) {
			if (a[j + 1] == a[j] + 1)
				b = false;
		}
		if (b)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}