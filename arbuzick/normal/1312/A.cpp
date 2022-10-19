#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		if (n % m == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}