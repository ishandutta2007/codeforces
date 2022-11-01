#include <iostream>

using namespace std;

int main()
{
	int n;
	string d;
	cin >> n;
	for(int i = 0; i <= n; i++)
	{
		string c;
		string e;
		int a = i;
		while(a >= 1)
		{
			char b = a % 10 + '0';
			c += b;
			a = a / 10;			
		}
		for(int j = c.size() - 1; j >= 0; j--)
		{
			e += c[j];
		}
		d += e;
	}
	cout << d[n - 1];
	return 0;
}