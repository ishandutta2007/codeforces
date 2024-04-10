#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


const int N = 10;

int main() {
	int n, x = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1)
			x++;
		else
			y++;
	}
	if (y > x) {
		cout << x;
	}
	else {
		cout << y + (x - y) / 3;
	}
}