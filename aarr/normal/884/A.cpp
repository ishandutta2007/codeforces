#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;


const int D = 86400;
bool mark[5];

int main() {
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		t -= D - x;
		if (t <= 0) {
			cout << i;
			return 0;
		}
	}
}