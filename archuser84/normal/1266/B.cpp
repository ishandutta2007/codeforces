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
	int t;
	bool ans[1500] = { 0 };
	cin >> t;
	for (Loop)
	{
		__int64 x;
		cin >> x;
		int r = x % 14;
		if (x > 14 && 1 <= r && r <= 6)
			ans[loop] = 1;
	}
	for (Loop)
	{
		if (ans[loop])
		{
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
}