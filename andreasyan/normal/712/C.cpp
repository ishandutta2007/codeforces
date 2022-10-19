#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k,b[3];
int main()
{
	int i, j;
	cin >> n >> m;
	b[0] = m;
	b[1] = m;
	b[2] = m;
	if (n == m)
	{
		cout << '0' << endl;
		return 0;
	}
	while (1)
	{
		sort(b, b + 3);
		for (i = n; i > b[0]; i--)
		{
			if (i + b[1] > b[2] && i + b[2] > b[1] && i<b[1]+b[2])
			{
				b[0] = i;
				k++;
//				cout << k << ' ' << b[0] << ' ' << b[1] << ' ' << b[2] << endl;
				break;
			}
		}
		if (b[0] == b[1] && b[1] == b[2] && b[2] == n)
			break;
	}
	cout << k << endl;
//	system("pause");
	return 0;
}