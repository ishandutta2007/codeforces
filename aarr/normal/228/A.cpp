#include <iostream>

using namespace std;

int a[5];
int main()
{
	int m = 0;
	for(int i = 0; i < 4; i ++)
	{
		int b;
		bool c = true;
		cin >> b;
		for(int j = 0; j < m; j ++)
		{
			if(b == a[j])
			{
				c = false;
			}
		}
		if(c == true)
		{
			a[m] = b;
			m ++;
		}
	}
	cout << 4 - m;
	return 0;
}