/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
//#include "sort.h"

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

struct vt {
	ld x, y;

	vt() {

	}

	vt(ld x, ld y): x(x), y(y) {

	}
};

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

ld operator *(vt a, vt b) {
	return a.x * b.y - a.y * b.x;
}

ld dst(vt a) {
	return hypot(a.x, a.y);
}

int main() {
	int n;

	cin >> n;

	vector <vt> v;

	for (int i = 0; i < n; i++) {
		vt a;

		scanf("%lf %lf", &a.x, &a.y);
		
		v.push_back(a);
	}

	v.push_back(v[0]);
	v.push_back(v[1]);

	ld ans = 2e9;

	for (int i = 0; i < n; i++) {
		vt a = v[i];
		vt b = v[i + 1];
		vt c = v[i + 2];

		b = b - a;
		c = c - a;

		ld ds = c * b / dst(c);
		ds = abs(ds);

		ans = min(ans, ds);
	}

	printf("%.10lf\n", ans / 2);

	return 0;
}