#include <iostream>
#include <algorithm>
using namespace std;

char s[105];
int a[105];
int main()
{
	int i, j, k, n, m;
	cin >> s;
	n = strlen(s);
	j = 0;
	for (i = 0; i < n; i++)
	{
		if (s[i] >= '1' && s[i] <= '3')
		{
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a, a + j);
	cout << a[0];
	for (i = 1; i < j; i++)
	{
		cout << '+' << a[i];
	}
	cout << endl;
	return 0;
}