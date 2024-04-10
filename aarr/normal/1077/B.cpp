#include <iostream>

using namespace std;

int a[103];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	int s = 0, k = 0, i = 0;
	while(i < n)
	{
		if(a[i] == 0)
		{
			i ++;
			k = 0;
		}
		else
		{
			if(i + 2 < n && a[i + 1] == 0 && a[i + 2] == 1)
			{
				i += 2;
				k ++;
			}
			else
			{
				i += 1;
				s += (k + 1) / 2;
				k = 0;
			}
		}
	}
	cout << s;
	return 0;
}