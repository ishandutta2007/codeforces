#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int nb;
	cin >> nb;

	int m = -1000 * 1000;
	for(int i = 0;i < nb;i++) {
		int a;
		cin >> a;

		if(a < 0) {
			m = max(m, a);
			continue;
		}

		int s = sqrt(a);
		if(s * s != a) {
			m = max(m, a);
		}
	}

	cout << m << endl;
	return 0;
}