#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
int n, r;
double R;
const double d = 0.01745329252;
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(7);
	cin >> n >> r;
	double sm = 180;
	sm /= n;
	sm *= d;
	sm = sin(sm);
	cout << (r*sm) / (1 - sm);
	return 0;
}