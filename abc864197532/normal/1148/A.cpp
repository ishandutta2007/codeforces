#include <iostream>
using namespace std;

int main () {
	long long int a,b,c,m,n;
	cin >> a >> b >> c;
	m=a+c;
	n=b+c;
	if (m>n) cout << 2*n+1 << endl;
	else if (n>m) cout << 2*m+1 << endl;
	else cout << 2*m << endl;
	return 0;
}