#include <iostream>

using namespace std;

int a[6];
int main()
{
	string s = "IMPOSSIBLE";
	for(int i = 0; i < 4; i ++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < 4; i ++)
	{
		for(int j = 0; j < i; j ++)
		{
			for(int k = 0; k < j; k ++)
			{
				if(i != j && j !=k && i !=k && a[i] + a[j] > a[k] && a[i] + a[k] > a[j] && a[j] + a[k] > a[i])
				{
					s = "TRIANGLE";
				}
				if(i != j && j !=k && i !=k && a[i] + a[j] >= a[k] && a[i] + a[k] >= a[j] && a[j] + a[k] >= a[i] && s == "IMPOSSIBLE")
				{
					s = "SEGMENT";
				}
			}
		}
	}
	cout << s;
	return 0;
}