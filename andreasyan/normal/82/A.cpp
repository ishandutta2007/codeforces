#include <iostream>
using namespace std;

int main()
{
	int i, j, k=0, n, m=0,z=1;
	cin >> n;
	for (i = 5; m < n; i = i * 2)
		m = m + i;
	i = i / 2;
	k = i / 5;
	z = !!((n - (m - i)) % k) + (n - (m - i)) / k;
	if (z == 1)
		cout << "Sheldon" << endl;
	if (z == 2)
		cout << "Leonard" << endl;
	if (z == 3)
		cout << "Penny" << endl;
	if (z == 4)
		cout << "Rajesh" << endl; 
	if (z == 5)
		cout << "Howard" << endl;
	//cout << i << endl << m << endl;
	return 0;
}