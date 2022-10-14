#include <bits/stdc++.h>
using namespace std;
#define lli long long int


int main () {
	double h,l;
	cin >> h >> l;
	double x=(h*h+l*l)/2/h;
	cout << setprecision(8) << x-h << endl;
}