#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdio>


using namespace std;

int main() {
	int n;
	cin >> n;
	double r;
	cin >> r;
	int *x = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> x[i];
	double *y = new double[n];
	y[0] = r;
	for (int i = 1; i < n; ++i) {
		double max = r;
		for (int j = 0; j < i; ++j) {
			if (abs(x[i] - x[j]) <= 2 * r) {
				double k = 4 * r * r - abs(x[i] - x[j]) * abs(x[i] - x[j]);
				k = double(k);
				k = sqrt(k) + y[j];
				if (k > max)
					max = k;
			}
		}
		y[i] = max;
	}
	for (int i = 0; i < n; ++i)
		printf("%.8lf ", y[i]);
	return 0;
}