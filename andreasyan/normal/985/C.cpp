#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;

int n, k, l;
int a[N];

long long ans;
int main()
{
	cin >> n >> k >> l;
	for (int i = 0; i < n * k; ++i)
		cin >> a[i];
	sort(a, a + n * k);
	int j = n * k;
	for (int i = 1; i < n * k; ++i)
	{
		if (a[i] - a[0] > l)
		{
			j = i;
			break;
		}
	}
	if (j < n)
	{
		cout << 0 << endl;
		return 0;
	}
	int m = n * k - j;
	--k;
	for (int i = j - 1; i >= 0; --i)
	{
		if (n == 1)
		{
			ans += a[0];
			break;
		}
		if (m >= k)
		{
			ans += a[i];
			m -= k;
			n--;
		}
		else
			m++;
	}
	cout << ans << endl;
	return 0;
}