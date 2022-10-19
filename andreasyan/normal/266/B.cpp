#include <iostream>
using namespace std;

char a[55];
int main()
{
	int i, j, k, n;
	char m;
	cin >>n>>k>> a;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (a[j] == 'B' && a[j + 1] == 'G')
			{
				a[j + 1] = 'B';
				a[j] = 'G';
				j++;
			}
		}
	}
	cout << a << endl;
	return 0;
}