#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	double d = 1005;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		d = min(d, (double) x / y);
	}
	cout << fixed << setprecision(7);
	cout << (double) d * m << endl;
	return 0;
}