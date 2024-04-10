#include <cstdio>
#include <cstring>

int main()
{
	char tmp[256];
	gets(tmp);
	int len = strlen(tmp);
	bool good = true;
	for (int i = 0; i < len; )
	{
		if (tmp[i] == '1')
		{
			i++;
			if (i < len && tmp[i] == '4')
			{
				i++;
				if (i < len && tmp[i] == '4')
				{
					i++;
				}
			}
		}
		else
		{
			good = false;
			break;
		}
	}
	if (good)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}