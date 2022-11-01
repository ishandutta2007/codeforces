#include <iostream>

#include <algorithm>

using namespace std;

int a[6];
int main()
{
	int n, ans = 0;
	cin >> n;
	a[0] = 1, a[1] = 5, a[2] = 10, a[3] = 20, a[4] = 100;
	while(n > 0)
	{
		
		int i = upper_bound(a, a + 5, n) - a - 1;
		n -= a[i];
		ans ++;
	}
	cout << ans;
}