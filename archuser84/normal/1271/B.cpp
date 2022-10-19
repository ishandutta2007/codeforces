#include <iostream>
#include <string>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n;
	char bl[300];
	int m[600];
	int size = 0;
	bool reverse = false;
	bool ans = true;
	cin >> n >> bl;
	for (int i = 0; i < n - 1; i++)
	{
		if (bl[i] == 'B')
		{
			m[size] = i + 1;
			++size;
			bl[i + 1] = bl[i + 1] == 'B' ? 'W' : 'B';
		}
	}
	if (bl[n - 1] == 'B')
	{
		if (n % 2 == 0)
			ans = 0;
		else
			reverse = 1;
	}

	if (!ans)
		cout << -1 << '\n';
	else
	{
		cout << size + reverse * (n / 2) << '\n';
		for (int i = 0; i < size; i++)
		{
			cout << m[i] << ' ';
		}
		if (reverse)
		{
			for (int i = 1; i < n; i += 2)
			{
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}