#include <iostream>

#include <algorithm>

using namespace std;

const long long N = 1000 * 1000 * 1000 + 7;
int a[200005];
int b[200005];
int main()
{
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		cin >> b[i];
	}
	a[n] = N;
	sort(a, a + n);
	sort(b, b + m);
	long long x = 0, y = N;
	for(int i = 0; i <= n; i ++)
	{	
		int j = lower_bound(b, b + m, a[i]) - b;
		if(i * 2 + (n - i) * 3 - j * 2 - (m - j) * 3 > x - y)
		{
			x = 1ll * i * 2 + (n - i) * 3;
			y = 1ll * j * 2 + (m - j) * 3;
		} 
	}
	cout << x << ":" << y;
	return 0;
}