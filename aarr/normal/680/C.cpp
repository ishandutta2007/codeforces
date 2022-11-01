#include <iostream>

using namespace std;

int a[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
int main()
{
	int b = 0;
	for(int i = 0; i < 19; i ++)
	{
		cout << a[i] << endl;
		fflush(stdout);
		string s;
		cin >> s;
		if(s == "yes")
		{
			b ++;
		}
	}
	if(b > 1)
	{
		cout << "composite";
	}
	else
	{
		cout << "prime";
	}
	return 0;
}