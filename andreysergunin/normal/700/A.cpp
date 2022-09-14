#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int main() {
	long long n, l;
	double v1, v2;
	long long k;
	cin >> n >> l;
	cin >> v1 >> v2;
	cin >> k;

	int m = (n - 1) / k + 1;
	double t = l / ( 2 * v1 * v2 / (v1 + v2) * ((double)m - 1) + v2);
	double ans = t + (double)(l - t * v2) / v1;
	cout.precision(12);
	cout << ans << endl; 
	return 0;
}