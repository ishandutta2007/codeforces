#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, i;
	cin >> n;
	int *a = new int[n];
	for (i = 0; i < n; ++i)
		cin >> a[i];
	int k = 0, s = -1;
	sort(a, a + n);
	for (i = 1; i < n; ++i)
		if (a[i] != a[i - 1])
		{
			k++;
			s = i;
		}
	if (k == 1 && 2 * s == n)
	{
		cout << "YES" << endl;
		cout << a[s - 1] << " " << a[s];
	}
	else cout << "NO";
	return 0;
}