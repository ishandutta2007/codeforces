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
	int n;
	cin >> n;
	bool ans[500] = { 0 };
	for (int i = 0; i < n; i++)
	{
		bool z = 0, e = 0;
		int sum = 0;
		char s[200];
		cin >> s;
		int size = strlen(s);
		for (int j = 0; j < size; j++)
		{
			sum += s[j] - '0';
			if (s[j] == '0' && !z)
				z = 1;
			else if ((s[j]-'0') % 2 == 0)
				e = 1;
		}
		if (z && e && sum % 3 == 0)
			ans[i] = 1;
	}
	for (LoopN)
	{
		if (ans[i])
			cout << "red\n";
		else
			cout << "cyan\n";
	}
}