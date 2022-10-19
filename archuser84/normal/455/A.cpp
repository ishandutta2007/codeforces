#include <iostream>
using namespace std;

long long my_max(long long a, long long b)
{
	return (a >= b)*a + (a < b)*b;
}

int main()
{
	int x[100000] = { 0 };
	long long f[100001];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;
		x[h - 1]++;
	}
	f[0] = 0;
	f[1] = x[0];
	for(int i=2;i<=100000;i++)
		f[i]= my_max((long long)(x[i - 1]) * i + f[i - 2], f[i - 1]);
	cout << f[100000] << endl;
}