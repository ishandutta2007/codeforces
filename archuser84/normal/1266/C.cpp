#include <iostream>
#include <string.h>
#include <map>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;

int Min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int r, c;
	cin >> r >> c;
	if (r == 1 && c == 1)
		cout << "0\n";
	else if (c == 1)
	{
		for (int i = 2; i <= r + 1; i++)
			cout << i << '\n';
	}
	else
	{
		for (int i = 2; i <= c + 1; i++)
			cout << i << ' ';
		cout << '\n';
		for (int j = c + 2; j < r + c + 1; j++)
		{
			for (int i = 2; i <= c + 1; i++)
				cout << j * i << ' ';
			cout << '\n';
		}
	}
}