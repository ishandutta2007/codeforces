#include <iostream>
using namespace std;
int a[20] = { 4,7,44,77,47,74,444,447,474,477,744,747,774,777 };
int main()
{
	int n,i;
	cin >> n;
	for (i = 0; i <= 13; i++)
	{
		if (n%a[i] == 0)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}