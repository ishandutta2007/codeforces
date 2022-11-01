#include <iostream>
using namespace std;


const int N = 1005;
int a[5];
int b[5];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		a[t] += x;
		b[t] += 10;
	}
	for (int i = 1; i < 3; i++) {
		if (a[i] >= b[i] / 2)
			cout << "LIVE" << endl;
		else
			cout << "DEAD" << endl;
 	}
	return 0;
}