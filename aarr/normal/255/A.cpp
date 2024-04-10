#include <iostream>
using namespace std;

int a[3];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i % 3] += x;
	}
	if (a[0] > a[1] && a[0] > a[2]) {
		cout << "chest";
	}
	if (a[1] >= a[0] && a[1] > a[2]) {
		cout << "biceps";
	}
	if (a[2] >= a[0] && a[2] >= a[1]) {
		cout << "back";
	}
	return 0;
}