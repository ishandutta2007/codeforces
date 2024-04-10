#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cin >> x;
	cin >> y;
	int a = y, b = y, c = y, ans = 0;
	while(a < x || b < x || c < x)
	{
		if(a > b)
		{
			swap(a, b);
		}
		if(a > c)
		{
			swap(a, c);
		}
		//cout << a << " " << b << " " << c << endl;
		a = min(b + c - 1, x);
		ans ++;
	}
	cout << ans;
	return 0;
}