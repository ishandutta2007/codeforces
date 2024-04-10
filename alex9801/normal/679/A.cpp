#include <stdio.h>
#include <string.h>
#include <algorithm>

int pri[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

char tmp[100];

int main()
{
	int c = 0, i;
	for(i = 0; i<16; i++)
	{
		printf("%d\n", pri[i]);
		fflush(stdout);

		scanf("%s", tmp);
		if(tmp[0]=='y')
			c++;
		if(c==2)
		{
			printf("composite\n");
			fflush(stdout);
			return 0;
		}
	}

	for(i = 0; i<4; i++)
	{
		printf("%d\n", pri[i]*pri[i]);
		fflush(stdout);

		scanf("%s", tmp);
		if(tmp[0]=='y')
		{
			printf("composite\n");
			fflush(stdout);
			return 0;
		}
	}

	printf("prime\n");
	fflush(stdout);
	return 0;
}