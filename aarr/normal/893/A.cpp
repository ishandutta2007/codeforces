#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


const int N = 10;
bool mark[5];

int main() {
	int n;
	cin >> n;
	mark[1] = mark[2] = true;
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x;
		for (int j = 1; j <= 3; j++) {
			if (!mark[j]) {
				y = j;
			}
			else if (j != x) {
				z = j;
			}
		}
		if (x == y) {
			cout << "NO";
			return 0;
		}
		mark[z] = false;
		mark[y] = true;
	}
	cout << "YES";
}