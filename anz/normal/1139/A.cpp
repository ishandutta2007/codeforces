#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	long long n;  string s;
	cin >> n >> s;

	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		if ((s[i] - '0') % 2 == 0)
		{
			result += (long long)i + 1;
		}
	}

	cout << result;
}