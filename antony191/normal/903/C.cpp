#include <iostream>
#include <algorithm>


using namespace std;

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(&a[0], &a[n]);
	int max = 1, k = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1])
			++k;
		else {
			if (k > max)
				max = k;
			k = 1;
		}
	}
	if (k > max) 
		max = k;
	cout << max;
	return 0;
}