#include <bits/stdc++.h>

using namespace std;

int main()
{
	double h,l;
	cin >> h >> l;
	cout << fixed << setprecision(14) << (h*h+l*l)/(2.0*h)-h << endl;
	return 0;
}