#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int n, a[101];

int main()
{
	//freopen("convention2.in", "r", stdin);
	//freopen("convention2.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0;
	for (int i = 0; i < n; i+=2)
	{
		sum += a[i + 1] - a[i];
	}
	cout << sum;
	return 0;
}