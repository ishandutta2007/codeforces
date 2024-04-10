#include <iostream>

using namespace std;

int main()
{
	int n, s = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		int x;
		cin >> x;
		s += x;
		if((s - i) % 2 == 0)
		{
			cout << 2 << endl;
		}
		else
		{
			cout << 1 << endl;
		}
	}
	return 0;
}