#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
string a;
int main()
{
	long long n, m;
	cin >> n >> m;
	long long result = 0;
	long long max_n = n * (n - 1) / 2;
	long long min_n = 0;
	if (n % 2 == 0)
	{
		min_n = (n / 2)*(n / 2 - 1) + n / 2;
	}
	else
	{
		min_n = (n / 2)*(n / 2 + 1);
	}
	//cout << max_n << ' ' << min_n << endl;
	for (int i = 0; i < m; i++)
	{
		long long x, d;
		cin >> x >> d;
		if (d >= 0) result += x * n + max_n * d;
		else result += x * n + min_n * d;

	}
	cout.precision(15);
	cout << fixed << (double)result / n;
}