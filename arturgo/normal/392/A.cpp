#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long dist;
	cin >> dist;

	if(dist == 0) {
		cout << 1 << endl;
		return 0;
	}

	long long nombre = 4 * dist;
	long long curCarre = 0;

	for(long long iX = dist - 1;iX >= 1;iX--) {
		long long q = dist * dist - iX * iX;

		if(q < (curCarre + 1) * (curCarre + 1)) {
			nombre += 4;
		}
		else {
			while((curCarre + 1) * (curCarre + 1) <= q) {
				curCarre++;
			}
		}
	}

	cout << nombre << endl;

	return 0;
}