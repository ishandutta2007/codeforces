#include <iostream>

#include <algorithm>

using namespace std;

int main()
{
	int n, i;
	cin >> n;
	int* a = new int[2 * n];
	for (i = 0; i < 2 * n; ++i) cin >> a[i];
	sort(a, a + 2 * n);
	if (a[n] > a[n - 1]) cout << "YES";
	else cout << "NO";
	return 0;
}