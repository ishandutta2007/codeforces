#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int i;
	cin >> i;
	vector <long long int> a;
	for (int j = 0; j < i; j++)
	{
		long long int c, x, y, k;
		cin >> x >> y >> k;
		if (y > x)
		{
			c = y;
			y = x;
			x = c;
		}
		if (x>k)
			k = -1;
		else if ((x - y) % 2 == 1)
			k--;
		else if ((k - x) % 2 == 1)
			k -= 2;
		a.push_back(k);
	}
	for (int i = 0; i < a.size() - 1; i++)
	{
		cout << a[i] << endl;
	}
	cout << a[a.size() - 1];
	return 0;
}