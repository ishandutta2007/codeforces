#pragma comment(linker, "/stack:16000000")
#define _CRT_SECURE_NO_DEPRECATE
#define input_file "input.txt"
#define output_file "output.txt"

#include <cassert>

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long int64;
const int INF = (int)2e9;
const int64 INF64 = (int64)1e18;
const double EPS = 1e-6;
const double PI = 3.1415926545;

typedef struct {
	int x, y;
} point;

#define sqr(x) ((x)*(x))
#define dist(a, b) sqrt((double)sqr(a.x - b.x) +sqr(a.y - b.y))
#define dist2(x1, y1, x2, y2) sqrt((double)(sqr(x1 - x2)) +sqr(y1 - y2))
#define bound(x, y, n, m) ((x) >= 0 && (y) >= 0 && (x) < (n) && (y) < (m))
#define all(c) c.begin(), c.end()

/* my functions ans structs */




/* main function */
int main() {
#ifndef ONLINE_JUDGE
	freopen(input_file, "r", stdin);
	freopen(output_file, "w", stdout);
#endif
	/* code begin */

	int n;
	cin >> n;
	vector<int> a(n);
	int km = 0, kp = 0;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[i] = x;
		if (x > 0)
			kp++;
		if (x < 0)
			km++;
	}
	sort(all(a));
	if (n == 1) {
		cout << a[0];
		return 0;
	}
	if (kp == 0 && km == 0) {
		cout << 0;
		return 0;
	}
	if (km == 1 && kp == 0) {
		cout << 0;
	}

	for (int i = 0; i < kp; i++) {
		cout << a[n - 1 - i] << " ";
	}
	if (km % 2 == 0) {
		for (int i = 0; i < km; i++) {
			cout << a[i] << " ";
		}
	}
	else
	{
		for (int i = 0; i < km - 1; i++) {
			cout << a[i] << " ";
		}
	}
		
	/* code end */
	return 0;
}//krqpbr