#include <iostream>
#include <algorithm>
using namespace std;

int a[55];
int main()
{
	int i, j, k, n, m,pat=0;
	cin >> n>>k;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (i = 1; i <= n; i++)
	{
		if (a[i] >= a[n-k+1] && a[i] != 0)
			pat++;
	}
	cout << pat << endl;
	return 0;
}