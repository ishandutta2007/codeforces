#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 102;

int n;
int a[N];

int ans1, ans2, ans3, ans4;
int main()
{
	cin >> n;
	for (int i = 0; i < n / 2; ++i)
		cin >> a[i];
	sort(a, a + n / 2);
	for (int x = 1, j = 0; x <= n; x += 2, ++j)
	{
		int y = a[j];
		ans1 += abs(x - y);
	}
	for (int x = 2, j = 0; x <= n; x += 2, ++j)
	{
		int y = a[j];
		ans2 += abs(x - y);
	}
	for (int x = n, j = n / 2 - 1; x >= 1; x -= 2, --j)
	{
		int y = a[j];
		ans3 += abs(x - y);
	}
	for (int x = n - 1, j = n / 2 - 1; x >= 1; x -= 2, --j)
	{
		int y = a[j];
		ans4 += abs(x - y);
	}
	cout << min(min(ans1, ans2), min(ans3, ans4)) << endl;
	return 0;
}