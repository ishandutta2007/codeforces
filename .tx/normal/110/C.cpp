#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, t, k = -1, c = 0;
	cin >> n;
	if (n % 4 == 0) {
		k = 0;
	}
	t = n;
	while (n >= 7) {
		n -= 7;
		c++;
		if (n % 4 == 0) {
			k = c;
		}
	}
	if (k == -1) {
		cout << -1;
	}
	else {
		for (int i = 0; i < (t - k * 7) / 4; i++) {
			printf("4");
		}
		for (int i = 0; i < k; i++) {
			printf("7");
		}
	}

	return 0;
}//tjlqty