#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, t;
int s[101], d[101];
int main()
{
	scanf("%d%d", &n, &t);
	int result = -1;
	int minNum = 987654321;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &s[i], &d[i]);
		if (t > s[i])
		{
			if ((t - s[i]) % d[i] == 0)
			{
				s[i] += (t - s[i]);
			}
			else
			{
				s[i] += ((t - s[i]) / d[i] + 1) * d[i];
			}
		}

		//cout << s[i] << endl;
		
		if (minNum > s[i])
		{
			minNum = s[i];
			result = i + 1;
		}
	}

	printf("%d", result);
}