#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int a[100001];
int main()
{	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 2)
	{
		cout << 0;
		return 0;
	}
	sort(a, a + n);
	cout << min((a[n - 1] - a[1]), a[n - 2] - a[0]);
	return 0;
}