#include<bits/stdc++.h>

const int N = 105;

int n;
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str);
		int s[2] = {0};
		n = strlen(str);
		for (int i = 0; i < n; i++)
			s[str[i] - '0']++;
		if (s[0] == n || s[1] == n)
		{
			for (int i = 0; i < n; i++) putchar(str[i]);
			puts("");
		}
		else
		{
			for (int i = 0; i < n; i++)
				printf("01");
			puts("");
		}
	}
	return 0;
}