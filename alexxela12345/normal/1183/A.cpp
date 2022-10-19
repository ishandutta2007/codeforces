#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (true) {
		int s = 0;
		int nn = n;
		while (nn > 0) {
			s += nn % 10;
			nn /= 10;
		}
		if (s % 4 == 0) {
			break;
		}
		n++;
	}
	cout << n << endl;
}