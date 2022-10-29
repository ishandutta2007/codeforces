#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long l = 1;
	while (l <= n)
		l *= 2;
	l /= 2;
	if (k == 1)
		cout << n;
	else
		cout << 2 * l - 1;
	return 0;
}