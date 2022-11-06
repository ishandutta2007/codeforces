#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long long n, m, x;
	cin >> n >> m >> x;
	/*if (x == 1) {
		cout << (n*m) / 2;
		return 0;
	}*/
	--x;
	m -= 2*x;
	n -= 2*x;
	if (m <= 0 || n <= 0) {
		cout << 0;
	}
	else {
		if (n == 1 && m == 1) {
			cout << 1;
			return 0;
		}
		if (n == 1) {
			cout << (m + 1) / 2;
			return 0;
		}
		if (m == 1) {
			cout << (n + 1) / 2;
			return 0;
		}
		cout << (m*n) / 2 - (m-2)*(n-2)/2;
	}
	return 0;
}//rpuunu