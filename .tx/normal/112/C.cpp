#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long lint;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	lint x, y;
	cin >> n >> x >> y;
	lint a = (y - n + 1);
	if (a <= 0 || a * a + n - 1 < x) {
		cout << -1;
	}
	else {
		cout << a << endl;
		for (int i = 1; i < n; i++) {
			cout << 1 << endl;
		}
	}



}//szszmg