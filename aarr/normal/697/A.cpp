#include <iostream>
#include <cmath>
using namespace std;

int a[105], b[105];

int main() {
	int t, s, x;
	cin >> t >> s >> x;
	if (x < t || x == t + 1) {
		cout << "NO";
	}
	else {
		if ((x - t) % s <= 1) {
			cout << "YES";
		}
		else {
			cout << "NO"; 
		}
	}
	return 0;
}