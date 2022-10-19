#include <iostream>
using namespace std;

int main()
{
	int i, j, n, m;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (j = 0; j < m; j++)
				cout << '#';
		}
		if (i % 2 == 1 && (i/2)%2==1)
		{
			cout << '#';
			for (j = 1; j < m; j++)
				cout << '.';
		}
		if (i % 2 == 1 && (i / 2) % 2 == 0)
		{
			for (j = 0; j < m-1; j++)
				cout << '.';
			cout << '#';
		}
		cout << endl;
	}
	return 0;
}