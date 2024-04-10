#include <iostream>
using namespace std;

int b, p, n,cn;
int ansb,ansp;
int main()
{
	cin >> n >> b >> p;
	cn = n;
	while (1)
	{
		if (n == 1)
			break;
		ansb += ((n / 2)*b*2+n/2);
		n = n - n / 2;
	}
	ansp = cn*p;
	cout << ansb << ' ' << ansp << endl;
//	system("pause");
	return 0;
}