#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int xa, xb, xc, ya, yb, yc;
	cin >> xa >> ya;
	cin >> xb >> yb;
	cin >> xc >> yc;
	
	cout << 3 << endl;
	
	cout << xb + xa - xc << " " << yb + ya - yc << endl;
	cout << xc + xa - xb << " " << yc + ya - yb << endl;
	cout << xb + xc - xa << " " << yb + yc - ya << endl;
	return 0;
}