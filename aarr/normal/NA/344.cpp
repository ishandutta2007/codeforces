#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;

int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i ++)
	{
		int n, x, y, d;
		cin >> n;
		cin >> x;
		cin >> y;
		cin >> d;
		bool b = false;
		if(x % d == y % d)
		{
			cout << (max(x, y) - min (x, y)) / d << endl;
		}
		else
		{
			int ans = N;
			if(1 == y % d)
			{
				ans = (y - 1) / d + (x - 1) / d + 1;
				b = true;
			}
			if(n % d == y % d)
			{
				ans = min(ans, (n - y) / d + (n - x) / d + 1);
				b = true;
			}
			if(b)
			{
				cout << ans << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}