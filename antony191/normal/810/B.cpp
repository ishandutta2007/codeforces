#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int main()
{
	int n, f;
	cin >> n >> f;
	long long* k = new long long[n];
	long long* l = new long long[n];
	long long* a = new long long[n];
	long long i, s = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> k[i];
		cin >> l[i];
		s += min(k[i], l[i]);
		a[i] = min(2 * k[i], l[i]) - min(k[i], l[i]);
	}
	sort(&a[0], &a[n]);
	for (i = 0; i < f; ++i)
	{
		s += a[n - 1 - i];
	}
	cout << s;
	return 0;
}