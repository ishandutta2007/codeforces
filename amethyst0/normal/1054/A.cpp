#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
	int x, y, z, t1, t2, t3;

	cin >> x >> y >> z >> t1 >> t2 >> t3;

	if (t1 * abs(x - y) >= 3 * t3 + t2 * abs(x - y) + t2 * abs(z - x)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	//system("pause");
}