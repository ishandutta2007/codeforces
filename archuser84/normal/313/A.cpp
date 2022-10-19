#include <iostream>
using namespace std;

int main()
{
	int x, ans;
	cin >> x;
	if (x >= 0)
		ans = x;
	else
	{
		int a = x / 10;
		int b = (x / 100) * 10 + (x % 10);
		if (a > b)
			ans = a;
		else
			ans = b;
	}
	cout << ans << endl;
}