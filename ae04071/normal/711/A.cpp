#include <cstdio>

char str[1000][10];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
	}

	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (str[i][0] == str[i][1] && str[i][0] == 'O')
		{
			str[i][0] = str[i][1] = '+';
			flag = true;
			break;
		}
		if (str[i][3] == str[i][4] && str[i][3] == 'O')
		{
			str[i][3] = str[i][4] = '+';
			flag = true;
			break;
		}
	}

	if (flag)
	{
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%s\n", str[i]);
	}
	else
		printf("NO\n");

	return 0;
}