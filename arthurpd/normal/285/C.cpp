#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int
main(void)
{
	long long n, a[300300], ans = 0, i;
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	for(i = n-1; i >= 0; i--)
		ans += abs(a[i] - (i+1));
	cout << ans << '\n';
	return 0;
}