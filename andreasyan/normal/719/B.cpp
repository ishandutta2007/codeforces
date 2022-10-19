#include <iostream>
using namespace std;

int n, m, k, res1, res2;
char b[100002], a[100002];
int a1, a2;
int main()
{
	int i;
	cin >> n;
	cin >> a;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			b[i] = 'b';
		else
			b[i] = 'r';
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			if (a[i] == 'r')
				a1++;
			else
				a2++;
		}
	}
	if (a1 > a2)
		res1 = a1;
	else
		res1 = a2;
	for (i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			b[i] = 'r';
		else
			b[i] = 'b';
	}
	a1 = 0;
	a2 = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] != b[i])
		{
			if (a[i] == 'r')
				a1++;
			else
				a2++;
		}
	}
	if (a1 > a2)
		res2 = a1;
	else
		res2 = a2;
	if (res1 > res2)
		cout << res2 << endl;
	else
		cout << res1 << endl;
//	system("pouse");
	return 0;
}