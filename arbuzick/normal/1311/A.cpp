#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int i;
	for (i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b)
			cout << 0 << endl;
		else if (a % 2 == b % 2 && b < a)
			cout << 1 << endl;
		else if (a % 2 != b % 2 && b > a)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
	return 0;
}