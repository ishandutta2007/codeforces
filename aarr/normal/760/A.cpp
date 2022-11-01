#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 305;
int cnt[N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int m, d, x;
	cin >> m >> d;
	if (m == 2) {
		x = 28;
	}
	else {
		if (m == 4 || m == 6 || m == 9 || m == 11) {
			x = 30;
		}
		else {
			x = 31;
		}
	}
	d = 8 - d;
//	cout << (x - d) << endl;
	cout << (int) ceil((double) (x - d) / 7) + 1;
}