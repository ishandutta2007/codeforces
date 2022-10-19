#include <iostream>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	for (int a = 1; a <= n; a++)
	{
		for (int b = a; a*a + b*b <= n*n; b++)
		{
			int x = sqrt(a*a + b * b);
			if (x*x== a * a + b * b)
				ans++;
		}
	}
	cout << ans << '\n';
}