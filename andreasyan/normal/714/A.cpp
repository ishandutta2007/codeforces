#include <iostream>
using namespace std;

long long l1, l2, r1, r2, k,l3,r3, pat;
int main()
{
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	if (l1 > l2)
		l3 = l1;
	else
		l3 = l2;
	if (r1 < r2)
		r3 = r1;
	else
		r3 = r2;
	if (l3 > r3)
		pat = 0;
	else
	{
		pat += r3 - l3 + 1;
		if (k >= l3 && k <= r3)
			pat--;
	}
	cout << pat << endl;
//	system("pause");
	return 0;
}