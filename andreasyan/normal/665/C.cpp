#include <iostream>
#include <cstring>
using namespace std;

int n, m;
char a[2 * 100005];
int main()
{
	int i, j, k;
	cin >> a;
	n = strlen(a);
	for (i = 1; i < n; ++i)
	{
		if (a[i] == a[i - 1])
		{
			for (j = 0; j < 26; ++j)
			{
				if ((j + 'a') != a[i-1] && (j + 'a') != a[i + 1])
				{
					a[i] = (j + 'a');
					break;
				}
			}
		}
	}
	cout << a << endl;
	return 0;
}