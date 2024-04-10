#include <iostream>
using namespace std;


bool isComposite(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return true;
		}
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		if (isComposite(i) && isComposite(n - i)) {
			cout << i << " " << n - i << endl;
			return 0;
		}
	}
	return 0;
}