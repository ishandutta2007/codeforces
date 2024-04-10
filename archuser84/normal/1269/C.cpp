#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
//#include <time.h>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
using namespace std;

int main()
{
	bool all9 = 1;
	int k, n;
	char s[300000];
	cin >> n >> k;
	cin >> s;
	char c[300000] = { 0 };
	for (int i = 0; i < k; ++i)
	{
		c[i] = s[i] - '0';
		if (c[i] != 9)
			all9 = 0;
	}
	bool bs = 0;
	for (int i = 0; i < n - k; ++i)
	{
		if (s[i] < s[i + k])
		{
			bs = 1;
			break;
		}
		if (s[i] > s[i + k])
		{
			break;
		}
	}
	if (bs)
	{
		cout << n << '\n';
		for (int i = k - 1; i >= 0; --i)
		{
			++c[i];
			if (c[i] == 10)
				c[i] = 0;
			else
				break;
		}
		for (int i = 0; i < n; ++i)
		{
			cout << (int)c[i%k];
		}
	}
	else
	{
		cout << n << '\n';
		for (int i = 0; i < n; ++i)
		{
			cout << (int)c[i%k];
		}
	}
	cout << '\n';
}