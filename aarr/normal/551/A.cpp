#include <iostream>

using namespace std;

int a[2005];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i ++)
	{
		int b = 0;
		for(int j = 0; j < n; j ++)
		{
			if(a[j] > a[i])
			{
				b += 1;
			}
		}
		cout << b + 1 << " ";
	}
	return 0;
}