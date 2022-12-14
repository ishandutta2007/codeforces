#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n, x;
	long long t = 0;
	cin >> n >> x;
	long long c[n];
	for(long long i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	sort(c, c + n);
	for(long long i = 0; i < n; i++)
	{
		t += x * c[i];
		x = x > 1 ? x - 1 : 1;
	}
	cout << t;
	return 0;
}