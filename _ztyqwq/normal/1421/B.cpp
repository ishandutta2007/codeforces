#include <bits/stdc++.h>
using namespace std;
string s[201];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			cin >> s[i];
		if(s[0][1] == s[1][0])
		{
			printf("%d\n", (s[0][1] == s[n - 1][n - 2]) + (s[0][1] == s[n - 2][n - 1]));
			if(s[n - 1][n - 2] == s[0][1])
				printf("%d %d\n", n, n - 1);
			if(s[n - 2][n - 1] == s[0][1])
				printf("%d %d\n", n - 1, n);
		}
		else if(s[n - 1][n - 2] == s[n - 2][n - 1])
		{
			printf("%d\n", (s[n - 1][n - 2] == s[0][1]) + (s[n - 1][n - 2] == s[1][0]));
			if (s[n - 1][n - 2] == s[0][1])
				printf("%d %d\n", 1, 2);
			if (s[n - 2][n - 1] == s[1][0])
				printf("%d %d\n", 2, 1);
		}
		else
		{
			printf("2\n");
			printf("1 2\n");
			if(s[n - 1][n - 2] == s[1][0])
				printf("%d %d\n", n, n - 1);
			if(s[n - 2][n - 1] == s[1][0])
				printf("%d %d\n", n - 1, n);
		}
	}
	return 0;
}