#include <iostream>
#include <cstring>
using namespace std;

char a[1020];
int b[257];
int main()
{
	int i,n, m=0;
	cin.getline(a,1000);
	n = strlen(a);
	for (i = 0; i < n; i++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
			b[a[i]] = 1;
	}
	for (i = 0; i <= 255; i++)
	{
		if (b[i] == 1)
			m++;
	}
	cout << m << endl;
	return 0;
}