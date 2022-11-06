#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int n;

struct rec {
	int c;
	rec() {};
	rec(int _x, int _y) {
		c = (n - _x) * _y;
	}
	bool operator < (const rec & a) {
		return this->c < a.c;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int	x, c;
	cin >> n >> x;
	int i, sum = 0;
	vector<rec> a(n);
	for (i = 0; i < n; i++) {
		cin >> c;
		a[i] = rec(i, c);
	}
	sort(a.begin(), a.end());
	for (i = 0; i < n && sum + a[i].c <= x; i++) {
		sum += a[i].c;
	}
	cout << i;	
	return 0;
}//bctqwz