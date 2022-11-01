#include <iostream>

using namespace std;

long long fib[55];
int a[55];
int main()
{
	fib[1] = 1;
	fib[2] = 2;
	for(int i = 3; i < 52; i ++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int n;
	long long l;
	cin >> n;
	cin >> l;
	l --;
	for(int i = 1; i <= n; i ++)
	{
		a[i] = i;
	}
	while (l > 0)
	{
		int x = lower_bound(fib, fib + n + 1, l) - fib;
		if(fib[x] != l)
		{
			x --;
		}
		swap(a[n - x], a[n - x + 1]);
		l -= fib[x];
	}
	for(int i = 1; i <= n; i ++)
	{
		cout << a[i] << " ";
	}
	return 0;
}