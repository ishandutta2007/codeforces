#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

char s[30];

int my_rand() {
	int z = rand();
	z *= RAND_MAX;
	z += rand();
	z *= RAND_MAX;
	z += rand();
	z %= 1000000000;
	if (z < 0) {
		z += 1000000000;
	}

	return z;
}

int a;
int cnt;

bool get_ans(int x, int y) {
	cnt++;
	cout << "? " << x << ' ' << y << endl;
	char c;

	scanf(" %c", &c);
	/*
	if (x % a >= y % a) {
		c = 'x';
	}
	else {
		c = 'y';
	}

	if (cnt == 60) {
		c = 'e';
	}
	*/
	if (c == 'e') {
		while (true);
	}

	if (c == 'x') {
		return false;
	}

	return true;
}

int main() {
	srand(time(NULL));

	while (true) {
		cnt = 0;
		//cin >> a;
		scanf(" %s", s);

		if (s[0] == 'm') {
			throw 1;
		}
		else if (s[0] == 'e') {
			break;
		}

		int x, y;

		while (true) {
			x = my_rand() + 1000000000;
			y = my_rand();

			if (!get_ans(y, x)) {
				break;
			}
		}

		int l = 0;
		int r = y;

		while (r - l > 1) {
			int m = (l + r) >> 1;

			if (!get_ans(m, x)) {
				r = m;
			}
			else {
				l = m;
			}
		}

		if (get_ans(x, r)) {
			r--;
		}

		x -= r;

		int g = x;

		for (int i = 2; i * i <= g; i++) {
			if (g % i == 0) {
				while (x % i == 0 && !get_ans(0, x / i)) {
					x /= i;
				}

				while (g % i == 0) {
					g /= i;
				}
			}
		}

		if (g != 1) {
			while (x % g == 0 && !get_ans(0, x / g)) {
				x /= g;
			}
		}

		cout << "! " << x << endl;
	}

	//system("pause");
}