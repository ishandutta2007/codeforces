#include <iostream>

using namespace std;

int a[100];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	int i = 0, b = 0;
	for(int j = 1; j <= 90; j ++)
	{
		if(j == a[i])
		{
			b = 0;
			i ++;
		}
		else
		{
			b ++;
		}
		if(b == 15 || j == 90)
		{
			cout << j;
			break;
		}
	}
	return 0;
}