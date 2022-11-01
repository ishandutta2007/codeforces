#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int x = 1000000;
	for(int i = 0; i < n; i ++)
	{
		cout << x << " ";
		x ++;
	}
	return 0;
}