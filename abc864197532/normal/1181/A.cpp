#include <iostream>
#include <math.h>
using namespace std;

int main () {
	long long int x,y,z;
	cin >> x >> y >> z;
	long long int k=(x+y)/z,a=x%z,b=y%z,l=0;
	if (a+b<z) l=0;
	else {
		if (a>b) l=min(z-a,b);
		else l=min(z-b,a);
	}
	cout << k << ' ' << l << endl;
}