#include <cstdio>
#include <cstring>

char str[110];
int main()
{
	int len;
	scanf("%s", str);
	len = strlen(str);

	int max = 0, prev = -1;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y')
		{
			int l = i - prev;
			if (max < l) max = l;
			prev = i;
		}
	}
	if (len - prev > max) max = len - prev;

	printf("%d", max);

	return 0;
}