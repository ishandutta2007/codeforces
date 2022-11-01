#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int b[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0)
			b[i] = -a[i] - 1;
		else
			b[i] = a[i];
		
	}
	int maxi = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] > b[maxi])
			maxi = i;
	}
	for (int i = 0; i < n; i++) {
		a[i] = -b[i] - 1;
	}
	if (n % 2 == 1)
		a[maxi] = b[maxi];
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}