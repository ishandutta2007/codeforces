#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


const int D = 86400;
bool b[105];

int main() {
	int n;
	cin >> n;
	if (n <= 10 || n > 21) {
		cout << 0;
		return 0;
	}
	if (n != 20) {
		cout << 4;
	}
	if (n == 20) {
		cout << 15;
	}
}