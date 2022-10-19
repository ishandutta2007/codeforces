#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;

int n;
int a[N];

long long ans1=999999999999999, ans2;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 1; i < n; ++i)
	{
		if (a[i] - a[i - 1] < ans1)
		{
			ans1 = a[i] - a[i - 1];
			ans2 = 1;
		}
		else if (a[i] - a[i - 1] == ans1)
		{
			ans2 ++;
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}