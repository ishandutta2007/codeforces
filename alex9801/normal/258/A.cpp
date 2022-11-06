#include <stdio.h>

char arr[100001];

int main()
{
	bool u=0;
	int i;
	scanf("%s",arr);
	for(i=0;arr[i];i++)
	{
		if(arr[i]=='0'||!arr[i+1])
		{
			arr[i]='X';
			break;
		}
	}
	for(i=0;arr[i];i++)
	{
		if(arr[i]=='1')
		{
			u=1;
			printf("1");
		}
		if(u&&arr[i]=='0')
			printf("0");
	}
	return 0;
}