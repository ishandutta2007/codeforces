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

#define ll long long
#define pii pair <int, int>
#define mp make_pair

using namespace std;

vector <int> x, y;

bool good(int cnt, ll a, ll b) {
	int buf = cnt;
	x.clear();
	y.clear();

	while (cnt > 0 && a >= cnt) {
		x.push_back(cnt);
		a -= cnt;
		cnt--;
	}

	if (cnt == 0) {
		return true;
	}

	if (a != 0) {
		x.push_back((int)a);
	}

	while (cnt > 0) {
		if (cnt == a) {
			cnt--;
			continue;
		}

		if (b < cnt) {
			return false;
		}

		y.push_back(cnt);
		b -= cnt;
		cnt--;
	}

	if (cnt == 0) {
		return true;
	}

	return false;
}

int main() {
	ll a, b;

	cin >> a >> b;

	int l = 0, r = (int)1e6;

	while (l != r) {
		int m = (l + r + 1) >> 1;

		if (good(m, a, b)) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}

	good(l, a, b);
	cout << x.size() << endl;

	for (int i = 0; i < (int)x.size(); i++) {
		printf("%d ", x[i]);
	}

	printf("\n");
	cout << y.size() << endl;

	for (int i = 0; i < (int)y.size(); i++) {
		printf("%d ", y[i]);
	}

	printf("\n");

	//system("pause");
}