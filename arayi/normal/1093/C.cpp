#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
long long int a[200000], n, sm;
int main()
{
	//freopen("leash.in", "r", stdin);
	//freopen("leash.out", "w", stdout);
	cin >> n;
	cin >> sm;
	a[n - 1] = sm;
	for (int i = 1; i < n/2; i++)
	{
		cin >> sm;
		if (a[i - 1] <= sm - min(a[n - i], sm)) {
			a[n - i - 1] = min(a[n - i], sm);
			a[i] = sm - a[n - i - 1];
		}
		else {
			a[i] = a[i - 1];
			a[n - i - 1] = sm - a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}