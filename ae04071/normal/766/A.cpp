#include <stdio.h>
#include <string.h>

char str[2][100100];
int main()
{
	scanf("%s",str[0]);
	scanf("%s",str[1]);

	int l1=strlen(str[0]);
	int l2=strlen(str[1]);
	if(l1==l2) {
		int i=0;
		for(i=0;i<l1;i++) {
			if(str[0][i]!=str[1][i])break;
		}
		if(i==l1)
			printf("-1\n");
		else
			printf("%d\n",l1);
	}
	else if(l1>l2)
		printf("%d\n",l1);
	else
		printf("%d\n",l2);
	return 0;
}