#include <iostream>

using namespace std;

int main()
{
	long long n, a, b, c, ans = 1ll * 1000 * 1000 * 1000 + 7;
	cin >> n;
	cin >> a;
	cin >> b;
	cin >> c;
	for(int i = 0; i < 4; i ++)
	{
		for(int j = 0; j < 7; j ++)
		{
			for(int k = 0; k < 7; k ++)
			{
				if((n + i + 2 * j + 3 * k) % 4 == 0)
				{
					ans = min(ans, a * i + b * j + c * k);
				}
			}
		}
	}
	cout << ans;
}