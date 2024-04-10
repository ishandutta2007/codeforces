#include <iostream>

using namespace std;

int a[5];
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		for(int j = 0; j < 3; j ++)
		{
			int b;
			cin >> b;
			a[j] += b;
		}
	}
	if(a[0] == 0 && a[1] == 0 && a[2] == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}