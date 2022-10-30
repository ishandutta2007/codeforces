#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long x, y, m, ans = 0;
	cin >> x >> y >> m;

	if (x <= 0 && y <= 0 && x < m && y < m)
	{
		cout << -1;
		return 0;
	}



	while (x < m && y < m)
	{
		
		if (x + y >= m)
		{
			x = x + y;
			ans++;
		}
		else
		{
			if (x <= y)
			{
				long long a = y - x;
				a /= y;
				a = max(a, 1LL);
				ans += a;
				x = x + y*a;
			}	
			else
			{
				long long a = x - y;
				a /= x;
				a = max(a, 1LL);
				ans += a;
				y = y + x*a;
			}
		}
	}

	cout << ans;

	return 0;

}