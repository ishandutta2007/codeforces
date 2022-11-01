#include <iostream>
using namespace std;

int a[1000][1000];
int main() {
	a[1][1] = 1;
	for (int i = 0; i < 9; i++) {
		int n = 1 << i;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[j + n][k] = a[j][k];
				a[j][k + n] = a[j][k];
				a[j + n][k + n] = 1 - a[j][k];
			}
		}
	}
	int k;
	cin >> k;
	for (int i = 1; i <= (1 << k); i++) {
		for (int j = 1; j <= (1 << k); j++) {
			if (a[i][j])
				cout << '+';
			else
				cout << '*';
		}
		cout << endl;
	}
}