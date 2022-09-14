#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld double

using namespace std;

const ld pi = acos(-1.0);

const ld eps = 1e-9;

int main() {
	int n, r1, r2;

	cin >> n >> r1 >> r2;

	if (r1 < r2) {
		cout << "NO" << endl;
		return 0;
	}

	if (2 * r2 > r1) {
		if (n == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		return 0;
	}

	if (2 * r2 == r1) {
		if (n <= 2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		return 0;
	}

	ld a = pow((r1 - r2) * (r1 - r2) - r2 * r2, 0.5);

	ld phi = acos(a / (r1 - r2)) * 2;

	if (n * phi <= 2 * pi + eps) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	//system("pause");
	return 0;
}