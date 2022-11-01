#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


const int D = 86400;
bool b[105];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int q = (k - 1) / 2;
	cout << q / m + 1 << " " << q % m + 1 << " ";
	if (k % 2) {
		cout << 'L';
	}
	else {
		cout << 'R';
	}
}