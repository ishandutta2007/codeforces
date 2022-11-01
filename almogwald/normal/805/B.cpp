
#include <iostream>
#include <vector>

using namespace std;
int main() {
	int a;
	cin >> a;
	for (int i = 0; i<a; i++) {
		if (i % 4 < 2) {
			cout << 'a';
		}
		else {
			cout << 'b';
		}
	}
	cout << endl;
	return 0;
}