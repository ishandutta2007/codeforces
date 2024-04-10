/*#include <stdio.h>
#include <string.h>

char arr[1000001];

int main()
{
	int hsum=0,result=1,flag=0,H=0,Q=0,sum=0,len,i;
	scanf("%s",arr);
	len=strlen(arr);
	for(i=0;i<len;i++)
	{
		if(arr[i]=='H')
		{
			H++;
			hsum++;
	//		flag=0;
		}
		else
		{
			if(flag==1)
			{
				result=0;
				break;
			}
			Q++;
//			flag=1;
			if(hsum%2==1)
			{
				result=0;
				break;
			}
		}
	}
	if(result==1)
		printf("Yes");
	else
		printf("No");
	return 0;
}*/

#include <stdio.h>
#include <string.h>

int main()
{
	int num,len,i,j;
	char arr[51];
	scanf("%s",arr);
	scanf("%d",&num);
	len=strlen(arr);
	for(i=0;i<len;i++)
	{
		if(arr[i]<97)
			arr[i]+=32;
	}
	for(i=0;i<len;i++)
	{
		int c=arr[i];
		if(c<num+97)
			arr[i]-=32;
	}
	printf("%s",arr);
	return 0;
}