#include <iostream>

using namespace std;

const int N = 1000 * 1000 * 1000 + 7;
int f(int x, int y)
{
	if(x == 1 && y == 1)
	{
		return 0;
	}
	if(x == y)
	{
		return N;
	}
	if(x > y)
	{
		swap(x, y);
	}
	return f(x, y - x) + 1;
}
int main()
{
	int n;
	cin >> n;
	int ans = f(1, n);
	for(int i = 1; i < n; i ++)
	{
		ans = min(ans, f(i, n));
	}
	cout << ans;
}