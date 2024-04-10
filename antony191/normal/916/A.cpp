#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

bool check(int a, int b);

int main() {
	int x;
	cin >> x;
	int a, b;
	cin >> a >> b;
	int i = 0;
	while (!check(a, b)) {
		b -= x;
		if (b < 0) {
			b += 60;
			a -= 1;
		}
		if (a < 0)
			a += 24;
		++i;
	}
	cout << i;
	return 0;
}

bool check(int a, int b) {
	return (a % 10 == 7) || (b % 10 == 7);
}